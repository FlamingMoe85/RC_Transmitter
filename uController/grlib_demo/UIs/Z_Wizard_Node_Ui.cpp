/*
 * Z_Wizard_Node_Ui.cpp
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#include "Z_Wizard_Node_Ui.h"

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

Canvas(wizardConfCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Z_Wizard_Node_Ui::Z_Wizard_Node_Ui() {
	// TODO Auto-generated constructor stub

}

Z_Wizard_Node_Ui::~Z_Wizard_Node_Ui() {
	// TODO Auto-generated destructor stub
}

void Z_Wizard_Node_Ui::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Enter(curNode, this->GetItmSel());
	(**curNode).Show(UiVis);
}

void Z_Wizard_Node_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&wizardConfCov);
	(**curNode).Show(UiVis);
}

void Z_Wizard_Node_Ui::SetWizard_Ref(Z_Wizard_Node* ref)
{

	myRef = ref;
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	ItemSel(GetItmSel(), 1);
	this->SetName(myRef->GetNameArr());
	Paint();
}
