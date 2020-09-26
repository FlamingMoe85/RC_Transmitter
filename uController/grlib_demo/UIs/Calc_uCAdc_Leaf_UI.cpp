/*
 * Calc_uCAdc_Leaf_UI.cpp
 *
 *  Created on: 15.05.2019
 *      Author: Justus
 */

#include "Calc_uCAdc_Leaf_UI.h"
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
static char valArr[] = "        ";
Calc_Addition_Leaf** myRef_C;

Canvas(calcuCAdcName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Add Module", 0, 0);
Canvas(calcuCAdcCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(calcuCAdcCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(calcuCAdcValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 110, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
Canvas(adcValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 140, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
Calc_uCAdc_Leaf_UI::Calc_uCAdc_Leaf_UI() {
	// TODO Auto-generated constructor stub

}

Calc_uCAdc_Leaf_UI::~Calc_uCAdc_Leaf_UI() {
	// TODO Auto-generated destructor stub
}

void Calc_uCAdc_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&calcuCAdcCov_1);
	WidgetPaint((tWidget *)&calcuCAdcCov_2);
	(**curNode).Show(UiVis);
}

void Calc_uCAdc_Leaf_UI::SetuCAdc_Ref(Calc_uCAdc_Leaf *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());

	WidgetPaint((tWidget *)&calcuCAdcCov_1);
	WidgetPaint((tWidget *)&calcuCAdcCov_2);
	WidgetPaint((tWidget *)&calcuCAdcName);
	UtilClass::SgndIntToStrng(&(nameArr[0]), myRef->GetChnlVal());
	CanvasTextSet(&calcuCAdcValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcuCAdcValue);
	Paint();
}

void Calc_uCAdc_Leaf_UI::Up()
{
	myRef->IncChnlVal();
	UtilClass::SgndIntToStrng(&(nameArr[0]), myRef->GetChnlVal());
	CanvasTextSet(&calcuCAdcValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcuCAdcValue);
}

void Calc_uCAdc_Leaf_UI::Down()
{
	myRef->DecChnlVal();
	UtilClass::SgndIntToStrng(&(nameArr[0]), myRef->GetChnlVal());
		CanvasTextSet(&calcuCAdcValue, &(nameArr[0]));
		WidgetPaint((tWidget *)&calcuCAdcValue);
}

void Calc_uCAdc_Leaf_UI::RepaintVal()
{
	//UtilClass::SgndIntToStrng(&(valArr[0]), myRef->GetAdc());
	UtilClass::IntToPercStrng(&(valArr[0]), (int)myRef->GetAdc(), true, 1, '.', '%');
			CanvasTextSet(&adcValue, &(valArr[0]));
			WidgetPaint((tWidget *)&adcValue);
}

void Calc_uCAdc_Leaf_UI::Paint()
{
}

uint16_t Calc_uCAdc_Leaf_UI::GetItmSel()
{
	return 0;
}

uint16_t Calc_uCAdc_Leaf_UI::GetCanSel()
{
	return 0;
}
