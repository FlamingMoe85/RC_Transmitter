/*
 * CalcMultiplicationLeafUI.cpp
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#include "CalcMultiplicationLeafUI.h"

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
#define TEXT_COLR		ClrWhite

static char nameArr[] = "        ";

Canvas(calcMulName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Scale Module", 0, 0);
Canvas(calcMulCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(calcMulCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(calcMulValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 110, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);


Calc_Multiplication_Leaf_UI::Calc_Multiplication_Leaf_UI() {
	// TODO Auto-generated constructor stub

}

Calc_Multiplication_Leaf_UI::~Calc_Multiplication_Leaf_UI() {
	// TODO Auto-generated destructor stub
}

void Calc_Multiplication_Leaf_UI::SetCalcLeaf_Mult_Ref(Calc_Multiplication_Leaf *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&calcMulCov_1);
	WidgetPaint((tWidget *)&calcMulCov_2);
	WidgetPaint((tWidget *)&calcMulName);
	UtilClass::IntToPercStrng(&(nameArr[0]), myRef->GetMulVal(), SIGNED);
	CanvasTextSet(&calcMulValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcMulValue);
	Paint();
}

void Calc_Multiplication_Leaf_UI::Paint()
{


}

uint16_t Calc_Multiplication_Leaf_UI::GetItmSel()
{
	return 0;
}

uint16_t Calc_Multiplication_Leaf_UI::GetCanSel()
{
	return 0;
}


void Calc_Multiplication_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&calcMulCov_1);
	WidgetPaint((tWidget *)&calcMulCov_2);
	(**curNode).Show(UiVis);
}

void Calc_Multiplication_Leaf_UI::Up()
{
	Up(1);
}

void Calc_Multiplication_Leaf_UI::Down()
{
	Down(-1);
}

void Calc_Multiplication_Leaf_UI::QuadEncNotify(int16_t val)
{
	Up(val);
}

void Calc_Multiplication_Leaf_UI::Up(int16_t val)
{
	myRef->SetMulVal(myRef->GetMulVal()+(val * VALUE_STEP_UINT));
	UtilClass::IntToPercStrng(&(nameArr[0]), myRef->GetMulVal(), SIGNED);
	CanvasTextSet(&calcMulValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcMulValue);
}

void Calc_Multiplication_Leaf_UI::Down(int16_t val)
{
	myRef->SetMulVal(myRef->GetMulVal()+(val * VALUE_STEP_UINT));
	UtilClass::IntToPercStrng(&(nameArr[0]), myRef->GetMulVal(), SIGNED);
	CanvasTextSet(&calcMulValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcMulValue);
}
