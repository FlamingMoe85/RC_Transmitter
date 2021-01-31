/*
 * Wizard_TwoChnlModl_Leaf_Ui.cpp
 *
 *  Created on: 28.01.2021
 *      Author: Justus
 */

#include "Wizard_TwoChnlModl_Leaf_Ui.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;

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

Canvas(intTwoChModName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "2 Chnl Modl Wiz", 0, 0);
Canvas(intTwoChModCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

char values[4][9];
/*
char v1[6];
char v2[6];
char v3[6];
char v4[6];
*/
tCanvasWidget wiz2ChnlCan[] =
{
    CanvasStruct(0, 0,wiz2ChnlCan+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(0*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Gas Sel", 0, 0),

    CanvasStruct(wiz2ChnlCan,  0,wiz2ChnlCan + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45+(0*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

    CanvasStruct(wiz2ChnlCan, 0,wiz2ChnlCan + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(1*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Gas Scale", 0, 0),

	CanvasStruct(wiz2ChnlCan, 0,wiz2ChnlCan + 4,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45+(1*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

			    CanvasStruct(wiz2ChnlCan, 0,wiz2ChnlCan+5,
			                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(2*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
							 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Steer Sel", 0, 0),

			    CanvasStruct(wiz2ChnlCan,  0,wiz2ChnlCan + 6,
			                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45+(2*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
							 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

			    CanvasStruct(wiz2ChnlCan, 0,wiz2ChnlCan + 7,
			                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(3*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
							 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Steer Scale", 0, 0),

				CanvasStruct(wiz2ChnlCan, 0,0,
							&g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45+(3*CAN_Y_WIDTH), 100, CAN_Y_WIDTH,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),
};

Wizard_TwoChnlModl_Leaf_Ui::Wizard_TwoChnlModl_Leaf_Ui() {
	// TODO Auto-generated constructor stub
	curSel = 0;
}

Wizard_TwoChnlModl_Leaf_Ui::~Wizard_TwoChnlModl_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}


void Wizard_TwoChnlModl_Leaf_Ui::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myRef->Generate();
}

void Wizard_TwoChnlModl_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&intTwoChModCov);
	(**curNode).Show(UiVis);
}

void Wizard_TwoChnlModl_Leaf_Ui::SetTwoChnlModl_Ref(Wizard_TwoChnlModl_Leaf* ref)
{
	myRef = ref;
	Sign(this);
	this->SetActUi(this->GetStackPos());
	WidgetPaint((tWidget *)&intTwoChModCov);
	WidgetPaint((tWidget *)&intTwoChModName);
	MarkSelected();
	FillVal(GAS);
	FillVal(STEER);
	FillVal(GAS_SCL);
	FillVal(STEER_SCL);
	PaintAll();
}

void Wizard_TwoChnlModl_Leaf_Ui::PaintAll()
{
	WidgetPaint((tWidget *)&(wiz2ChnlCan[0]));
}

void Wizard_TwoChnlModl_Leaf_Ui::MarkSelected()
{
	for(uint16_t i=0; i<4; i++)
	{
		if(curSel == i)
		{
			CanvasFillColorSet(&(wiz2ChnlCan[i*2]),SELECTED_PNT);
		}
		else
		{
			CanvasFillColorSet(&(wiz2ChnlCan[i*2]),UNSELCTED_PNT);
		}
	}
}

void Wizard_TwoChnlModl_Leaf_Ui::RepaintSelVal()
{
	//WidgetPaint((tWidget *)&(wiz2ChnlCan[(curSel*2)+1]));
	PaintAll();
}

void Wizard_TwoChnlModl_Leaf_Ui::FillVal(uint16_t sel)
{
/**/
	if((sel == GAS) || (sel == STEER))
	{
		UtilClass::UnsgndIntToStrng(&(values[sel][0]), myRef->GetSel(sel));
	}
	else
	{
		UtilClass::IntToPercStrng(&(values[sel][0]), myRef->GetSel(sel), true);
	}
	CanvasTextSet(&(wiz2ChnlCan[(sel*2)+1]), &(values[sel][0]));

/*
	if(sel == GAS)
	{
		UtilClass::UnsgndIntToStrng(&(v1[0]), myRef->GetSel(sel));
		CanvasTextSet(&(wiz2ChnlCan[(sel*2)+1]), &(values[sel][0]));
	}
	*/
}

void Wizard_TwoChnlModl_Leaf_Ui::Up()
{
	if(curSel < 3)curSel++;
	else curSel = 0;
	MarkSelected();
	PaintAll();
}

void Wizard_TwoChnlModl_Leaf_Ui::Down()
{
	if(curSel > 0)curSel--;
	else curSel = 3;
	MarkSelected();
	PaintAll();
}



void Wizard_TwoChnlModl_Leaf_Ui::Right()
{
	Right(1);
}

void Wizard_TwoChnlModl_Leaf_Ui::Left()
{
	Left(-1);
}

void Wizard_TwoChnlModl_Leaf_Ui::Left(int16_t val)
{
	myRef->AddValtoSel(curSel, val);
	FillVal(curSel);
	RepaintSelVal();
}

void Wizard_TwoChnlModl_Leaf_Ui::Right(int16_t val)
{
	myRef->AddValtoSel(curSel, val);
	FillVal(curSel);
	RepaintSelVal();
}

void Wizard_TwoChnlModl_Leaf_Ui::QuadEncNotify(int16_t val)
{
	if(val > 0)Right(val);
	else if(val < 0)Left(val);
}
