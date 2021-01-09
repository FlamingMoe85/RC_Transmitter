/*
 * Time_Integrator_Leaf_Ui.cpp
 *
 *  Created on: 01.01.2021
 *      Author: Justus
 */

#include "Time_Integrator_Leaf_Ui.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;

#define CAN_X_POS	0
#define CAN_X_WIDTH	200
#define CAN_Y_WIDTH	30
#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT	ClrOrange
#define TEXT_COLR		ClrWhite

static char maxArr[] = "       ";
static char minArr[] = "       ";
static char rateArr[] = "       ";
static char defArr[] = "       ";
static char resSelArr[] = "       ";

Canvas(intergName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Integrator", 0, 0);
Canvas(intergCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(intgrMax,0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 45, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Maximum", 0, 0);
Canvas(intgrMaxVal,0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 75, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "100%", 0, 0);

Canvas(intgrMin, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 160, 45, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Minimum", 0, 0);
Canvas(intgrMinVal, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 160, 75, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "-100%", 0, 0);

Canvas(intgrRate, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 110, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Rate", 0, 0);
Canvas(intgrRateVal, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 140, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "100%", 0, 0);

Canvas(intgrDef, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 160, 110, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Default", 0, 0);
Canvas(intgrDefVal, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 160, 140, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "100%", 0, 0);

Canvas(intgrRes, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 175, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Reset In", 0, 0);
Canvas(intgrResVal, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 205, 160, 30, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "0", 0, 0);

Time_Integrator_Leaf_Ui::Time_Integrator_Leaf_Ui() {
	// TODO Auto-generated constructor stub
	sel = 0;
	selOld = sel;
}

Time_Integrator_Leaf_Ui::~Time_Integrator_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}

void Time_Integrator_Leaf_Ui::SetIntegrator_Ref(Time_Integrator_Leaf* caller)
{
	myRef = caller;

	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&intergCov);
	WidgetPaint((tWidget *)&intergName);
	selOld = 1;
	sel = 0;
	MarkSelected();
	PaintVal();

	sel = 1;
	selOld = 1;
	MarkSelected();
	PaintVal();

	sel = 2;
	selOld = 2;
	MarkSelected();
	PaintVal();

	sel = 3;
	selOld = 3;
	MarkSelected();
	PaintVal();

	sel = 4;
	selOld = 4;
	MarkSelected();
	PaintVal();

	selOld = 0;
	sel = 0;
}

void Time_Integrator_Leaf_Ui::PaintVal()
{
	switch(sel)
	{
		case 0:
		{
			UtilClass::IntToPercStrng(&(maxArr[0]), myRef->GetMax(), UNSIGNED);
			CanvasTextSet(&intgrMaxVal, &(maxArr[0]));
			WidgetPaint((tWidget *)&intgrMaxVal);
			break;
		}
		case 1:
		{
			UtilClass::IntToPercStrng(&(minArr[0]), myRef->GetMin(), SIGNED);
			CanvasTextSet(&intgrMinVal, &(minArr[0]));
			WidgetPaint((tWidget *)&intgrMinVal);
			break;
		}
		case 2:
		{
			UtilClass::IntToPercStrng(&(rateArr[0]), myRef->GetRate(), UNSIGNED);
			CanvasTextSet(&intgrRateVal, &(rateArr[0]));
			WidgetPaint((tWidget *)&intgrRateVal);
			break;
		}
		case 3:
		{
			UtilClass::IntToPercStrng(&(defArr[0]), myRef->GetDef(), SIGNED);
			CanvasTextSet(&intgrDefVal, &(defArr[0]));
			WidgetPaint((tWidget *)&intgrDefVal);
			break;
		}
		case 4:
		{
			UtilClass::UnsgndIntToStrng(&(resSelArr[0]), myRef->GetResSel());
			CanvasTextSet(&intgrResVal, &(resSelArr[0]));
			WidgetPaint((tWidget *)&intgrResVal);
			break;
		}
	}
}

void Time_Integrator_Leaf_Ui::MarkSelected()
{
	switch(sel)
	{
		case 0:
		{
			CanvasFillColorSet(&intgrMax,SELECTED_PNT);
			WidgetPaint((tWidget *)&intgrMax);
			break;
		}
		case 1:
		{
			CanvasFillColorSet(&intgrMin,SELECTED_PNT);
			WidgetPaint((tWidget *)&intgrMin);
			break;
		}
		case 2:
		{
			CanvasFillColorSet(&intgrRate,SELECTED_PNT);
			WidgetPaint((tWidget *)&intgrRate);
			break;
		}
		case 3:
		{
			CanvasFillColorSet(&intgrDef,SELECTED_PNT);
			WidgetPaint((tWidget *)&intgrDef);
			break;
		}
		case 4:
		{
			CanvasFillColorSet(&intgrRes,SELECTED_PNT);
			WidgetPaint((tWidget *)&intgrRes);
			break;
		}
	}
	switch(selOld)
	{
		case 0:
		{
			CanvasFillColorSet(&intgrMax,UNSELCTED_PNT);
			WidgetPaint((tWidget *)&intgrMax);
			break;
		}
		case 1:
		{
			CanvasFillColorSet(&intgrMin,UNSELCTED_PNT);
			WidgetPaint((tWidget *)&intgrMin);
			break;
		}
		case 2:
		{
			CanvasFillColorSet(&intgrRate,UNSELCTED_PNT);
			WidgetPaint((tWidget *)&intgrRate);
			break;
		}
		case 3:
		{
			CanvasFillColorSet(&intgrDef,UNSELCTED_PNT);
			WidgetPaint((tWidget *)&intgrDef);
			break;
		}
		case 4:
		{
			CanvasFillColorSet(&intgrRes,UNSELCTED_PNT);
			WidgetPaint((tWidget *)&intgrRes);
			break;
		}
	}
	selOld = sel;
}

void Time_Integrator_Leaf_Ui::PaintSelected()
{

}

uint16_t Time_Integrator_Leaf_Ui::GetItmSel()
{
	return 0;
}

uint16_t Time_Integrator_Leaf_Ui::GetCanSel()
{
	return 0;
}

void Time_Integrator_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	(**curNode).Esc(curNode);
	(**curNode).Show(UiVis);
}

void Time_Integrator_Leaf_Ui::Up(int16_t val)
{
	switch(sel)
	{
		case 0:
		{
			myRef->AddSngMax(val);
			break;
		}
		case 1:
		{
			myRef->AddSngMin(val);
			break;
		}
		case 2:
		{
			myRef->AddSngRate(val);
			break;
		}
		case 3:
		{
			myRef->AddSngDef(val);
			break;
		}
		case 4:
		{
			myRef->AddSngResSel(val);
			break;
		}
	}
	PaintVal();
}

void Time_Integrator_Leaf_Ui::Down(int16_t val)
{
	Up(val);
	PaintVal();
}

void Time_Integrator_Leaf_Ui::Up()
{
	Up(1);
	PaintVal();
}

void Time_Integrator_Leaf_Ui::Down()
{
	Up(-1);
	PaintVal();
}

void Time_Integrator_Leaf_Ui::Right()
{

	sel++;
	if(sel > 4) sel = 0;
	MarkSelected();
}

void Time_Integrator_Leaf_Ui::Left()
{

	if(sel == 0) sel = 4;
	else sel--;
	MarkSelected();
}

void Time_Integrator_Leaf_Ui::Grab()
{
	myRef->ResetIval();
}

void Time_Integrator_Leaf_Ui::QuadEncNotify(int16_t val)
{
	if(val > 0)Up(val);
	else if(val < 0) Down(val);
}
