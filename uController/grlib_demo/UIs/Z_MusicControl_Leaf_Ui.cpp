/*
 * Z_MusicControl_Leaf_Ui.cpp
 *
 *  Created on: 09.02.2022
 *      Author: Justus
 */

#include "Z_MusicControl_Leaf_Ui.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;

#define CAN_X_POS	100
#define CAN_X_WIDTH	100
#define CAN_Y_WIDTH	30
#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT	ClrOrange
#define TEXT_COLR		ClrWhite

char playArr[2];
char pauseArr[2];
char fwArr[2];
char bwArr[2];
char vuArr[2];
char vdArr[2];

Canvas(musicName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 100, 0, 200, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Music", 0, 0);
Canvas(musicCov, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
tCanvasWidget musicCanvaces[] =
{
    CanvasStruct(0, 0,musicCanvaces+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Play", 0, 0),


	CanvasStruct(musicCanvaces,  0,musicCanvaces + 2,
				 &g_sKentec320x240x16_SSD2119, CAN_X_POS+CAN_X_WIDTH, 45, CAN_X_WIDTH, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

	CanvasStruct(musicCanvaces, 0,musicCanvaces+3,
			     &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+CAN_Y_WIDTH, CAN_X_WIDTH, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Pause", 0, 0),


	CanvasStruct(musicCanvaces,  0,musicCanvaces + 4,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+CAN_X_WIDTH, 45+CAN_Y_WIDTH, CAN_X_WIDTH, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

	CanvasStruct(musicCanvaces, 0,musicCanvaces+5,
			     &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(CAN_Y_WIDTH*2), CAN_X_WIDTH, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Forward", 0, 0),


	CanvasStruct(musicCanvaces,  0,musicCanvaces + 6,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+CAN_X_WIDTH, 45+(CAN_Y_WIDTH*2), CAN_X_WIDTH, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

	CanvasStruct(musicCanvaces, 0,musicCanvaces+7,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(CAN_Y_WIDTH*3), CAN_X_WIDTH, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Backward", 0, 0),


	CanvasStruct(musicCanvaces,  0,musicCanvaces+8,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+CAN_X_WIDTH, 45+(CAN_Y_WIDTH*3), CAN_X_WIDTH, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

				CanvasStruct(musicCanvaces, 0,musicCanvaces+9,
						     &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(CAN_Y_WIDTH*4), CAN_X_WIDTH, CAN_Y_WIDTH,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "V+", 0, 0),


				CanvasStruct(musicCanvaces,  0,musicCanvaces + 10,
							&g_sKentec320x240x16_SSD2119, CAN_X_POS+CAN_X_WIDTH, 45+(CAN_Y_WIDTH*4), CAN_X_WIDTH, CAN_Y_WIDTH,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0),

				CanvasStruct(musicCanvaces, 0,musicCanvaces+11,
							&g_sKentec320x240x16_SSD2119, CAN_X_POS, 45+(CAN_Y_WIDTH*5), CAN_X_WIDTH, CAN_Y_WIDTH,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "V-", 0, 0),


				CanvasStruct(musicCanvaces,  0,0,
							&g_sKentec320x240x16_SSD2119, CAN_X_POS+CAN_X_WIDTH, 45+(CAN_Y_WIDTH*5), CAN_X_WIDTH, CAN_Y_WIDTH,
							CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
							UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " - ", 0, 0)

};

Z_MusicControl_Leaf_Ui::Z_MusicControl_Leaf_Ui() {
	// TODO Auto-generated constructor stub
	curPos = 0;
	amtControls = sizeof(musicCanvaces) / (sizeof(musicCanvaces[0])*2);
}

Z_MusicControl_Leaf_Ui::~Z_MusicControl_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}


void Z_MusicControl_Leaf_Ui::SetMusicControl_Ref(Z_MusicControl* ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	WidgetPaint((tWidget *)&musicName);


	PaintSelected();
}

void Z_MusicControl_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&musicCov);
	(**curNode).Show(UiVis);
}

void Z_MusicControl_Leaf_Ui::Up()
{
	CanvasFillColorSet(&(musicCanvaces[curPos*2]),UNSELCTED_PNT);
	CanvasFillColorSet(&(musicCanvaces[(curPos*2)+1]),UNSELCTED_PNT);
	if(curPos < (amtControls-1)) curPos++;
	else curPos = 0;

	PaintSelected();

}

void Z_MusicControl_Leaf_Ui::Down()
{
	CanvasFillColorSet(&(musicCanvaces[curPos*2]),UNSELCTED_PNT);
	CanvasFillColorSet(&(musicCanvaces[(curPos*2)+1]),UNSELCTED_PNT);
	if(curPos > 0) curPos--;
	else curPos = (amtControls-1);

	PaintSelected();

}

void Z_MusicControl_Leaf_Ui::Right()
{
	uint16_t retVal;


	if(curPos == 0)
	{
		retVal = myRef->AddSgndToPlay(1, ADD);
		UtilClass::UnsgndIntToStrng(&(playArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[1]), &(playArr[0]));

		retVal++;
		retVal = myRef->AddSgndToPause(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(pauseArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[3]), &(pauseArr[0]));

		retVal++;
		retVal = myRef->AddSgndToFw(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(fwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[5]), &(fwArr[0]));

		retVal++;
		retVal = myRef->AddSgndToBw(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(bwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[7]), &(bwArr[0]));

		retVal++;
		retVal = myRef->AddSgndToVup(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(vuArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[9]), &(vuArr[0]));

		retVal++;
		retVal = myRef->AddSgndToVdown(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(vdArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[11]), &(vdArr[0]));
	}
	if(curPos == 1)
	{
		retVal = myRef->AddSgndToPause(1, ADD);
		UtilClass::UnsgndIntToStrng(&(pauseArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[3]), &(pauseArr[0]));
	}
	if(curPos == 2)
	{
		retVal = myRef->AddSgndToFw(1, ADD);
		UtilClass::UnsgndIntToStrng(&(fwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[5]), &(fwArr[0]));
	}
	if(curPos == 3)
	{
		retVal = myRef->AddSgndToBw(1, ADD);
		UtilClass::UnsgndIntToStrng(&(bwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[7]), &(bwArr[0]));
	}
	if(curPos == 4)
	{
		retVal = myRef->AddSgndToVup(1, ADD);
		UtilClass::UnsgndIntToStrng(&(vuArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[9]), &(vuArr[0]));
	}
	if(curPos == 5)
	{
		retVal = myRef->AddSgndToVdown(1, ADD);
		UtilClass::UnsgndIntToStrng(&(vdArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[11]), &(vdArr[0]));
	}
	PaintSelected();
}

void Z_MusicControl_Leaf_Ui::Left()
{
	uint16_t retVal;

	if(curPos == 0)
	{
		retVal = myRef->AddSgndToPlay(-1, ADD);
		UtilClass::UnsgndIntToStrng(&(playArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[1]), &(playArr[0]));

		retVal++;
		retVal = myRef->AddSgndToPause(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(pauseArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[3]), &(pauseArr[0]));

		retVal++;
		retVal = myRef->AddSgndToFw(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(fwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[5]), &(fwArr[0]));

		retVal++;
		retVal = myRef->AddSgndToBw(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(bwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[7]), &(bwArr[0]));

		retVal++;
		retVal = myRef->AddSgndToVup(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(vuArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[9]), &(vuArr[0]));

		retVal++;
		retVal = myRef->AddSgndToVdown(retVal, SET);
		UtilClass::UnsgndIntToStrng(&(vdArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[11]), &(vdArr[0]));
	}
	if(curPos == 1)
	{
		retVal = myRef->AddSgndToPause(-1, ADD);
		UtilClass::UnsgndIntToStrng(&(pauseArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[3]), &(pauseArr[0]));
	}
	if(curPos == 2)
	{
		retVal = myRef->AddSgndToFw(-1, ADD);
		UtilClass::UnsgndIntToStrng(&(fwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[5]), &(fwArr[0]));
	}
	if(curPos == 3)
	{
		retVal = myRef->AddSgndToBw(-1, ADD);
		UtilClass::UnsgndIntToStrng(&(bwArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[7]), &(bwArr[0]));
	}
	if(curPos == 4)
	{
		retVal = myRef->AddSgndToVup(-1, ADD);
		UtilClass::UnsgndIntToStrng(&(vuArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[9]), &(vuArr[0]));
	}
	if(curPos == 5)
	{
		retVal = myRef->AddSgndToVdown(-1, ADD);
		UtilClass::UnsgndIntToStrng(&(vdArr[0]), retVal);
		CanvasTextSet(&(musicCanvaces[11]), &(vdArr[0]));
	}
	PaintSelected();
}

void Z_MusicControl_Leaf_Ui::PaintSelected()
{
	CanvasFillColorSet(&(musicCanvaces[curPos*2]),SELECTED_PNT);
	CanvasFillColorSet(&(musicCanvaces[(curPos*2)+1]),SELECTED_PNT);

	WidgetPaint((tWidget *)&(musicCanvaces[0]));
}
