/*
 * Quadlet.cpp
 *
 *  Created on: 31.10.2020
 *      Author: Justus
 */

#include "Quadlet.h"

#include "Quadlet.h"
#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;
extern tCanvasWidget g_psPanels[];


#define CAN_X_POS	0
#define CAN_X_WIDTH	200
#define CAN_Y_WIDTH	30
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)
#define NXT_X_WIDTH	24
#define NXT_Y_WIDTH NXT_X_WIDTH
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT	ClrOrange
#define TEXT_COLR		ClrWhite
static char posArrSSW_1[3];
static char posArrSSW_2[3];
static char posArrSSW_3[3];
static char inArrSSW_1[3];
static char inArrSSW_2[3];
static char inArrSSW_3[3];
static char valArrSSW_1pos[6];
static char valArrSSW_2pos[6];
static char valArrSSW_3pos[6];
static char valArrSSW_1neg[6];
static char valArrSSW_2neg[6];
static char valArrSSW_3neg[6];
static char activePosArrSSW[] = "   ";
static char outputArrSSWPos[] = "      ";
static char outputArrSSWNeg[] = "      ";
static char moduleName[16];
static char rubric_3_Name[6];
static char rubric_4_Name[6];

void QuadletAddInPrs();
void QuadletDelInPrs();

Canvas(srcQuadletName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Empty", 0, 0);
Canvas(srcQuadletCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 320, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(srcQuadletCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(actPosCanQuadlet, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 190, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "-", 0, 0);

Canvas(outputCanQuadletPos, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 100, 215, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " ", 0, 0);

Canvas(NegOutQuadletCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 215, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " ", 0, 0);

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT		ClrOrange

tCanvasWidget rubricCanvasQuadlet[] =
{
    CanvasStruct(0, 0,rubricCanvasQuadlet+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Pos", 0, 0),
    CanvasStruct(rubricCanvasQuadlet,  0,rubricCanvasQuadlet + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "In", 0, 0),

    CanvasStruct(rubricCanvasQuadlet, 0,rubricCanvasQuadlet + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Empty", 0, 0),

	CanvasStruct(rubricCanvasQuadlet, 0,0,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 45, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Empty", 0, 0)
};

tCanvasWidget swPosCanvasQuadlet[] =
{
    CanvasStruct(0, 0,swPosCanvasQuadlet+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "1", 0, 0),

    CanvasStruct(swPosCanvasQuadlet,  0,swPosCanvasQuadlet + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "a", 0, 0),

    CanvasStruct(swPosCanvasQuadlet, 0,swPosCanvasQuadlet + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 90, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "A", 0, 0),

	CanvasStruct(swPosCanvasQuadlet, 0,swPosCanvasQuadlet + 4,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 90, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "AA", 0, 0),

	CanvasStruct(swPosCanvasQuadlet, 0,swPosCanvasQuadlet + 5,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS, 120, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "2", 0, 0),

	CanvasStruct(swPosCanvasQuadlet,  0,swPosCanvasQuadlet + 6,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 120, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "b", 0, 0),

	CanvasStruct(swPosCanvasQuadlet, 0,swPosCanvasQuadlet + 7,
				 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 120, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "B", 0, 0),

	CanvasStruct(swPosCanvasQuadlet, 0,swPosCanvasQuadlet + 8,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 120, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "BB", 0, 0),


	CanvasStruct(swPosCanvasQuadlet, 0,swPosCanvasQuadlet+9,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS, 150, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "3", 0, 0),

	CanvasStruct(swPosCanvasQuadlet,  0,swPosCanvasQuadlet + 10,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 150, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "c", 0, 0),

	CanvasStruct(swPosCanvasQuadlet, 0,swPosCanvasQuadlet + 11,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 150, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "C", 0, 0),

	CanvasStruct(swPosCanvasQuadlet, 0,0,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 150, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "CC", 0, 0)

};

tPushButtonWidget addDelBtns[] =
{
		RectangularButtonStruct(0, 0, addDelBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 190, 50, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 UNSELCTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, "Add", 0, 0, 0, 0, 0),//QuadletAddInPrs),

						RectangularButtonStruct(addDelBtns, 0, 0,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 50, 190, 50, 50,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, "Del", 0, 0, 0, 0, 0)//QuadletDelInPrs)
};



I_Quadlet* cRef;
Quadlet* thisPointer;

Quadlet::Quadlet() {
	// TODO Auto-generated constructor stub
	thisPointer = this;
	inSel = 0;
	column = 0;
	btnSel = 0;
}

Quadlet::~Quadlet() {
	// TODO Auto-generated destructor stub
}

void Quadlet::OnRefSet()
{
	WidgetPaint((tWidget *)&srcQuadletCov_1);
	WidgetPaint((tWidget *)&srcQuadletCov_2);
	WidgetPaint((tWidget *)&srcQuadletName);
	//WidgetPaint((tWidget *)&calcScaleSwValue);
	WidgetPaint((tWidget *)&(rubricCanvasQuadlet[0]));
}

void QuadletAddInPrs(tWidget *psWidget)
{
		cRef->AddChnlPair();
		thisPointer->Paint();
}

void QuadletDelInPrs(tWidget *psWidget)
{
		cRef->DelChnlPairAt(thisPointer->GetInSel());
		thisPointer->CorrectInSel();
		thisPointer->Paint();
}

void Quadlet::CorrectInSel()
{
	if((inSel >= cRef->GetAmtOfPairs()) && (inSel > 0))inSel--;
}

uint16_t Quadlet::GetInSel()
{
	return inSel;
}

void Quadlet::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	RemFcnBtns();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&srcQuadletCov_1);
	WidgetPaint((tWidget *)&srcQuadletCov_2);
	(**curNode).Show(UiVis);
}

void Quadlet::SetCRef(I_Quadlet* cRefArg)
{
	cRef = cRefArg;
}

void Quadlet::SetModuleName(char* name, uint16_t length)
{
	unsigned int i;
	if(length > 15) length = 15;
	for(i=0; i<length; i++)
	{
		moduleName[i] = name[i];
	}
	moduleName[length] = 0;
	CanvasTextSet(&(srcQuadletName), &(moduleName[0]));
}

void Quadlet::SetRubric_3_Name(char* name, uint16_t length)
{
	unsigned int i;
	if(length > 5) length = 5;
	for(i=0; i<length; i++)
	{
		rubric_3_Name[i] = name[i];
	}
	rubric_3_Name[length] = 0;
	CanvasTextSet(&(rubricCanvasQuadlet[2]), &(rubric_3_Name[0]));
}

void Quadlet::SetRubric_4_Name(char* name, uint16_t length)
{
	unsigned int i;
	if(length > 5) length = 5;
	for(i=0; i<length; i++)
	{
		rubric_4_Name[i] = name[i];
	}
	rubric_4_Name[length] = 0;
	CanvasTextSet(&(rubricCanvasQuadlet[3]), &(rubric_4_Name[0]));
}

void Quadlet::Up()
{
	Up(1);
}
void Quadlet::Up(int16_t val)
{
	if(column == 0)
	{
		if(inSel < cRef->GetAmtOfPairs()-1)inSel++;
		else  inSel = 0;
	}
	else if((column == 1) && (cRef->GetAmtOfPairs()>0))
	{
		cRef->AddSgndToPairIn(inSel, val);
	}
	else if((column == 2) && (cRef->GetAmtOfPairs()>0))
	{
		cRef->AddSgndToPairValPos(inSel, val*VALUE_STEP_UINT);
	}
	else if((column == 3) && (cRef->GetAmtOfPairs()>0))
	{
		cRef->AddSgndToPairValNeg(inSel, val*VALUE_STEP_UINT);
	}
	Paint();
}

void Quadlet::Down()
{
	Down(-1);
}
void Quadlet::Down(int16_t val)
{
	if(column == 0)
	{
		if(inSel > 0)inSel--;
		else inSel = cRef->GetAmtOfPairs()-1;
	}
	else if((column == 1) && (cRef->GetAmtOfPairs()>0))
	{
		cRef->AddSgndToPairIn(inSel, val );
	}
	else if((column == 2) && (cRef->GetAmtOfPairs()>0))
	{
		cRef->AddSgndToPairValPos(inSel, val * VALUE_STEP_UINT);
	}
	else if((column == 3) && (cRef->GetAmtOfPairs()>0))
	{
		cRef->AddSgndToPairValNeg(inSel, val*VALUE_STEP_UINT);
	}
	Paint();
}

void Quadlet::QuadEncNotify(int16_t val)
{
	if(val > 0)Up(val);
	else if(val < 0) Down(val);
}

void Quadlet::Right()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel < 1)btnSel++;
		else btnSel = 0;
		RefreshButtons();
	}
	else
	{
		if(column < 3) column++;
		else column = 0;
		Paint();
	}
}

void Quadlet::Left()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel > 0)btnSel--;
		else btnSel = 1;
		RefreshButtons();
	}
	else
	{
		if(column > 0) column--;
		else column = 3;
		Paint();
	}
}


void Quadlet::Paint()
{
	uint16_t amtOfIns = cRef->GetAmtOfPairs();
	if(amtOfIns > 2)
	{
		UtilClass::UnsgndIntToStrng(&(posArrSSW_3[0]), UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, -1));
		CanvasTextSet(&(swPosCanvasQuadlet[0]), &(posArrSSW_3[0]));
		UtilClass::UnsgndIntToStrng(&(inArrSSW_3[0]), cRef->AddSgndToPairIn(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, -1),0));
		CanvasTextSet(&(swPosCanvasQuadlet[1]), &(inArrSSW_3[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_3pos[0]), cRef->AddSgndToPairValPos(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, -1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuadlet[2]), &(valArrSSW_3pos[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_3neg[0]), cRef->AddSgndToPairValNeg(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, -1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuadlet[3]), &(valArrSSW_3neg[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvasQuadlet[0]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[1]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[2]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[3]), " - ");
	}
	if(amtOfIns > 0)
	{
		UtilClass::UnsgndIntToStrng(&(posArrSSW_1[0]), UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 0));
		CanvasTextSet(&(swPosCanvasQuadlet[4]), &(posArrSSW_1[0]));
		UtilClass::UnsgndIntToStrng(&(inArrSSW_1[0]), cRef->AddSgndToPairIn(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 0),0));
		CanvasTextSet(&(swPosCanvasQuadlet[5]), &(inArrSSW_1[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_1pos[0]), cRef->AddSgndToPairValPos(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuadlet[6]), &(valArrSSW_1pos[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_1neg[0]), cRef->AddSgndToPairValNeg(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuadlet[7]), &(valArrSSW_1neg[0]));

	}
	else
	{
		CanvasTextSet(&(swPosCanvasQuadlet[4]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[5]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[6]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[7]), " - ");
	}
	if(amtOfIns > 1)
	{
		UtilClass::UnsgndIntToStrng(&(posArrSSW_2[0]), UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 1));
		CanvasTextSet(&(swPosCanvasQuadlet[8]), &(posArrSSW_2[0]));
		UtilClass::UnsgndIntToStrng(&(inArrSSW_2[0]), cRef->AddSgndToPairIn(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 1),0));
		CanvasTextSet(&(swPosCanvasQuadlet[9]), &(inArrSSW_2[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_2pos[0]), cRef->AddSgndToPairValPos(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuadlet[10]), &(valArrSSW_2pos[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_2neg[0]), cRef->AddSgndToPairValNeg(UtilClass::CatchWrap(cRef->GetAmtOfPairs(), inSel, 1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuadlet[11]), &(valArrSSW_2neg[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvasQuadlet[8]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[9]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[10]), " - ");
		CanvasTextSet(&(swPosCanvasQuadlet[11]), " - ");
	}

	if(column == 0)
	{
		CanvasFillColorSet(&(swPosCanvasQuadlet[4]),SELECTED_PNT);
		CanvasFillColorSet(&(swPosCanvasQuadlet[5]),UNSELCTED_PNT);
		CanvasFillColorSet(&(swPosCanvasQuadlet[6]),UNSELCTED_PNT);
		CanvasFillColorSet(&(swPosCanvasQuadlet[7]),UNSELCTED_PNT);
	}
	else if(column == 1)
	{
		CanvasFillColorSet(&(swPosCanvasQuadlet[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[5]),SELECTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[6]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[7]),UNSELCTED_PNT);
	}
	else if(column == 2)
	{
		CanvasFillColorSet(&(swPosCanvasQuadlet[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[5]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[6]),SELECTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[7]),UNSELCTED_PNT);
	}
	else if(column == 3)
	{
		CanvasFillColorSet(&(swPosCanvasQuadlet[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[5]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[6]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuadlet[7]),SELECTED_PNT);
	}
	WidgetPaint((tWidget *)&(swPosCanvasQuadlet[0]));
}

void Quadlet::RepaintVal()
{
	UtilClass::UnsgndIntToStrng(&(activePosArrSSW[0]),  cRef->GetPos());
	CanvasTextSet(&actPosCanQuadlet, &(activePosArrSSW[0]));
	WidgetPaint((tWidget *)&actPosCanQuadlet);

	/**/
	UtilClass::IntToPercStrng(&(outputArrSSWNeg[0]),  cRef->GetValNeg(), SIGNED);
		CanvasTextSet(&NegOutQuadletCan, &(outputArrSSWNeg[0]));
		WidgetPaint((tWidget *)&NegOutQuadletCan);

	UtilClass::IntToPercStrng(&(outputArrSSWPos[0]),  cRef->GetValPos(), SIGNED);
		CanvasTextSet(&outputCanQuadletPos, &(outputArrSSWPos[0]));
		WidgetPaint((tWidget *)&outputCanQuadletPos);


}

uint16_t Quadlet::GetItmSel()
{
	return 0;
}

uint16_t Quadlet::GetCanSel()
{
	return 0;
}

void Quadlet::RemFcnBtns()
{
	WidgetRemove((tWidget *)&addDelBtns);
}
void Quadlet::ConFcnBtns()
{
	WidgetPaint((tWidget *)addDelBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)addDelBtns);
}

void Quadlet::Grab()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel == 0)
		{
			cRef->AddChnlPair();
			thisPointer->Paint();
		}
		if(btnSel == 1)
		{
			cRef->DelChnlPairAt(thisPointer->GetInSel());
			thisPointer->CorrectInSel();
			thisPointer->Paint();
		}
	}
	else
	{

	}
}

void Quadlet::RefreshButtons()
{
	for(unsigned int i=0; i<2; i++)
	{
		addDelBtns[i].ui32FillColor = UNSELCTED_PNT;
	}
	if(GetRotaryState() == ROTARY_IS_DOWN)addDelBtns[btnSel].ui32FillColor = SELECTED_PNT;
	WidgetPaint((tWidget *)&addDelBtns);
}
