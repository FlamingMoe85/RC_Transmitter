/*
 * Strct_PoolOwner_UI.cpp
 *
 *  Created on: 06.05.2019
 *      Author: Justus
 */

#include "Strct_PoolOwner_UI.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"
#include "./grlib/keyboard.h"

#include "../utils/UtilClass.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;

#define CAN_X_POS	100
#define CAN_X_WIDTH	200
#define CAN_Y_WIDTH	30
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)
#define NXT_X_WIDTH	24
#define NXT_Y_WIDTH NXT_X_WIDTH
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT		ClrOrange
#define GRABED_PNT		ClrRed
#define TEXT_COLR		ClrWhite


uint16_t cursChrPos;

tCanvasWidget myCanvacsesPoolItmSel[] =
{
    CanvasStruct(0, 0,myCanvacsesPoolItmSel+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),
    CanvasStruct(myCanvacsesPoolItmSel,  0,myCanvacsesPoolItmSel + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(1*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

    CanvasStruct(myCanvacsesPoolItmSel, 0,myCanvacsesPoolItmSel + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(2*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

								 CanvasStruct(myCanvacsesPoolItmSel, 0,0,
								                  &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH,
								 				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
								 				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Compo Pool", 0, 0)
};

Canvas(selCovPool, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, CAN_X_WIDTH, 2*CAN_Y_WIDTH, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Strct_PoolOwner_UI::Strct_PoolOwner_UI() {
	// TODO Auto-generated constructor stub
	curItem = 0;
	canSel = 1;
}

Strct_PoolOwner_UI::~Strct_PoolOwner_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_PoolOwner_UI::SetPoolOwner_Ref(Strct_PoolOwner_Node* ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	this->ItemSel(GetItmSel(),1);
	//WidgetPaint((tWidget *)&(myCanvacsesChMnr[0]));
	Paint();
}

void Strct_PoolOwner_UI::ItemSel(uint16_t itmSel, uint16_t cSel)
{
	canSel = cSel;
	myCanvacsesPoolItmSel[0].pcText = " - ";
	myCanvacsesPoolItmSel[1].pcText = " - ";
	myCanvacsesPoolItmSel[2].pcText = " - ";

	/*if(cSel == 0)
		{
			myCanvacsesItmSel[0].ui32FillColor = SELECTED_PNT;
			myCanvacsesItmSel[1].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesItmSel[2].ui32FillColor = UNSELCTED_PNT;
			if(myItmLst->Count() > 0)myCanvacsesItmSel[0].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
			if(myItmLst->Count() > 1)myCanvacsesItmSel[1].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 1))->GetNameArr();
			if(myItmLst->Count() > 2)myCanvacsesItmSel[2].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 2))->GetNameArr();
		}*/
		if(cSel == 1)
		{
			myCanvacsesPoolItmSel[0].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesPoolItmSel[1].ui32FillColor = SELECTED_PNT;
			myCanvacsesPoolItmSel[2].ui32FillColor = UNSELCTED_PNT;

			/*
			if(myItmLst->Count() > 0)myCanvacsesItmSel[0].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, -1))->GetNameArr();
			if(myItmLst->Count() > 1)myCanvacsesItmSel[1].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
			if(myItmLst->Count() > 2)myCanvacsesItmSel[2].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, 1))->GetNameArr();
			*/
			if(myRef->GetPoolLst()->Count() > 2)myCanvacsesPoolItmSel[0].pcText = myRef->GetPoolLstMem(UtilClass::CatchWrap(myRef->GetPoolLst()->Count(), itmSel, -1))->GetNameArr();
			if(myRef->GetPoolLst()->Count() > 0)myCanvacsesPoolItmSel[1].pcText = myRef->GetPoolLstMem(UtilClass::CatchWrap(myRef->GetPoolLst()->Count(), itmSel, 0))->GetNameArr();
			if(myRef->GetPoolLst()->Count() > 1)myCanvacsesPoolItmSel[2].pcText = myRef->GetPoolLstMem(UtilClass::CatchWrap(myRef->GetPoolLst()->Count(), itmSel, 1))->GetNameArr();
		}
		/*
		if(cSel > 1)
		{
			myCanvacsesItmSel[0].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesItmSel[1].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesItmSel[2].ui32FillColor = SELECTED_PNT;

			if(myItmLst->Count() > 0)myCanvacsesItmSel[0].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, -2))->GetNameArr();
			if(myItmLst->Count() > 1)myCanvacsesItmSel[1].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, -1))->GetNameArr();
			if(myItmLst->Count() > 2)myCanvacsesItmSel[2].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
		}*/
		/*
		for(uint16_t i=3; i>myItmLst->Count(); i--)
		{
			myCanvacsesItmSel[i-1].pcText = " - ";
		}
		*/
		Paint();
}

void Strct_PoolOwner_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myRef->GetEntry()->GetChildList()->AddEnd(
			myRef->GetPoolLstMem(this->GetItmSel()));

	(**curNode).Esc(curNode);
	//WidgetRemove((tWidget *)&cmpBtns);
	//WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}


void Strct_PoolOwner_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	//WidgetRemove((tWidget *)&cmpBtns);
	//WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}

void Strct_PoolOwner_UI::Up()
{

	//if(curItem < (myRef->GetEntry()->GetChildList()->Count()-1))
	if(curItem < (myRef->GetPoolLst()->Count()-1))
	{
		curItem++;
	}
	else
	{
		curItem = 0;
	}

	ItemSel(curItem, canSel);
}
void Strct_PoolOwner_UI::Down()
{
	if(curItem > 0)
	{
		curItem--;
	}
	else
	{
		//curItem = myRef->GetEntry()->GetChildList()->Count()-1;
		curItem = myRef->GetPoolLst()->Count()-1;
	}
	ItemSel(curItem, canSel);
}
void Strct_PoolOwner_UI::Right()
{

}
void Strct_PoolOwner_UI::Left()
{

}

void Strct_PoolOwner_UI::Grab()
{

}

void Strct_PoolOwner_UI::Paint()
{
	WidgetPaint((tWidget *)&(myCanvacsesPoolItmSel[0]));
}

uint16_t Strct_PoolOwner_UI::GetCanSel()
{
	return canSel;
}

uint16_t Strct_PoolOwner_UI::GetItmSel()
{
	return curItem;
}
