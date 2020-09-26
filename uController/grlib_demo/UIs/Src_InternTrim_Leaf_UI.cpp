/*
 * Src_InternTrim_Leaf_UI.cpp
 *
 *  Created on: 08.09.2019
 *      Author: Justus
 */

#include "Src_InternTrim_Leaf_UI.h"
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
static char pairSelArr[] = "        ";
//Calc_Addition_Leaf** myRef_C;

Canvas(intTrimName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Trim", 0, 0);
Canvas(intTrimCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(intTrimCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(pairSelValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 110, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);
Canvas(intTrimValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 140, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);

Src_InternTrim_Leaf_UI::Src_InternTrim_Leaf_UI() {
	// TODO Auto-generated constructor stub

}

Src_InternTrim_Leaf_UI::~Src_InternTrim_Leaf_UI() {
	// TODO Auto-generated destructor stub
}

void Src_InternTrim_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&intTrimCov_1);
	WidgetPaint((tWidget *)&intTrimCov_2);
	(**curNode).Show(UiVis);
}

void Src_InternTrim_Leaf_UI::SetInternTrim_Ref(Src_InternTrim_Leaf *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());

	WidgetPaint((tWidget *)&intTrimCov_1);
	WidgetPaint((tWidget *)&intTrimCov_2);
	WidgetPaint((tWidget *)&intTrimName);
	UtilClass::SgndIntToStrng(&(nameArr[0]), myRef->GetTrimVal());
	CanvasTextSet(&intTrimValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&intTrimValue);
	RepaintVals();
	RepaintTrmSel();
	Paint();
}

void Src_InternTrim_Leaf_UI::RepaintVals()
{

	UtilClass::IntToPercStrng(&(nameArr[0]), myRef->GetTrimVal(), SIGNED);
		CanvasTextSet(&intTrimValue, &(nameArr[0]));
		WidgetPaint((tWidget *)&intTrimValue);
}

void Src_InternTrim_Leaf_UI::RepaintTrmSel()
{

	UtilClass::SgndIntToStrng(&(pairSelArr[0]), myRef->GetPairSel());
	CanvasTextSet(&pairSelValue, &(pairSelArr[0]));
	WidgetPaint((tWidget *)&pairSelValue);
}

void Src_InternTrim_Leaf_UI::Paint()
{
}

uint16_t Src_InternTrim_Leaf_UI::GetItmSel()
{
	return 0;
}

uint16_t Src_InternTrim_Leaf_UI::GetCanSel()
{
	return 0;
}

void Src_InternTrim_Leaf_UI::Up()
{
	myRef->IncPairSel();
	RepaintTrmSel();
}

void Src_InternTrim_Leaf_UI::Down()
{
	myRef->DecPairSel();
	RepaintTrmSel();
}

void Src_InternTrim_Leaf_UI::Right()
{
	myRef->IncTrim();
}

void Src_InternTrim_Leaf_UI::Left()
{
	myRef->DecTrim();
}
