/*
 * Wizard_IntTrim.cpp
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#include "Wizard_IntTrim_Ui.h"

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

Canvas(intTrimWizName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Int Trim Wiz", 0, 0);
Canvas(intTrimWizCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);


Wizard_IntTrim_Ui::Wizard_IntTrim_Ui() {
	// TODO Auto-generated constructor stub

}

Wizard_IntTrim_Ui::~Wizard_IntTrim_Ui() {
	// TODO Auto-generated destructor stub
}

void Wizard_IntTrim_Ui::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myRef->Generate();
}

void Wizard_IntTrim_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&intTrimWizCov);
	(**curNode).Show(UiVis);
}

void Wizard_IntTrim_Ui::SetIntTrimWiz_Ref(Wizard_InternTrim* ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	WidgetPaint((tWidget *)&intTrimWizCov);
	WidgetPaint((tWidget *)&intTrimWizName);
}
