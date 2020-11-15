/*
 * Calc_Expo1_Leaf_Ui.cpp
 *
 *  Created on: 14.11.2020
 *      Author: Justus
 */

#include "Calc_Expo1_Leaf_Ui.h"

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


void CompPoolPrsExp1(tWidget *psWidget);
void NewCompPrsExp1(tWidget *psWidget);
void EnterTriggerPrsExp1(tWidget *psWidget);

Canvas(expo1Name, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Expo 1", 0, 0);
Canvas(expo1Cov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

tPushButtonWidget expo1Btns[] =
{

									 RectangularButtonStruct(0, 0, expo1Btns+1,//myCanvacsesAdd+1,
									 					     &g_sKentec320x240x16_SSD2119, 0, 190, 100, 50,
									 						 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 						UNSELCTED_PNT,
									 						UNSELCTED_PNT,
									 						ClrGray, TEXT_COLR, &g_sFontCm22, "Comp Pool", 0, 0, 0, 0, CompPoolPrsExp1),

									RectangularButtonStruct(expo1Btns, 0, expo1Btns+2,//myCanvacsesAdd+1,
															&g_sKentec320x240x16_SSD2119, 100, 190, 100, 50,
															CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
															UNSELCTED_PNT,
															UNSELCTED_PNT,
															ClrGray, TEXT_COLR, &g_sFontCm22, "New Compo", 0, 0, 0, 0, NewCompPrsExp1),

									RectangularButtonStruct(expo1Btns+1, 0, 0,//myCanvacsesAdd+1,
															&g_sKentec320x240x16_SSD2119, 200, 190, 100, 50,
															CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
															UNSELCTED_PNT,
															UNSELCTED_PNT,
															ClrGray, TEXT_COLR, &g_sFontCm22, "Trigger", 0, 0, 0, 0, EnterTriggerPrsExp1)



};

Calc_Expo1_Leaf_Ui* instUiPtr;
Calc_Expo1_Leaf* cRef;

Calc_Expo1_Leaf_Ui::Calc_Expo1_Leaf_Ui() {
	// TODO Auto-generated constructor stub

}

Calc_Expo1_Leaf_Ui::~Calc_Expo1_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}


void Calc_Expo1_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	RemFcnBtns();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&expo1Cov);
	(**curNode).Show(UiVis);
}

void Calc_Expo1_Leaf_Ui::SetExpo1_Ref(Calc_Expo1_Leaf* ref)
{
	myRef = ref;
	cRef = ref;
	WidgetPaint((tWidget *)&expo1Cov);
	WidgetPaint((tWidget *)&expo1Name);
	instUiPtr = this;
	ConFcnBtns();
}

void Calc_Expo1_Leaf_Ui::SetCompPool(Strct_PoolOwner_Node* poolOwnRef)
{
	myPoolOwnerRef = poolOwnRef;
}

void Calc_Expo1_Leaf_Ui::EnterCompoPool()//(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myPoolOwnerRef->SetEntry(myRef);
	(*(myRef->GetCurNodePtrLoc())) = (Graph_App_I*)myPoolOwnerRef;
	//currentNode = (Graph_App_I*)myPoolOwnerRef;

	RemFcnBtns();
	WidgetPaint((tWidget *)&expo1Cov);
	myPoolOwnerRef->Show();
}

void Calc_Expo1_Leaf_Ui::EnterTrigCompo()
{
	if(myRef->GetTrigCompo() != 0)
	{
		myRef->GetTrigCompo()->SetEntry(myRef);
		(*(myRef->GetCurNodePtrLoc())) = (Graph_App_I*)myRef->GetTrigCompo();
		//currentNode = (Graph_App_I*)myRef->GetTrigCompo();

		RemFcnBtns();
		WidgetPaint((tWidget *)&expo1Cov);

		myRef->GetTrigCompo()->Show(myRef->GetVisitor());
	}
}



void Calc_Expo1_Leaf_Ui::RemFcnBtns()
{
	WidgetRemove((tWidget *)&expo1Btns);
}
void Calc_Expo1_Leaf_Ui::ConFcnBtns()
{
	WidgetPaint((tWidget *)expo1Btns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)expo1Btns);
}



void CompPoolPrsExp1(tWidget *psWidget)
{
	instUiPtr->EnterCompoPool();
}

void NewCompPrsExp1(tWidget *psWidget)
{
	cRef->NewTrigCompo();
}
void EnterTriggerPrsExp1(tWidget *psWidget)
{
	instUiPtr->EnterTrigCompo();
}
