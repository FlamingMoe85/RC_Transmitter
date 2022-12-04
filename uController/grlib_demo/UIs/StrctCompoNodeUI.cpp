/*
 * StrctCompoNodeUI.cpp
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#include "StrctCompoNodeUI.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

#include "../../../share/Graph_App/Strct_CalcFactory.h"
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

Strct_Compo_Node* myRef_C;
Strct_CalcFactory myCalcFac;

extern void AddModPrs();
void NewCompPress(tWidget *psWidget);
extern void CompPoolPrs_CompNode();
extern void DelPrs();

tCanvasWidget myCanvacsesNode[] =
{
    CanvasStruct(0, 0,0,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 30, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Compo", 0, 0)
};
/**/
tPushButtonWidget moduleBtns[] =
{
		RectangularButtonStruct(0, 0, moduleBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 140, 100, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 UNSELCTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, " Add Module ", 0, 0, 0, 0, 0),//AddModPrs),

						RectangularButtonStruct(moduleBtns, 0, moduleBtns+2,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 110, 140, 100, 50,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, " CompPool ", 0, 0, 0, 0, 0),//CompPoolPrs_CompNode),

										RectangularButtonStruct(moduleBtns+1, 0, moduleBtns+3,//myCanvacsesAdd+1,
																&g_sKentec320x240x16_SSD2119, 220, 140, 100, 50,
																CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																UNSELCTED_PNT,
																UNSELCTED_PNT,
																ClrGray, TEXT_COLR, &g_sFontCm22, "DelComp", 0, 0, 0, 0, 0),//DelPrs),

																RectangularButtonStruct(moduleBtns+2, 0, 0,//myCanvacsesAdd+1,
																					                 &g_sKentec320x240x16_SSD2119, 110, 200, 100, 50,
																									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																									 UNSELCTED_PNT,
																									 UNSELCTED_PNT,
																									 ClrGray, TEXT_COLR, &g_sFontCm22, " New Comp", 0, 0, 0, 0, 0)//NewCompPress)




};
Canvas(modBtnsCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Strct_Compo_Node_UI::Strct_Compo_Node_UI() {
	// TODO Auto-generated constructor stub
	btnSel = 0;
}

Strct_Compo_Node_UI::~Strct_Compo_Node_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_Compo_Node_UI::SetStrctCmp_Ref(Strct_Compo_Node *ref)
{
	myRef = ref;
	myRef_C = ref;
	this->ConctNameBtn();
	WidgetAdd(WIDGET_ROOT, (tWidget *)moduleBtns);
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	ItemSel(GetItmSel(), 1);
	this->SetName(myRef->GetNameArr());
	WidgetPaint((tWidget *)&moduleBtns);
	Paint();
}

void NewCompPress(tWidget *psWidget)
{
	myRef_C->AddCompAtEnd();
}

void Strct_Compo_Node_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	if(NameModeActive() == true)
	{
		RemoveChar();
	}
	else
	{
		(**curNode).Esc(curNode);
		this->RmoveNameBtn();
		WidgetRemove((tWidget *)&moduleBtns);
		WidgetPaint((tWidget *)&modBtnsCov);
		(**curNode).Show(UiVis);
	}
}

void Strct_Compo_Node_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	if(NameModeActive() == true)
	{
		AddCurChar();
	}
	else
	{
		(**curNode).Enter(curNode, this->GetItmSel());
		this->RmoveNameBtn();
		WidgetRemove((tWidget *)&moduleBtns);
		WidgetPaint((tWidget *)&modBtnsCov);
		(**curNode).Show(UiVis);
	}
}

void Strct_Compo_Node_UI::EnterModFac(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{

	myCalcFac.SetEntry(myRef);
	*curNode = &myCalcFac;
	//(**curNode).Enter(curNode, this->GetItmSel());


	WidgetRemove((tWidget *)&moduleBtns);
	WidgetPaint((tWidget *)&modBtnsCov);
	(**curNode).Show(UiVis);
}

void Strct_Compo_Node_UI::SetCompPool(Strct_PoolOwner_Node* poolOwnRef)
{
	myPoolOwnerRef = poolOwnRef;
}

void Strct_Compo_Node_UI::EnterCompoPool(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myPoolOwnerRef->SetEntry(
			myRef);
	*curNode = (Graph_App_I*)myPoolOwnerRef;

		WidgetRemove((tWidget *)&moduleBtns);
		WidgetPaint((tWidget *)&modBtnsCov);
		(**curNode).Show(UiVis);
}

void Strct_Compo_Node_UI::RemFcnBtns()
{
	WidgetRemove((tWidget *)&moduleBtns);
}

void Strct_Compo_Node_UI::ConFcnBtns()
{
	WidgetPaint((tWidget *)moduleBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)moduleBtns);
}

void Strct_Compo_Node_UI::DelSelItm()
{
	myRef->GetChildList()->DelAtLoc(this->GetItmSel());
	myRef->Show();
}


void Strct_Compo_Node_UI::Right()
{
	if((GetRotaryState() == ROTARY_IS_DOWN) && (NameModeActive() == false))
	{
		btnSel++;
		if(btnSel >= 5)btnSel=0;
		RefreshButtons();
	}
	else
	{
		ItemRight();
	}
}

void Strct_Compo_Node_UI::Left()
{
	if((GetRotaryState() == ROTARY_IS_DOWN) && (NameModeActive() == false))
	{
		if(btnSel > 0)btnSel--;
		else btnSel=4;
		RefreshButtons();
	}
	else
	{
		ItemLeft();
	}
}
void Strct_Compo_Node_UI::Grab()
{

	if(NameModeActive() == true)
	{
		DisableNameMode();
	}
	else if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel == 0)AddModPrs();
		if(btnSel == 1)CompPoolPrs_CompNode();
		if(btnSel == 2)DelPrs();
		if(btnSel == 3)myRef->AddCompAtEnd();
		if(btnSel == 4)
		{
			EnableNameMode();
		}
	}
	else
	{

		ItemGrab();
	}
}

void Strct_Compo_Node_UI::RefreshButtons()
{
	for(unsigned int i=0; i<4; i++)
	{
		moduleBtns[i].ui32FillColor = UNSELCTED_PNT;
	}

	if(btnSel >= 4)
	{
		WidgetPaint((tWidget *)&moduleBtns);
		if(GetRotaryState() == ROTARY_IS_DOWN) MarkName();
		else UnmarkName();
	}
	else
	{
		UnmarkName();
		if(GetRotaryState() == ROTARY_IS_DOWN)moduleBtns[btnSel].ui32FillColor = SELECTED_PNT;
		WidgetPaint((tWidget *)&moduleBtns);
	}
}
