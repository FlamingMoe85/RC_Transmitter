/*
 * StrctChnlNodeUI.cpp
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#include "StrctMultiSwNodeUI.h"
#include "StrctChnlNodeUI.h"
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

#define UNSELCTED_PNT 	ClrSaddleBrown
#define SELECTED_PNT		ClrOrange
#define GRABED_PNT		ClrRed
#define TEXT_COLR		ClrWhite

Strct_Chnl_Node* myRef_C;

void AddSltPrs(tWidget *psWidget);

tCanvasWidget myCanvacsesChnl[] =
{
    CanvasStruct(0, 0,0,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Chnl", 0, 0)
};

tPushButtonWidget sltBtns[] =
{
		RectangularButtonStruct(0, 0, 0,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 140, 100, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 SELECTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, " Add Slot ", 0, 0, 0, 0, AddSltPrs)
};
Canvas(sltBtnsCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Strct_Chnl_Node_UI::Strct_Chnl_Node_UI() {
	// TODO Auto-generated constructor stub
	//myRef_C = &myRef;
}

Strct_Chnl_Node_UI::~Strct_Chnl_Node_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_Chnl_Node_UI::SetStrctChnl_Ref(Strct_Chnl_Node *ref)
{
	myRef = ref;
	myRef_C = ref;
	WidgetAdd(WIDGET_ROOT, (tWidget *)sltBtns);
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	ItemSel(GetItmSel(), 1);
	this->SetName(myRef->GetNameArr());
	WidgetPaint((tWidget *)&sltBtns);
	Paint();
}

void Strct_Chnl_Node_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Enter(curNode, this->GetItmSel());
	WidgetRemove((tWidget *)&sltBtns);
	WidgetPaint((tWidget *)&sltBtnsCov);
	(**curNode).Show(UiVis);
}

void Strct_Chnl_Node_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetRemove((tWidget *)&sltBtns);
	WidgetPaint((tWidget *)&sltBtnsCov);
	(**curNode).Show(UiVis);
}

void Strct_Chnl_Node_UI::RemFcnBtns()
{
	WidgetRemove((tWidget *)&sltBtns);
}

void Strct_Chnl_Node_UI::ConFcnBtns()
{
	WidgetPaint((tWidget *)sltBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)sltBtns);
}

void AddSltPrs(tWidget *psWidget)
{
	myRef_C->AddSltAtEnd();
}
