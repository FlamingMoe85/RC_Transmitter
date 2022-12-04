/*
 * ItemSelector.cpp
 *
 *  Created on: 23.09.2018
 *      Author: Justus
 */

#include "ItemSelector.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"
#include "./grlib/keyboard.h"

#include "../../../share/CharSelector.hpp"

static CharSelector charSelector;

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


void NamePrs(tWidget *psWidget);
void KeyPrs(tWidget *psWidget, uint32_t ui32Key, uint32_t ui32Event);
extern void RemBtns_ItmSel();
extern void ConBtns_ItmSel();

char* namArr;
char curCharArr[2] = {' ', '\0'};
uint16_t cursChrPos;

Keyboard(g_sKeyboard, 0, 0, 0,
&g_sKentec320x240x16_SSD2119, 8, 90, 300, 140,
KEYBOARD_STYLE_TEXT | KEYBOARD_STYLE_FILL |
KEYBOARD_STYLE_PRESS_NOTIFY | KEYBOARD_STYLE_RELEASE_NOTIFY|  KEYBOARD_STYLE_BG,
ClrBlack, ClrGray, ClrDarkGray, ClrGray, ClrWhite, g_psFontCmss14,
100, 50, NUM_KEYBOARD_US_ENGLISH, g_psKeyboardUSEnglish, KeyPrs);

tCanvasWidget myCanvacsesItmSel[] =
{
    CanvasStruct(0, 0,myCanvacsesItmSel+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+30, 45, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

    CanvasStruct(myCanvacsesItmSel,  0,myCanvacsesItmSel + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+30, 45+(1*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

    CanvasStruct(myCanvacsesItmSel, 0,myCanvacsesItmSel+3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+30, 45+(2*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

								    CanvasStruct(myCanvacsesItmSel, 0,myCanvacsesItmSel+4,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, 30, 30,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "88", 0, 0),

																    CanvasStruct(myCanvacsesItmSel, 0,myCanvacsesItmSel+5,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(1*CAN_Y_WIDTH), 30, 30,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "2", 0, 0),

																								    CanvasStruct(myCanvacsesItmSel, 0,0,
																								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(2*CAN_Y_WIDTH), 30, 30,
																												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "3", 0, 0)
};

Canvas(keyBrdCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 8, 90, 300, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(selCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 90, 0, 230, 135, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(CurChar, 0, 0,0,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 30, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "", 0, 0);
tPushButtonWidget itmSelBtns[] =
{
		RectangularButtonStruct(0, 0, 0,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+30, 0, CAN_X_WIDTH, CAN_Y_WIDTH,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 SELECTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0, 0, 0, NamePrs)
};

ItemSelector::ItemSelector() {
	// TODO Auto-generated constructor stub
	curItem = 0;
	canSel = 1;
	WidgetAdd(WIDGET_ROOT, (tWidget *)itmSelBtns);
	grabMode = 0;
	myCanvacsesItmSel[3].pcText = counter_1;
	myCanvacsesItmSel[4].pcText = counter_2;
	myCanvacsesItmSel[5].pcText = counter_3;
	DisableNameMode();
}

ItemSelector::~ItemSelector() {
	// TODO Auto-generated destructor stub
}

void ItemSelector::SetChldLst(List<Graph_App_I*>* lstArg)
{
	myItmLst = lstArg;
}

void ItemSelector::RmoveNameBtn()
{
	WidgetRemove((tWidget *)itmSelBtns);
}

void ItemSelector::ConctNameBtn()
{
	WidgetAdd(WIDGET_ROOT, (tWidget *)itmSelBtns);
}

void ItemSelector::SetNameSelcted()
{
	itmSelBtns[0].ui32FillColor = SELECTED_PNT;
	itmSelBtns[0].ui32OutlineColor = ClrGray;
	WidgetPaint((tWidget *)&(itmSelBtns[0]));
}

void ItemSelector::SetNameUnseclected()
{
	itmSelBtns[0].ui32FillColor = UNSELCTED_PNT;
	itmSelBtns[0].ui32OutlineColor = ClrGray;
	WidgetPaint((tWidget *)&(itmSelBtns[0]));
}

void ItemSelector::MarkName()
{
	itmSelBtns[0].ui32OutlineColor = ClrRed;
	WidgetPaint((tWidget *)&(itmSelBtns[0]));
}

void ItemSelector::UnmarkName()
{
	itmSelBtns[0].ui32OutlineColor = ClrGray;
	WidgetPaint((tWidget *)&(itmSelBtns[0]));
}

void ItemSelector::SetName(char* n)
{
	cursChrPos = 0;
	namArr = n;
	itmSelBtns[0].pcText = n;
	while(n[cursChrPos] != '\0')
	{
		cursChrPos++;
	}
	//EscItmSel();
}

void NamePrs(tWidget *psWidget)
{
	RemBtns_ItmSel();
	WidgetPaint((tWidget *)&selCov);
	WidgetAdd(WIDGET_ROOT, (tWidget *)&g_sKeyboard);
	WidgetPaint((tWidget *)&g_sKeyboard);
}

void KeyPrs(tWidget *psWidget, uint32_t ui32Key, uint32_t ui32Event)
{

	if(ui32Event == 1)
	{
		if(ui32Key == 8)
		{
			if(cursChrPos > 0)
			{
				namArr[cursChrPos-1] = namArr[cursChrPos];
				cursChrPos--;
			}
		}
		else if((cursChrPos < (NAME_LENGTH-1)) && (ui32Key != 13))
		{
			namArr[cursChrPos+1] = namArr[cursChrPos];
			namArr[cursChrPos++] = ui32Key;
		}
	}
	if(ui32Event == 2)
	{
		if(ui32Key == 13)
		{

			WidgetRemove((tWidget *)&g_sKeyboard);
			WidgetPaint((tWidget *)&keyBrdCov);
			WidgetPaint((tWidget *)&(myCanvacsesItmSel[0]));
			ConBtns_ItmSel();
		}
	}

	itmSelBtns[0].pcText = namArr;
	WidgetPaint((tWidget *)&(itmSelBtns[0]));
}

void ItemSelector::KeyPress(char c, int action)
{
	switch(action)
	{
		case SHOW_CHAR:
			curCharArr[0] = c;
			CurChar.pcText = curCharArr;
			WidgetPaint((tWidget *)&CurChar);
			break;

		case REMOVE_CHAR:
			if(cursChrPos > 0)
			{
				namArr[cursChrPos-1] = namArr[cursChrPos];
				cursChrPos--;
				itmSelBtns[0].pcText = namArr;
				WidgetPaint((tWidget *)&(itmSelBtns[0]));
			}
			break;

		case ADD_CHAR:
			if(cursChrPos < (NAME_LENGTH-1))
			{
				namArr[cursChrPos+1] = namArr[cursChrPos];
				namArr[cursChrPos++] = c;
				itmSelBtns[0].pcText = namArr;
				WidgetPaint((tWidget *)&(itmSelBtns[0]));
			}
			break;
	};

}

void ItemSelector::ItemSel(uint16_t itmSel, uint16_t cSel)
{
	uint16_t lstCnt;
	canSel = cSel;
	char counter[3];
	myCanvacsesItmSel[0].pcText = " - ";
	myCanvacsesItmSel[1].pcText = " - ";
	myCanvacsesItmSel[2].pcText = " - ";
	myCanvacsesItmSel[3].pcText = " - ";
	myCanvacsesItmSel[4].pcText = " - ";
	myCanvacsesItmSel[5].pcText = " - ";


	lstCnt = myItmLst->Count();
	if(curItem >= lstCnt)
	{
		if(lstCnt == 0) curItem = 0;
		else curItem = myItmLst->Count() - 1;
		itmSel = curItem;
	}

	if(cSel == 0)
		{
			myCanvacsesItmSel[0].ui32FillColor = SELECTED_PNT;
			myCanvacsesItmSel[1].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesItmSel[2].ui32FillColor = UNSELCTED_PNT;
			if(myItmLst->Count() > 0)myCanvacsesItmSel[0].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
			if(myItmLst->Count() > 1)myCanvacsesItmSel[1].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 1))->GetNameArr();
			if(myItmLst->Count() > 2)myCanvacsesItmSel[2].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 2))->GetNameArr();
		}
		if(cSel == 1)
		{
			myCanvacsesItmSel[0].ui32FillColor = UNSELCTED_PNT;
			if(grabMode == 1) myCanvacsesItmSel[1].ui32FillColor = GRABED_PNT;
			else myCanvacsesItmSel[1].ui32FillColor = SELECTED_PNT;
			myCanvacsesItmSel[2].ui32FillColor = UNSELCTED_PNT;

			/*
			if(myItmLst->Count() > 0)myCanvacsesItmSel[0].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, -1))->GetNameArr();
			if(myItmLst->Count() > 1)myCanvacsesItmSel[1].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
			if(myItmLst->Count() > 2)myCanvacsesItmSel[2].pcText = myItmLst->At(CatchWrap(myItmLst->Count(), itmSel, 1))->GetNameArr();
			*/
			if(myItmLst->Count() > 2)
			{
				myCanvacsesItmSel[0].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, -1))->GetNameArr();
				UtilClass::UnsgndIntToStrng(counter_1, UtilClass::CatchWrap(myItmLst->Count(), itmSel, -1));
				myCanvacsesItmSel[3].pcText =  counter_1;
			}
			if(myItmLst->Count() > 0)
			{
				myCanvacsesItmSel[1].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
				UtilClass::UnsgndIntToStrng(counter_2, UtilClass::CatchWrap(myItmLst->Count(), itmSel, 0));
				myCanvacsesItmSel[4].pcText = counter_2;
			}
			if(myItmLst->Count() > 1)
			{
				myCanvacsesItmSel[2].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 1))->GetNameArr();
				UtilClass::UnsgndIntToStrng(counter_3, UtilClass::CatchWrap(myItmLst->Count(), itmSel, 1));
				myCanvacsesItmSel[5].pcText = counter_3;
			}
		}
		if(cSel > 1)
		{
			myCanvacsesItmSel[0].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesItmSel[1].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesItmSel[2].ui32FillColor = SELECTED_PNT;

			if(myItmLst->Count() > 0)myCanvacsesItmSel[0].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, -2))->GetNameArr();
			if(myItmLst->Count() > 1)myCanvacsesItmSel[1].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, -1))->GetNameArr();
			if(myItmLst->Count() > 2)myCanvacsesItmSel[2].pcText = myItmLst->At(UtilClass::CatchWrap(myItmLst->Count(), itmSel, 0))->GetNameArr();
		}
		/*
		for(uint16_t i=3; i>myItmLst->Count(); i--)
		{
			myCanvacsesItmSel[i-1].pcText = " - ";
		}
		*/
		Paint();
}

void ItemSelector::EscItmSel()
{
	WidgetPaint((tWidget *)&(selCov));
}

void ItemSelector::ItemUp()
{
	if(NameModeActive())
	{
		KeyPress(charSelector.TypeUp(), SHOW_CHAR);
	}
	else
	{
		if(curItem < (myItmLst->Count()-1))
		{
			if(grabMode == 1) myItmLst->MoveItmAtLoc(curItem, 1);
			/*
			nxtItm = CatchWrap(myItmLst->Count(), curItem, 1);
			tmpItmPtr = myItmLst->At(nxtItm);
			myItmLst->At(nxtItm) = */
			curItem++;
			//if(canSel < 2) canSel++;
		}
		else
		{
			if(grabMode == 1) myItmLst->MoveItmAtLoc(curItem, 1);
			curItem = 0;
		}

		ItemSel(curItem, canSel);
	}
}
void ItemSelector::ItemDown()
{
	if(NameModeActive())
	{
		KeyPress(charSelector.TypeDown(), SHOW_CHAR);
	}
	else
	{
		if(curItem > 0)
		{
			if(grabMode == 1) myItmLst->MoveItmAtLoc(curItem, -1);
			curItem--;
			//if(canSel > 0) canSel--;
		}
		else
		{
			if(grabMode == 1) myItmLst->MoveItmAtLoc(curItem, -1);
			curItem = myItmLst->Count()-1;
		}
		ItemSel(curItem, canSel);
	}
}
void ItemSelector::ItemRight()
{
	if(NameModeActive())
	{
		KeyPress(charSelector.NextChar(), SHOW_CHAR);
	}
}
void ItemSelector::ItemLeft()
{
	if(NameModeActive())
	{
		KeyPress(charSelector.PrvChar(), SHOW_CHAR);
	}
}

void ItemSelector::AddCurChar()
{
	KeyPress(charSelector.CurChar(), ADD_CHAR);
}


void ItemSelector::RemoveChar()
{
	KeyPress(charSelector.CurChar(), REMOVE_CHAR);
}

void ItemSelector::ItemGrab()
{
	if(grabMode == 0)
	{
		grabMode = 1;
	}
	else
	{
		grabMode = 0;
	}
	ItemSel(GetItmSel(), 1);
}

void ItemSelector::Paint()
{
	WidgetPaint((tWidget *)&(itmSelBtns[0]));
	WidgetPaint((tWidget *)&(myCanvacsesItmSel[0]));
}

uint16_t ItemSelector::GetCanSel()
{
	return canSel;
}

uint16_t ItemSelector::GetItmSel()
{
	return curItem;
}

void  ItemSelector::EnableNameMode()
{
	nameMode = true;
	SetNameSelcted();
	KeyPress(charSelector.CurChar(), SHOW_CHAR);
}
void  ItemSelector::DisableNameMode()
{
	nameMode = false;
	SetNameUnseclected();
}
bool  ItemSelector::NameModeActive()
{
	return nameMode;
}
