/*
 * Strct_SaveLoad_Node_UI.cpp
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#include "Strct_SaveLoad_Node_UI.h"
#include <stdint.h>
#include <stdbool.h>
#include "../utils/UtilClass.h"
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

#include "./grlib/keyboard.h"

#include "../utils/UtilClass.h"

extern "C"
{
#include "inc/hw_sysctl.h"
#include "driverlib/sysctl.h"
}

extern const tDisplay g_sKentec320x240x16_SSD2119;
extern tCanvasWidget g_psPanels[];
extern ModelManager modMan;

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

static Strct_SaveLoad_Node_UI* instPtr;

extern void SavePrs();
extern void LoadPrs();
extern void DelModPrs();
extern void FormatPrs();
extern void ExportPrs();
extern void ImportPrs();

void ModNamePrs(tWidget *psWidget);
void ModKeyPrs(tWidget *psWidget, uint32_t ui32Key, uint32_t ui32Event);
void ModSetName(char* n);
char* namArr;
char name_4[NAME_LENGTH];
uint16_t cursChrPos;
static char freeSpaceArr[] = "        ";

Keyboard(ModKeyboard, 0, 0, 0,
&g_sKentec320x240x16_SSD2119, 8, 90, 300, 140,
KEYBOARD_STYLE_TEXT | KEYBOARD_STYLE_FILL |
KEYBOARD_STYLE_PRESS_NOTIFY | KEYBOARD_STYLE_RELEASE_NOTIFY|  KEYBOARD_STYLE_BG,
ClrBlack, ClrGray, ClrDarkGray, ClrGray, ClrWhite, g_psFontCmss14,
100, 50, NUM_KEYBOARD_US_ENGLISH, g_psKeyboardUSEnglish, ModKeyPrs);

Canvas(modKeyBrdCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 8, 90, 300, 140, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(svldCov0, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 90, 0, 230, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(svldCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(svldCov2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 100, 100, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(freeSpaceCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 220, 200, 100, CAN_Y_WIDTH,
		CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
						 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, freeSpaceArr, 0, 0);

tPushButtonWidget saveLoadBtns[] =
{
		RectangularButtonStruct(0, 0, saveLoadBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 160, 100, 40,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 UNSELCTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, "Save", 0, 0, 0, 0, 0),//SavePrs),

						RectangularButtonStruct(saveLoadBtns, 0, saveLoadBtns+2,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 110, 160, 100, 40,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, "Load", 0, 0, 0, 0, 0),//LoadPrs),



										RectangularButtonStruct(saveLoadBtns+1, 0, saveLoadBtns+3,//myCanvacsesAdd+1,
									                 &g_sKentec320x240x16_SSD2119, 220, 160, 100, 40,
													 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
													 UNSELCTED_PNT,
													 UNSELCTED_PNT,
													 ClrGray, TEXT_COLR, &g_sFontCm22, "Del", 0, 0, 0, 0, 0),//DelModPrs),

									 RectangularButtonStruct(saveLoadBtns+2, 0, saveLoadBtns+4,//myCanvacsesAdd+1,
													&g_sKentec320x240x16_SSD2119, CAN_X_POS, 120, CAN_X_WIDTH, CAN_Y_WIDTH,
													 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
													 UNSELCTED_PNT,
													 UNSELCTED_PNT,
													 ClrGray, TEXT_COLR, &g_sFontCm22, "Name", 0, 0, 0, 0, 0),//ModNamePrs),

										RectangularButtonStruct(saveLoadBtns+3, 0, saveLoadBtns+5,//myCanvacsesAdd+1,
													&g_sKentec320x240x16_SSD2119, 0, 200, 100, 40,
													CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
													UNSELCTED_PNT,
													UNSELCTED_PNT,
													ClrGray, TEXT_COLR, &g_sFontCm22, "Export", 0, 0, 0, 0, 0),//ExportPrs),



										RectangularButtonStruct(saveLoadBtns+4, 0, 0,//myCanvacsesAdd+1,
												    &g_sKentec320x240x16_SSD2119, 110, 200, 100, 40,
													CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
													UNSELCTED_PNT,
													UNSELCTED_PNT,
													ClrGray, TEXT_COLR, &g_sFontCm22, "Import", 0, 0, 0, 0, 0),



};

tCanvasWidget myCanvacsesModelSel[] =
{
    CanvasStruct(0, 0,myCanvacsesModelSel+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 30, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),
    CanvasStruct(myCanvacsesModelSel,  0,myCanvacsesModelSel + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 30+(1*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

    CanvasStruct(myCanvacsesModelSel, 0,myCanvacsesModelSel + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 30+(2*CAN_Y_WIDTH), CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

								 CanvasStruct(myCanvacsesModelSel, 0,0,
								                  &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH,
								 				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
								 				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Save / Load", 0, 0)
};

//Canvas(selCovPool, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, CAN_X_WIDTH, 2*CAN_Y_WIDTH, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Strct_SaveLoad_Node_UI::Strct_SaveLoad_Node_UI() {
	// TODO Auto-generated constructor stub
	name_4[0] = 'N';
	name_4[1] = 'e';
	name_4[2] = 'w';
	name_4[3] = ' ';
	name_4[4] = 'M';
	name_4[5] = 'o';
	name_4[6] = 'd';
	name_4[7] = '\0';

	curItem = 0;
	btnSel = 0;
}

Strct_SaveLoad_Node_UI::~Strct_SaveLoad_Node_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_SaveLoad_Node_UI::ShowFreeSpace()
{
	UtilClass::IntToPercStrng(&(freeSpaceArr[0]), myRef->GetFreeSpacePerc(), UNSIGNED);
	CanvasTextSet(&freeSpaceCan, &(freeSpaceArr[0]));
	WidgetPaint((tWidget *)&freeSpaceCan);
}

void ModSetName(char* n)
{
	cursChrPos = 0;
	namArr = n;
	myCanvacsesModelSel[3].pcText = n;
	while(n[cursChrPos] != '\0')
	{
		cursChrPos++;
	}
}

void ModNamePrs(tWidget *psWidget)
{
	instPtr->newOrOvrwrt = NEW_MOD;
	ModSetName(&(name_4[0]));
	WidgetRemove((tWidget *)&saveLoadBtns);
	//WidgetPaint((tWidget *)&selCov);
	WidgetAdd(WIDGET_ROOT, (tWidget *)&ModKeyboard);
	WidgetPaint((tWidget *)&ModKeyboard);
	WidgetPaint((tWidget *)&(myCanvacsesModelSel[3]));
}

void ModKeyPrs(tWidget *psWidget, uint32_t ui32Key, uint32_t ui32Event)
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

			WidgetRemove((tWidget *)&ModKeyboard);
			WidgetPaint((tWidget *)&modKeyBrdCov);
			myCanvacsesModelSel[3].pcText = "Save / Load";
			saveLoadBtns[3].pcText = namArr;
			WidgetPaint((tWidget *)&(myCanvacsesModelSel[0]));
			WidgetPaint((tWidget *)saveLoadBtns);
			WidgetAdd(WIDGET_ROOT, (tWidget *)saveLoadBtns);
			return;
		}
	}

	myCanvacsesModelSel[3].pcText = namArr;
	WidgetPaint((tWidget *)&(myCanvacsesModelSel[3]));
}

void Strct_SaveLoad_Node_UI::SaveMod()
{
	if(newOrOvrwrt == OVERWRITE)
	{
		myRef->PrepForOverwrite(curItem);
	}
	else
	{
		myRef->SaveMod(&(name_4[0]));
	}

	ShowFreeSpace();
//	ItemSel(GetItmSel(), 1);
}

void Strct_SaveLoad_Node_UI::SetSaveLoad_Ref(Strct_SaveLoad_Node* ref)
{
	myRef = ref;
	newOrOvrwrt = OVERWRITE;
	instPtr = this;
	//myRef_C = ref;
	//WidgetAdd(WIDGET_ROOT, (tWidget *)moduleBtns);
	this->SetActUi(this->GetStackPos());
	//this->SetChldLst(myRef->GetChildList());


	if(myRef->GetCurModNmbr() <= myRef->GetAmtOfModels()-1)
	{
		curItem = myRef->GetCurModNmbr();
	}
ItemSel(GetItmSel(), 1);
	//this->SetName(myRef->GetNameArr());
	//WidgetPaint((tWidget *)&moduleBtns);
	//WidgetPaint((tWidget *)&svldCov);
//Paint();
	ConFcnBtns();
	ShowFreeSpace();
}

void Strct_SaveLoad_Node_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetRemove((tWidget *)&saveLoadBtns);
	WidgetPaint((tWidget *)&svldCov);
	(**curNode).Show(UiVis);
}

void Strct_SaveLoad_Node_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Enter(curNode, this->GetItmSel());
	WidgetRemove((tWidget *)&saveLoadBtns);
	WidgetPaint((tWidget *)&svldCov);
	(**curNode).Show(UiVis);
}

void Strct_SaveLoad_Node_UI::RemFcnBtns()
{
	WidgetRemove((tWidget *)&saveLoadBtns);
}
void Strct_SaveLoad_Node_UI::ConFcnBtns()
{
	WidgetPaint((tWidget *)saveLoadBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)saveLoadBtns);
}


void Strct_SaveLoad_Node_UI::Up()
{
	if(curItem < (myRef->GetAmtOfModels()-1))
	{
		curItem++;
	}
	else
	{
		curItem = 0;
	}

	ItemSel(curItem, canSel);
}

void Strct_SaveLoad_Node_UI::Down()
{
	if(curItem > 0)
	{
		curItem--;
	}
	else
	{
		//curItem = myRef->GetEntry()->GetChildList()->Count()-1;
		curItem = myRef->GetAmtOfModels()-1;
	}
	ItemSel(curItem, canSel);
}


void Strct_SaveLoad_Node_UI::Paint()
{
	//WidgetPaint((tWidget *)&(svldCov0));
	//WidgetPaint((tWidget *)&(svldCov2));
	WidgetPaint((tWidget *)&(myCanvacsesModelSel[0]));
}

void Strct_SaveLoad_Node_UI::ItemSel(uint16_t sel, uint16_t cSel)
{
	uint16_t modAmt, caughtWrap;
	canSel = cSel;
	myCanvacsesModelSel[0].pcText = " - ";
	myCanvacsesModelSel[1].pcText = " - ";
	myCanvacsesModelSel[2].pcText = " - ";

		if(cSel == 1)
		{
			myCanvacsesModelSel[0].ui32FillColor = UNSELCTED_PNT;
			myCanvacsesModelSel[1].ui32FillColor = SELECTED_PNT;
			myCanvacsesModelSel[2].ui32FillColor = UNSELCTED_PNT;

			modAmt = myRef->GetAmtOfModels();
			if(modAmt > 2)
				{
				caughtWrap = UtilClass::CatchWrap(modAmt, sel, -1);
				myRef->GetNameOfModel(&(name_3[0]), caughtWrap); //myRef->GetPoolLstMem(UtilClass::CatchWrap(myRef->GetAmtOfModels(), itmSel, -1))->GetNameArr();
				myCanvacsesModelSel[0].pcText = &(name_3[0]);
				}
			if(modAmt > 0)
				{
				caughtWrap = UtilClass::CatchWrap(modAmt, sel, 0);
				myRef->GetNameOfModel(&(name_1[0]), caughtWrap);
				myCanvacsesModelSel[1].pcText = &(name_1[0]);
				}
			if(modAmt > 1)
				{
				caughtWrap = UtilClass::CatchWrap(modAmt, sel, 1);
				myRef->GetNameOfModel(&(name_2[0]), caughtWrap);
				myCanvacsesModelSel[2].pcText = &(name_2[0]);
				}
		}
		Paint();
}

uint16_t Strct_SaveLoad_Node_UI::GetCanSel()
{
	return canSel;
}

uint16_t Strct_SaveLoad_Node_UI::GetItmSel()
{
	return curItem;
}

void Strct_SaveLoad_Node_UI::Right()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		btnSel++;
		if(btnSel >= 6)btnSel=0;
		RefreshButtons();
	}
	else
	{

	}
}
void Strct_SaveLoad_Node_UI::Left()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel > 0)btnSel--;
		else btnSel=5;
		RefreshButtons();
	}
	else
	{

	}
}

void Strct_SaveLoad_Node_UI::Grab()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel == 0)SavePrs();
		if(btnSel == 1)LoadPrs();
		if(btnSel == 2)DelModPrs();
		if(btnSel == 3)FormatPrs();
		if(btnSel == 4)ExportPrs();
		if(btnSel == 5)ImportPrs();
	}
	else
	{


	}
}

void Strct_SaveLoad_Node_UI::RefreshButtons()
{
	for(unsigned int i=0; i<5; i++)
	{
		saveLoadBtns[i].ui32FillColor = UNSELCTED_PNT;
	}
	if(GetRotaryState() == ROTARY_IS_DOWN)saveLoadBtns[btnSel].ui32FillColor = SELECTED_PNT;
	WidgetPaint((tWidget *)&saveLoadBtns);
}
