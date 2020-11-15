/*
 * Z_SystemConfig_Leaf_UI.cpp
 *
 *  Created on: 11.11.2020
 *      Author: Justus
 */

#include "Z_SystemConfig_Leaf_UI.h"

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

Canvas(sysConfName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Sys Config", 0, 0);
Canvas(sysConfCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Z_SystemConfig_Leaf_UI::Z_SystemConfig_Leaf_UI() {
	// TODO Auto-generated constructor stub

}

Z_SystemConfig_Leaf_UI::~Z_SystemConfig_Leaf_UI() {
	// TODO Auto-generated destructor stub
}

void Z_SystemConfig_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&sysConfCov);
	(**curNode).Show(UiVis);
}

void Z_SystemConfig_Leaf_UI::SetSysConfig_Ref(Z_SystemConfig_Leaf* ref)
{
	myRef = ref;
	WidgetPaint((tWidget *)&sysConfCov);
	WidgetPaint((tWidget *)&sysConfName);
}
