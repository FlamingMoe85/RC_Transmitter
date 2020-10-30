/*
 * Calc_DeadArea_Leaf_Ui.cpp
 *
 *  Created on: 16.10.2020
 *      Author: Justus
 */

#include "Calc_DeadArea_Leaf_Ui.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;
extern tCanvasWidget g_psPanels[];


#define CAN_X_POS	0
#define CAN_X_WIDTH	200
#define CAN_Y_WIDTH	30
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)
#define NXT_X_WIDTH	24
#define NXT_Y_WIDTH NXT_X_WIDTH
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)

#define UNSELECTED_PNT 	ClrBlue
#define SELECTED_PNT	ClrOrange
#define TEXT_COLR		ClrWhite

static char nullPointArr[6];
static char deadSpanArr[6];

Canvas(deadSpanCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(deadSpanName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 60, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELECTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Dead Span", 0, 0);
Canvas(spanNPCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 60, 115, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELECTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Nullpoint", 0, 0);
Canvas(spanNPValCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 60, 140, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELECTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0);

Canvas(nullSpanCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 160, 115, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELECTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Span", 0, 0);
Canvas(nullSpanValCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 160, 140, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELECTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0);

Clac_DeadArea_Leaf* myRef_C;

Calc_DeadArea_Leaf_Ui::Calc_DeadArea_Leaf_Ui() {
	// TODO Auto-generated constructor stub

}

Calc_DeadArea_Leaf_Ui::~Calc_DeadArea_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}


void Calc_DeadArea_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();

	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&deadSpanCov);
	(**curNode).Show(UiVis);
}

void Calc_DeadArea_Leaf_Ui::SetDeadSpan_Ref(Clac_DeadArea_Leaf *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&deadSpanCov);
	WidgetPaint((tWidget *)&deadSpanName);
	MarkSelected();
	RepaintNpVal();
	RepaintSpanVal();
}

void Calc_DeadArea_Leaf_Ui::MarkSelected()
{
	if(sel == NULLPOINT)
	{
		CanvasFillColorSet(&(spanNPCan),SELECTED_PNT);
		CanvasFillColorSet(&(nullSpanCan),UNSELECTED_PNT);
	}
	else
	{
		CanvasFillColorSet(&(spanNPCan),UNSELECTED_PNT);
		CanvasFillColorSet(&(nullSpanCan),SELECTED_PNT);
	}
	WidgetPaint((tWidget *)&spanNPCan);
	WidgetPaint((tWidget *)&nullSpanCan);
}

void Calc_DeadArea_Leaf_Ui::Up()
{
	Up(1);
}

void Calc_DeadArea_Leaf_Ui::Down()
{
	Down(-1);
}


void Calc_DeadArea_Leaf_Ui::Up(int16_t val)
{
	if(sel == NULLPOINT)
	{
		myRef->AddSngdToNullPoint((float)val);
		RepaintNpVal();
	}
	else
	{
		myRef->AddSngdToSpan((float)val);
		RepaintSpanVal();
	}
}

void Calc_DeadArea_Leaf_Ui::Down(int16_t val)
{
	if(sel == NULLPOINT)
	{
		myRef->AddSngdToNullPoint((float)val);
		RepaintNpVal();
	}
	else
	{
		myRef->AddSngdToSpan((float)val);
		RepaintSpanVal();
	}

}

void Calc_DeadArea_Leaf_Ui::Right()
{
	if(sel == NULLPOINT)sel = SPAN;
	else sel = NULLPOINT;
	MarkSelected();
}

void Calc_DeadArea_Leaf_Ui::Left()
{
	if(sel == NULLPOINT)sel = SPAN;
	else sel = NULLPOINT;
	MarkSelected();
}

void Calc_DeadArea_Leaf_Ui::QuadEncNotify(int16_t val)
{
	if(val > 0) Up(val);
	else Down(val);
}

void Calc_DeadArea_Leaf_Ui::Grab()
{

}

void Calc_DeadArea_Leaf_Ui::Paint()
{

}

void Calc_DeadArea_Leaf_Ui::RepaintNpVal()
{
	int16_t con;
	con = (int16_t)myRef->GetNullPoint();
	UtilClass::IntToPercStrng(&(nullPointArr[0]), con, SIGNED);
	CanvasTextSet(&spanNPValCan, &(nullPointArr[0]));
	WidgetPaint((tWidget *)&spanNPValCan);
}

void Calc_DeadArea_Leaf_Ui::RepaintSpanVal()
{
	int16_t con;
	con = (int16_t)myRef->GetSpan();
	UtilClass::IntToPercStrng(&(deadSpanArr[0]), con, UNSIGNED);
	CanvasTextSet(&nullSpanValCan, &(deadSpanArr[0]));
	WidgetPaint((tWidget *)&nullSpanValCan);
}

uint16_t Calc_DeadArea_Leaf_Ui::GetItmSel()
{
	return 0;
}

uint16_t Calc_DeadArea_Leaf_Ui::GetCanSel()
{
	return 0;
}
