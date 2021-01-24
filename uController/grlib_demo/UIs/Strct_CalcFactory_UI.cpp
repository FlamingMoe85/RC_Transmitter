/*
 * Strct_CalcFactory_UI.cpp
 *
 *  Created on: 04.05.2019
 *      Author: Justus
 */

#include "Strct_CalcFactory_UI.h"

#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"
#include "./grlib/keyboard.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;

#define CAN_X_POS	90
#define CAN_X_WIDTH	200
#define CAN_Y_WIDTH	30
#define NXT_X_WIDTH	24
#define NXT_Y_WIDTH NXT_X_WIDTH

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT		ClrOrange
#define GRABED_PNT		ClrRed
#define TEXT_COLR		ClrWhite

tCanvasWidget ModFacItmSel[] =
{
    CanvasStruct(0, 0,ModFacItmSel+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+30, 45, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

    CanvasStruct(ModFacItmSel,  0,ModFacItmSel + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+30, 45+(1*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

    CanvasStruct(ModFacItmSel, 0,ModFacItmSel+3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+30, 45+(2*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

								    CanvasStruct(ModFacItmSel, 0,ModFacItmSel+4,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, 30, 30,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "88", 0, 0),

																    CanvasStruct(ModFacItmSel, 0,ModFacItmSel+5,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(1*CAN_Y_WIDTH), 30, 30,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "2", 0, 0),

																								    CanvasStruct(ModFacItmSel, 0,0,
																								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(2*CAN_Y_WIDTH), 30, 30,
																												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "3", 0, 0)
};

Canvas(modFacCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0, 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Strct_CalcFactory_UI::Strct_CalcFactory_UI() {
	// TODO Auto-generated constructor stub
	curItem = 0;
	canSel = 1;
}

Strct_CalcFactory_UI::~Strct_CalcFactory_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_CalcFactory_UI::SetCalcFactory_Ref(Strct_CalcFactory *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	//this->SetChldLst(myRef->GetChildList());
	ItemSel(curItem,1);
	//WidgetPaint((tWidget *)&(myCanvacsesChMnr[0]));
	//this->SetName(myRef->GetNameArr());
	Paint();
}

void Strct_CalcFactory_UI::ItemSel(uint16_t itmSel, uint16_t cSel)
{
	uint16_t lstCnt;
	canSel = cSel;
	ModFacItmSel[0].pcText = " - ";
	ModFacItmSel[1].pcText = " - ";
	ModFacItmSel[2].pcText = " - ";
	ModFacItmSel[3].pcText = " - ";
	ModFacItmSel[4].pcText = " - ";
	ModFacItmSel[5].pcText = " - ";


	lstCnt = myRef->GetAmtOfMachines();
	if(curItem >= lstCnt)
	{
		if(lstCnt == 0) curItem = 0;
		else curItem = myRef->GetAmtOfMachines() - 1;
		itmSel = curItem;
	}

	if(cSel == 0)
		{
			ModFacItmSel[0].ui32FillColor = SELECTED_PNT;
			ModFacItmSel[1].ui32FillColor = UNSELCTED_PNT;
			ModFacItmSel[2].ui32FillColor = UNSELCTED_PNT;
			if(myRef->GetAmtOfMachines() > 0)ModFacItmSel[0].pcText =myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 0));
			if(myRef->GetAmtOfMachines() > 1)ModFacItmSel[1].pcText =myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 1));
			if(myRef->GetAmtOfMachines() > 2)ModFacItmSel[2].pcText =myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 2));
		}
		if(cSel == 1)
		{
			ModFacItmSel[0].ui32FillColor = UNSELCTED_PNT;
			ModFacItmSel[1].ui32FillColor = SELECTED_PNT;
			ModFacItmSel[2].ui32FillColor = UNSELCTED_PNT;

			/*
			if(myItmLst->Count() > 0)ModFacItmSel[0].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, -1))->GetNameArr();
			if(myItmLst->Count() > 1)ModFacItmSel[1].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
			if(myItmLst->Count() > 2)ModFacItmSel[2].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, 1))->GetNameArr();
			*/
			if(myRef->GetAmtOfMachines() > 2)
			{
				ModFacItmSel[0].pcText = myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, -1));
				UtilClass::UnsgndIntToStrng(counter_1, UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, -1));
				ModFacItmSel[3].pcText =  counter_1;
			}
			if(myRef->GetAmtOfMachines() > 0)
			{
				ModFacItmSel[1].pcText = myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 0));
				UtilClass::UnsgndIntToStrng(counter_2, UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 0));
				ModFacItmSel[4].pcText = counter_2;
			}
			if(myRef->GetAmtOfMachines() > 1)
			{
				ModFacItmSel[2].pcText = myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 1));
				UtilClass::UnsgndIntToStrng(counter_3, UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 1));
				ModFacItmSel[5].pcText = counter_3;
			}
		}
		if(cSel > 1)
		{
			ModFacItmSel[0].ui32FillColor = UNSELCTED_PNT;
			ModFacItmSel[1].ui32FillColor = UNSELCTED_PNT;
			ModFacItmSel[2].ui32FillColor = SELECTED_PNT;

			if(myRef->GetAmtOfMachines() > 0)ModFacItmSel[0].pcText =myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, -2));
			if(myRef->GetAmtOfMachines() > 1)ModFacItmSel[1].pcText =myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, -1));
			if(myRef->GetAmtOfMachines() > 2)ModFacItmSel[2].pcText =myRef->GetNameOfMachIndex(UtilClass::CatchWrap(myRef->GetAmtOfMachines(), itmSel, 0));
		}
		Paint();
}
void Strct_CalcFactory_UI::Paint()
{
	WidgetPaint((tWidget *)&(ModFacItmSel[0]));
}

void Strct_CalcFactory_UI::Up()
{

	if(curItem < (myRef->GetAmtOfMachines()-1))
	{
		curItem++;
	}
	else
	{
		curItem = 0;
	}

	ItemSel(curItem, canSel);
}
void Strct_CalcFactory_UI::Down()
{
	if(curItem > 0)
	{
		curItem--;
		//if(canSel > 0) canSel--;
	}
	else
	{
		curItem = myRef->GetAmtOfMachines()-1;
	}
	ItemSel(curItem, canSel);
}

void Strct_CalcFactory_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myRef->AddModuleToEntryByType(myRef->GetMachTypeByIndex(curItem));
	(**curNode).Esc(curNode);
	(**curNode).Show(UiVis);
}


void Strct_CalcFactory_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	(**curNode).Show(UiVis);
}
