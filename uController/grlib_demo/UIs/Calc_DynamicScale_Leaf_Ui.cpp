/*
 * Calc_DynamicScale_Leaf_Ui.cpp
 *
 *  Created on: 21.11.2020
 *      Author: Justus
 */

#include "Calc_DynamicScale_Leaf_Ui.h"

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


void CompPoolPrsDynScl(tWidget *psWidget);
void NewCompPrsDynScl(tWidget *psWidget);
void EnterTriggerPrsDynScl(tWidget *psWidget);

Canvas(dynSclName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Dyn Scale", 0, 0);
Canvas(dynSclCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

tPushButtonWidget dynSclBtns[] =
{

									 RectangularButtonStruct(0, 0, dynSclBtns+1,//myCanvacsesAdd+1,
									 					     &g_sKentec320x240x16_SSD2119, 0, 190, 100, 50,
									 						 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 						UNSELCTED_PNT,
									 						UNSELCTED_PNT,
									 						ClrGray, TEXT_COLR, &g_sFontCm22, "Comp Pool", 0, 0, 0, 0, CompPoolPrsDynScl),

									RectangularButtonStruct(dynSclBtns, 0, dynSclBtns+2,//myCanvacsesAdd+1,
															&g_sKentec320x240x16_SSD2119, 100, 190, 100, 50,
															CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
															UNSELCTED_PNT,
															UNSELCTED_PNT,
															ClrGray, TEXT_COLR, &g_sFontCm22, "New Compo", 0, 0, 0, 0, NewCompPrsDynScl),

									RectangularButtonStruct(dynSclBtns+1, 0, 0,//myCanvacsesAdd+1,
															&g_sKentec320x240x16_SSD2119, 200, 190, 100, 50,
															CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
															UNSELCTED_PNT,
															UNSELCTED_PNT,
															ClrGray, TEXT_COLR, &g_sFontCm22, "Trigger", 0, 0, 0, 0, EnterTriggerPrsDynScl)



};

Calc_DynamicScale_Leaf_Ui* instUiPtr;
Calc_DynamicScale_Leaf* cRef;

Calc_DynamicScale_Leaf_Ui::Calc_DynamicScale_Leaf_Ui() {
	// TODO Auto-generated constructor stub

}

Calc_DynamicScale_Leaf_Ui::~Calc_DynamicScale_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}

void Calc_DynamicScale_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	RemFcnBtns();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&dynSclCov);
	(**curNode).Show(UiVis);
}

void Calc_DynamicScale_Leaf_Ui::SetDynScale_Ref(Calc_DynamicScale_Leaf* ref)
{
	myRef = ref;
	cRef = ref;
	this->SetActUi(this->GetStackPos());
	WidgetPaint((tWidget *)&dynSclCov);
	WidgetPaint((tWidget *)&dynSclName);
	instUiPtr = this;
	ConFcnBtns();
}

void Calc_DynamicScale_Leaf_Ui::SetCompPool(Strct_PoolOwner_Node* poolOwnRef)
{
	myPoolOwnerRef = poolOwnRef;
}

void Calc_DynamicScale_Leaf_Ui::EnterCompoPool()//(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myPoolOwnerRef->SetEntry(myRef);
	(*(myRef->GetCurNodePtrLoc())) = (Graph_App_I*)myPoolOwnerRef;
	//currentNode = (Graph_App_I*)myPoolOwnerRef;

	RemFcnBtns();
	WidgetPaint((tWidget *)&dynSclCov);
	myPoolOwnerRef->Show();
}

void Calc_DynamicScale_Leaf_Ui::EnterTrigCompo()
{
	if(myRef->GetTrigCompo() != 0)
	{
		myRef->GetTrigCompo()->SetEntry(myRef);
		(*(myRef->GetCurNodePtrLoc())) = (Graph_App_I*)myRef->GetTrigCompo();
		//currentNode = (Graph_App_I*)myRef->GetTrigCompo();
		this->SetActUi(2);
		RemFcnBtns();
		WidgetPaint((tWidget *)&dynSclCov);

		myRef->GetTrigCompo()->Show(myRef->GetVisitor());
	}
}



void Calc_DynamicScale_Leaf_Ui::RemFcnBtns()
{
	WidgetRemove((tWidget *)&dynSclBtns);
}
void Calc_DynamicScale_Leaf_Ui::ConFcnBtns()
{
	WidgetPaint((tWidget *)dynSclBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)dynSclBtns);
}



void CompPoolPrsDynScl(tWidget *psWidget)
{
	instUiPtr->EnterCompoPool();
}

void NewCompPrsDynScl(tWidget *psWidget)
{
	cRef->NewTrigCompo();
}
void EnterTriggerPrsDynScl(tWidget *psWidget)
{
	instUiPtr->EnterTrigCompo();
}
