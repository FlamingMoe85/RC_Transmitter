/*
 * CalcAdditionLeafUI.cpp
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#include "CalcAdditionLeafUI.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;
extern tCanvasWidget g_psPanels[];


#define CAN_X_POS	100
#define CAN_X_WIDTH	200
#define CAN_Y_WIDTH	30
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)
#define NXT_X_WIDTH	24
#define NXT_Y_WIDTH NXT_X_WIDTH
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT	ClrOrange
#define TEXT_COLR		ClrWhite
static char nameArr[] = "        ";
Calc_Addition_Leaf** myRef_C;

Canvas(calcAddName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Add Module", 0, 0);
Canvas(calcAddCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(calcAddCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(calcAddValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 110, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
					 /*
					 RectangularButtonStruct(myCanvacsesAdd, 0,0,
	                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(2*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 				 UNSELCTED_PNT,
									 SELECTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0, 0)
};*/



Calc_Addition_Leaf_UI::Calc_Addition_Leaf_UI() {
	// TODO Auto-generated constructor stub
	num = '0';
	myRef_C = &myRef;
	//WidgetAdd(WIDGET_ROOT, (tWidget *)myPushBtns);
}

Calc_Addition_Leaf_UI::~Calc_Addition_Leaf_UI() {
	// TODO Auto-generated destructor stub
}

void Calc_Addition_Leaf_UI::SetCalcLeaf_Add_Ref(Calc_Addition_Leaf *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());

	WidgetPaint((tWidget *)&calcAddCov_1);
	WidgetPaint((tWidget *)&calcAddCov_2);
	WidgetPaint((tWidget *)&calcAddName);
	UtilClass::IntToPercStrng(&(nameArr[0]), myRef->GetSgndAddVal(), SIGNED);
	CanvasTextSet(&calcAddValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcAddValue);
	Paint();
}

void Calc_Addition_Leaf_UI::Paint()
{
}

uint16_t Calc_Addition_Leaf_UI::GetItmSel()
{
	return 0;
}

uint16_t Calc_Addition_Leaf_UI::GetCanSel()
{
	return 0;
}



void Calc_Addition_Leaf_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ }
void Calc_Addition_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&calcAddCov_1);
	WidgetPaint((tWidget *)&calcAddCov_2);
	(**curNode).Show(UiVis);
}

void Calc_Addition_Leaf_UI::Up()
{
	myRef->AddSgndVal(+5);
	UtilClass::IntToPercStrng(&(nameArr[0]), myRef->GetSgndAddVal(), SIGNED);
	CanvasTextSet(&calcAddValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcAddValue);
}

void Calc_Addition_Leaf_UI::Down()
{
	myRef->AddSgndVal(-5);
	UtilClass::IntToPercStrng(&(nameArr[0]), myRef->GetSgndAddVal(), SIGNED);
		CanvasTextSet(&calcAddValue, &(nameArr[0]));
		WidgetPaint((tWidget *)&calcAddValue);
}
void Calc_Addition_Leaf_UI::Right(){ }
void Calc_Addition_Leaf_UI::Left(){ }
void Calc_Addition_Leaf_UI::Grab(){ }
