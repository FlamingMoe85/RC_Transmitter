/*
 * TimeCalc_Ramp_Leaf_UI.cpp
 *
 *  Created on: 15.11.2019
 *      Author: Justus
 */

#include "TimeCalc_Ramp_Leaf_UI.h"

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
#define SELECTED_PNT		ClrOrange
#define GRABED_PNT		ClrRed
#define TEXT_COLR		ClrWhite

Canvas(nameBannerRamp, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Ramp", 0, 0);

Canvas(calcRampCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(calcRampCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(valueAboveRisCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 50, 100, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
Canvas(valueAboveFalCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 80, 100, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
Canvas(nullPointCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 120, 100, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
Canvas(valueBelowRisCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 160, 100, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
Canvas(valueBelowFalCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 190, 100, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);


static char valArrAboRis[] = "        ";
static char valArrAboFal[] = "        ";
static char valArrBelRis[] = "        ";
static char valArrBelFal[] = "        ";
static char valArrNulPoi[] = "        ";

static uint16_t selLookUp[] = {0, 1, 4, 2, 3, 5};

TimeCalc_Ramp_Leaf_UI::TimeCalc_Ramp_Leaf_UI() {
	// TODO Auto-generated constructor stub
	sel = 0;
}

TimeCalc_Ramp_Leaf_UI::~TimeCalc_Ramp_Leaf_UI() {
	// TODO Auto-generated destructor stub

}

void TimeCalc_Ramp_Leaf_UI::SetTimeCalc_Ramp_Ref(TimeCalc_Ramp_Leaf* ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&calcRampCov_1);
		WidgetPaint((tWidget *)&calcRampCov_2);
		WidgetPaint((tWidget *)&nameBannerRamp);
		MarkSelected();
		PaintVal();
}

void TimeCalc_Ramp_Leaf_UI::PaintVal()
{
	UtilClass::IntToPercStrng(&(valArrAboRis[0]), myRef->GetPercPerSec(ABOVE_RISING), UNSIGNED);
	CanvasTextSet(&valueAboveRisCan, &(valArrAboRis[0]));
	WidgetPaint((tWidget *)&valueAboveRisCan);

	UtilClass::IntToPercStrng(&(valArrAboFal[0]), myRef->GetPercPerSec(ABOVE_FALLING), UNSIGNED);
	CanvasTextSet(&valueAboveFalCan, &(valArrAboFal[0]));
	WidgetPaint((tWidget *)&valueAboveFalCan);

	UtilClass::IntToPercStrng(&(valArrBelRis[0]), myRef->GetPercPerSec(BELOW_RISING), UNSIGNED);
	CanvasTextSet(&valueBelowRisCan, &(valArrBelRis[0]));
	WidgetPaint((tWidget *)&valueBelowRisCan);

	UtilClass::IntToPercStrng(&(valArrBelFal[0]), myRef->GetPercPerSec(BELOW_FALLING), UNSIGNED);
	CanvasTextSet(&valueBelowFalCan, &(valArrBelFal[0]));
	WidgetPaint((tWidget *)&valueBelowFalCan);

	UtilClass::IntToPercStrng(&(valArrNulPoi[0]), myRef->GetNullPoint(), SIGNED);
	CanvasTextSet(&nullPointCan, &(valArrNulPoi[0]));
	WidgetPaint((tWidget *)&nullPointCan);

}

void TimeCalc_Ramp_Leaf_UI::MarkSelected()
{
	/**/
	if(selLookUp[sel] == 0)
	{
		CanvasFillColorSet(&valueAboveRisCan,SELECTED_PNT);
		CanvasFillColorSet(&valueAboveFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&nullPointCan,UNSELCTED_PNT);
	}
	else if(selLookUp[sel] == 1)
	{
		CanvasFillColorSet(&valueAboveRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueAboveFalCan,SELECTED_PNT);
		CanvasFillColorSet(&valueBelowRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&nullPointCan,UNSELCTED_PNT);
	}
	else if(selLookUp[sel] == 2)
	{
		CanvasFillColorSet(&valueAboveRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueAboveFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowRisCan,SELECTED_PNT);
		CanvasFillColorSet(&valueBelowFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&nullPointCan,UNSELCTED_PNT);
	}
	else if(selLookUp[sel] == 3)
	{
		CanvasFillColorSet(&valueAboveRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueAboveFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowFalCan,SELECTED_PNT);
		CanvasFillColorSet(&nullPointCan,UNSELCTED_PNT);
	}
	else if(selLookUp[sel] == 4)
	{
		CanvasFillColorSet(&valueAboveRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueAboveFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowRisCan,UNSELCTED_PNT);
		CanvasFillColorSet(&valueBelowFalCan,UNSELCTED_PNT);
		CanvasFillColorSet(&nullPointCan,SELECTED_PNT);
	}

	else if(selLookUp[sel] == 5)
	{
		CanvasFillColorSet(&valueAboveRisCan,SELECTED_PNT);
		CanvasFillColorSet(&valueAboveFalCan,SELECTED_PNT);
		CanvasFillColorSet(&valueBelowRisCan,SELECTED_PNT);
		CanvasFillColorSet(&valueBelowFalCan,SELECTED_PNT);
		CanvasFillColorSet(&nullPointCan,UNSELCTED_PNT);
	}
}

void TimeCalc_Ramp_Leaf_UI::PaintSelected()
{
	WidgetPaint((tWidget *)&valueAboveRisCan);
	WidgetPaint((tWidget *)&valueAboveFalCan);
	WidgetPaint((tWidget *)&valueBelowRisCan);
	WidgetPaint((tWidget *)&valueBelowFalCan);
	WidgetPaint((tWidget *)&nullPointCan);
}

uint16_t TimeCalc_Ramp_Leaf_UI::GetItmSel()
{
	return 0;
}

uint16_t TimeCalc_Ramp_Leaf_UI::GetCanSel()
{
	return 0;
}

void TimeCalc_Ramp_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&calcRampCov_1);
	WidgetPaint((tWidget *)&calcRampCov_2);
	(**curNode).Show(UiVis);
}

void TimeCalc_Ramp_Leaf_UI::Up(int16_t val)
{
	if(selLookUp[sel] < 4)
	{
		myRef->SetPercPerSec(selLookUp[sel], myRef->GetPercPerSec(selLookUp[sel]) + val);
	}
	if(selLookUp[sel] == 4)
	{
		myRef->SetNullPoint(myRef->GetNullPoint()+val);
	}
	if(selLookUp[sel] == 5)
	{
		for(uint16_t i=0; i<5; i++)
		{
			myRef->SetPercPerSec(selLookUp[i], myRef->GetPercPerSec(selLookUp[i]) + val);
		}
	}
	PaintVal();
}

void TimeCalc_Ramp_Leaf_UI::Down(int16_t val)
{
	if(selLookUp[sel] < 4)
	{
		uint16_t curVal = myRef->GetPercPerSec(selLookUp[sel]);
		if(curVal > val) curVal += val;
		else curVal = 0;
		myRef->SetPercPerSec(selLookUp[sel], curVal);
	}
	if(selLookUp[sel] == 4)
	{
		myRef->SetNullPoint(myRef->GetNullPoint()+val);
	}
	if(selLookUp[sel] == 5)
	{

		uint16_t curVal = myRef->GetPercPerSec(selLookUp[0]);
		if(curVal > val) curVal += val;
		else curVal = 0;
		for(uint16_t i=0; i<5; i++)
		{
			myRef->SetPercPerSec(selLookUp[i], curVal);
		}
	}
	PaintVal();
}

void TimeCalc_Ramp_Leaf_UI::Up()
{
	sel++;
	if(sel > 5) sel = 0;
	MarkSelected();
	PaintSelected();
}

void TimeCalc_Ramp_Leaf_UI::Down()
{
	if(sel == 0) sel = 4;
	else sel--;
	MarkSelected();
	PaintSelected();
}

void TimeCalc_Ramp_Leaf_UI::Right()
{
	Up(1);
}

void TimeCalc_Ramp_Leaf_UI::Left()
{
	Down(-1);
}

void TimeCalc_Ramp_Leaf_UI::Grab()
{
	uint16_t smallest = 65535;
	sel = 5;
	for(uint16_t i=0; i<5; i++)
	{
		if(i == 2)i++;
		if(smallest > myRef->GetPercPerSec(selLookUp[i])) smallest = myRef->GetPercPerSec(selLookUp[i]);
	}

	for(uint16_t i=0; i<5; i++)
	{
		if(i == 2)i++;
		myRef->SetPercPerSec(selLookUp[i], smallest);
	}

	MarkSelected();
	PaintVal();
}

void TimeCalc_Ramp_Leaf_UI::QuadEncNotify(int16_t val)
{
	if(val > 0)Up(val);
	else if(val < 0) Down(val);
}
