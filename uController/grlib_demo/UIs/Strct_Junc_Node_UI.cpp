/*
 * Strct_Junc_Node_UI.cpp
 *
 *  Created on: 18.09.2019
 *      Author: Justus
 */

#include "Strct_Junc_Node_UI.h"

#include "StrctMultiSwNodeUI.h"
#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

#include "../../../share/Graph_App/Strct_PoolOwner_Node.h"

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

Strct_Junc_Node* myRef_C;

void JuncAddCompPrs(tWidget *psWidget);
extern void CompPoolPrs_JuncNode(tWidget *psWidget);
extern void DelPrs(tWidget *psWidget);

tPushButtonWidget jncBtns[] =
{
		RectangularButtonStruct(0, 0, jncBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 140, 100, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 SELECTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, " New Compo ", 0, 0, 0, 0, JuncAddCompPrs),

						RectangularButtonStruct(jncBtns, 0, jncBtns + 2,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 110, 140, 100, 50,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, " CompPool ", 0, 0, 0, 0, CompPoolPrs_JuncNode),

										RectangularButtonStruct(jncBtns+1, 0, 0,//myCanvacsesAdd+1,
																&g_sKentec320x240x16_SSD2119, 220, 140, 100, 50,
																CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																UNSELCTED_PNT,
																UNSELCTED_PNT,
																ClrGray, TEXT_COLR, &g_sFontCm22, "DelComp", 0, 0, 0, 0, DelPrs)
};
Canvas(jncBtnsCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Strct_Junc_Node_UI::Strct_Junc_Node_UI() {
	// TODO Auto-generated constructor stub

}

Strct_Junc_Node_UI::~Strct_Junc_Node_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_Junc_Node_UI::SetJunc_Ref(Strct_Junc_Node* ref)
{
	myRef = ref;
	myRef_C = ref;
	this->ConctNameBtn();
	WidgetAdd(WIDGET_ROOT, (tWidget *)jncBtns);
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	ItemSel(GetItmSel(), 1);
	this->SetName(myRef->GetNameArr());
	WidgetPaint((tWidget *)&jncBtns);
		Paint();
}



void Strct_Junc_Node_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Enter(curNode, this->GetItmSel());
	WidgetRemove((tWidget *)&jncBtns);
	WidgetPaint((tWidget *)&jncBtnsCov);
	(**curNode).Show(UiVis);
}

void Strct_Junc_Node_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetRemove((tWidget *)&jncBtns);
	WidgetPaint((tWidget *)&jncBtnsCov);
	(**curNode).Show(UiVis);
}

void Strct_Junc_Node_UI::SetCompPool(Strct_PoolOwner_Node* poolOwnRef)
{
	myPoolOwnerRef = poolOwnRef;
}

void Strct_Junc_Node_UI::EnterCompoPool(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myPoolOwnerRef->SetEntry(
			myRef);
	*curNode = (Graph_App_I*)myPoolOwnerRef;
		//(**curNode).Enter(curNode, this->GetItmSel());


		WidgetRemove((tWidget *)&jncBtns);
		WidgetPaint((tWidget *)&jncBtnsCov);
		(**curNode).Show(UiVis);
}

void JuncAddCompPrs(tWidget *psWidget)
{
	myRef_C->AddCompAtEnd();
}

void Strct_Junc_Node_UI::RemFcnBtns()
{
	WidgetRemove((tWidget *)&jncBtns);
}

void Strct_Junc_Node_UI::ConFcnBtns()
{
	WidgetPaint((tWidget *)jncBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)jncBtns);
}

void Strct_Junc_Node_UI::DelSelItm()
{
	myRef->GetChildList()->DelAtLoc(this->GetItmSel());
	myRef->Show();
}
