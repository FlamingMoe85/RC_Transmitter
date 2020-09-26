/*
 * StrctMultiSwNodeUI.cpp
 *
 *  Created on: 22.04.2019
 *      Author: Justus
 */

#include "StrctMultiSwNodeUI.h"
#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

#include "../../../share/Graph_App/Strct_PoolOwner_Node.h"
#include "../../../share/Graph_App/Strct_Junc_Node.h"

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

Strct_MultSw_Node* myRef_C;

void AddCompPrs(tWidget *psWidget);
extern void CompPoolPrs_MultSwNode(tWidget *psWidget);
extern void DelPrs(tWidget *psWidget);

void AddJuncPrs(tWidget *psWidget);
extern void DelJuncPrs(tWidget *psWidget);

tPushButtonWidget cmpBtns[] =
{
		RectangularButtonStruct(0, 0, cmpBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 140, 100, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 SELECTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, " New Compo ", 0, 0, 0, 0, AddCompPrs),

	RectangularButtonStruct(cmpBtns, 0, cmpBtns + 2,//myCanvacsesAdd+1,
							&g_sKentec320x240x16_SSD2119, 110, 140, 100, 50,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT,
							UNSELCTED_PNT,
							ClrGray, TEXT_COLR, &g_sFontCm22, " CompPool ", 0, 0, 0, 0, CompPoolPrs_MultSwNode),

	RectangularButtonStruct(cmpBtns+1, 0, cmpBtns + 3,//myCanvacsesAdd+1,
							&g_sKentec320x240x16_SSD2119, 220, 140, 100, 50,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT,
							UNSELCTED_PNT,
							ClrGray, TEXT_COLR, &g_sFontCm22, "DelComp", 0, 0, 0, 0, DelPrs),

	RectangularButtonStruct(cmpBtns + 2, 0, cmpBtns+4,//myCanvacsesAdd+1,
							&g_sKentec320x240x16_SSD2119, 0, 190, 100, 50,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT,
							SELECTED_PNT,
							ClrGray, TEXT_COLR, &g_sFontCm22, " New Junc ", 0, 0, 0, 0, AddJuncPrs),

	RectangularButtonStruct(cmpBtns+3, 0, 0,//myCanvacsesAdd+1,
							&g_sKentec320x240x16_SSD2119, 220, 190, 100, 50,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT,
							UNSELCTED_PNT,
							ClrGray, TEXT_COLR, &g_sFontCm22, "Rem Junc", 0, 0, 0, 0, DelJuncPrs),
};
Canvas(cmpBtnsCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

StrctMultiSwNodeUI::StrctMultiSwNodeUI() {
	// TODO Auto-generated constructor stub

}

StrctMultiSwNodeUI::~StrctMultiSwNodeUI() {
	// TODO Auto-generated destructor stub
}

void StrctMultiSwNodeUI::SetMultSw_Ref(Strct_MultSw_Node* ref)
{
	myRef = ref;
	myRef_C = ref;
	this->ConctNameBtn();
	WidgetAdd(WIDGET_ROOT, (tWidget *)cmpBtns);
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	ItemSel(GetItmSel(), 1);
	this->SetName(myRef->GetNameArr());
	WidgetPaint((tWidget *)&cmpBtns);
		Paint();
}



void StrctMultiSwNodeUI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Enter(curNode, this->GetItmSel());
	WidgetRemove((tWidget *)&cmpBtns);
	WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}

void StrctMultiSwNodeUI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetRemove((tWidget *)&cmpBtns);
	WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}

void StrctMultiSwNodeUI::SetCompPool(Strct_PoolOwner_Node* poolOwnRef)
{
	myPoolOwnerRef = poolOwnRef;
}

void StrctMultiSwNodeUI::EnterCompoPool(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myPoolOwnerRef->SetEntry(
			myRef);
	*curNode = (Graph_App_I*)myPoolOwnerRef;
		//(**curNode).Enter(curNode, this->GetItmSel());


		WidgetRemove((tWidget *)&cmpBtns);
		WidgetPaint((tWidget *)&cmpBtnsCov);
		(**curNode).Show(UiVis);
}

void AddCompPrs(tWidget *psWidget)
{
	myRef_C->AddCompAtEnd();
}

void AddJuncPrs(tWidget *psWidget)
{
	myRef_C->GetChildList()->AddEnd((Graph_App_I*)new Strct_Junc_Node());
	myRef_C->Show();
}

void StrctMultiSwNodeUI::RemFcnBtns()
{
	WidgetRemove((tWidget *)&cmpBtns);
}

void StrctMultiSwNodeUI::ConFcnBtns()
{
	WidgetPaint((tWidget *)cmpBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)cmpBtns);
}

void StrctMultiSwNodeUI::DelSelItm()
{
	myRef->GetChildList()->DelAtLoc(this->GetItmSel());
	myRef->Show();
}
