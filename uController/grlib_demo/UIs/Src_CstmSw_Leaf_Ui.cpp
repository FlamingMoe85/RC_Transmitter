/*
 * Src_CstmSw_Leaf_Ui.cpp
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#include "Src_CstmSw_Leaf_Ui.h"
#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;
extern tCanvasWidget g_psPanels[];


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
static char posArr_1[3];
static char posArr_2[3];
static char posArr_3[3];
static char inArr_1[3];
static char inArr_2[3];
static char inArr_3[3];
static char valArr_1[6];
static char valArr_2[6];
static char valArr_3[6];
static char activePosArr[] = "   ";
static char outputArr[] = "      ";
static char modeArr[11];

extern void CstmSwAddInPrs(tWidget *psWidget);
extern void CstmSwDelInPrs(tWidget *psWidget);

Src_CstmSw_Leaf** myRef_C;

Canvas(srcCstmSwName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Custom Switch", 0, 0);
Canvas(srcCstmSwCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(srcCstmSwCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(actPosCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 190, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "-", 0, 0);

Canvas(outputCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 215, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " ", 0, 0);

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT		ClrOrange

tCanvasWidget rubricCanvas[] =
{
    CanvasStruct(0, 0,rubricCanvas+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Pos", 0, 0),
    CanvasStruct(rubricCanvas,  0,rubricCanvas + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "In", 0, 0),

    CanvasStruct(rubricCanvas, 0,rubricCanvas + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Val", 0, 0),

	CanvasStruct(rubricCanvas, 0,0,
				&g_sKentec320x240x16_SSD2119, 0, 90, 100, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Mode", 0, 0)
};

tCanvasWidget swPosCanvas[] =
{
    CanvasStruct(0, 0,swPosCanvas+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "1", 0, 0),

    CanvasStruct(swPosCanvas,  0,swPosCanvas + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "a", 0, 0),

    CanvasStruct(swPosCanvas, 0,swPosCanvas + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 90, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "A", 0, 0),

								    CanvasStruct(0, 0,swPosCanvas + 4,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 120, 50, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "2", 0, 0),

								    CanvasStruct(swPosCanvas,  0,swPosCanvas + 5,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 120, 50, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "b", 0, 0),

								    CanvasStruct(swPosCanvas, 0,swPosCanvas + 6,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 120, 110, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "B", 0, 0),


																    CanvasStruct(0, 0,swPosCanvas+7,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 150, 50, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "3", 0, 0),

																    CanvasStruct(swPosCanvas,  0,swPosCanvas + 8,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 150, 50, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "c", 0, 0),

																    CanvasStruct(swPosCanvas, 0,0,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 150, 110, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "C", 0, 0),

};

tPushButtonWidget cstmSwBtns[] =
{
		RectangularButtonStruct(0, 0, cstmSwBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 190, 100, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 UNSELCTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, "Add In", 0, 0, 0, 0, CstmSwAddInPrs),

						RectangularButtonStruct(cstmSwBtns, 0, 0,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 100, 190, 100, 50,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, "Del In", 0, 0, 0, 0, CstmSwDelInPrs)




};

Canvas(srcCstmSwValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 110, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);

Canvas(modeValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90+CAN_Y_WIDTH, 100, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);

Src_CstmSw_Leaf_Ui::Src_CstmSw_Leaf_Ui() {
	// TODO Auto-generated constructor stub
	myRef_C = &myRef;
	inSel = 0;
	column = 0;
	btnSel = 0;
}

Src_CstmSw_Leaf_Ui::~Src_CstmSw_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}

void Src_CstmSw_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	RemFcnBtns();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&srcCstmSwCov_1);
	WidgetPaint((tWidget *)&srcCstmSwCov_2);
	(**curNode).Show(UiVis);
}

void Src_CstmSw_Leaf_Ui::SetCstmSw_Ref(Src_CstmSw_Leaf *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&srcCstmSwCov_1);
	WidgetPaint((tWidget *)&srcCstmSwCov_2);
	WidgetPaint((tWidget *)&srcCstmSwName);
	WidgetPaint((tWidget *)&modeValue);
	//UtilClass::SgndIntToStrng(&(nameArr[0]), myRef->GetChnlVal());
	//CanvasTextSet(&srcCstmSwValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&srcCstmSwValue);
	WidgetPaint((tWidget *)&(rubricCanvas[0]));
	//
	Paint();
	ConFcnBtns();
}

void Src_CstmSw_Leaf_Ui::Up()
{
	Up(1);
}
void Src_CstmSw_Leaf_Ui::Up(int16_t val)
{
	if(column == 0)
	{
		if(inSel < myRef->GetAmtOfPairs()-1)inSel++;
		else  inSel = 0;
	}
	else if((column == 1) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToPairIn(inSel, val);
	}
	else if(myRef->GetAmtOfPairs()>0)
	{
		myRef->AddSgndToPairVal(inSel, val*VALUE_STEP_UINT);
	}
	Paint();
}

void Src_CstmSw_Leaf_Ui::Down()
{
	Down(-1);
}
void Src_CstmSw_Leaf_Ui::Down(int16_t val)
{
	if(column == 0)
	{
		if(inSel > 0)inSel--;
		else inSel = myRef->GetAmtOfPairs()-1;
	}
	else if((column == 1) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToPairIn(inSel, val );
	}
	else if(myRef->GetAmtOfPairs()>0)
	{
		myRef->AddSgndToPairVal(inSel, val * VALUE_STEP_UINT);
	}
	Paint();
}

void Src_CstmSw_Leaf_Ui::QuadEncNotify(int16_t val)
{
	if(val > 0)Up(val);
	else if(val < 0) Down(val);
}

void Src_CstmSw_Leaf_Ui::Right()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		btnSel++;
		if(btnSel >= 2)btnSel=0;
		RefreshButtons();
	}
	else
	{
		if(column < 2) column++;
		else column = 0;
		Paint();
	}
}

void Src_CstmSw_Leaf_Ui::Left()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel > 0)btnSel--;
		else btnSel=1;
		RefreshButtons();
	}
	else
	{
		if(column > 0) column--;
		else column = 2;
		Paint();
	}
}

void Src_CstmSw_Leaf_Ui::Grab()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel == 0)AddIn();
		if(btnSel == 1)DelIn();
	}
	else
	{
		myRef->CycleMode();
		PaintMode();
	}
}

void Src_CstmSw_Leaf_Ui::PaintMode()
{
	if(myRef->GetMode() == CONT_MODE)
	{
		modeArr[0] = 'C';
		modeArr[1] = 'o';
		modeArr[2] = 'n';
		modeArr[3] = 't';
		modeArr[4] = 'i';
		modeArr[5] = 'n';
		modeArr[6] = 'u';
	    modeArr[7] = 'o';
	    modeArr[8] = 'u';
		modeArr[9] = 's';
		modeArr[10] = 0;
	}
	else
	{
		modeArr[0] = 'P';
		modeArr[1] = 'u';
		modeArr[2] = 'l';
		modeArr[3] = 's';
		modeArr[4] = 'e';
		modeArr[5] = 0;

	}
	CanvasTextSet(&(modeValue), &(modeArr[0]));
	WidgetPaint((tWidget *)&(modeValue));
}

void Src_CstmSw_Leaf_Ui::Paint()
{
	uint16_t amtOfIns = myRef->GetAmtOfPairs();
	if(amtOfIns > 2)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_3[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1));
		CanvasTextSet(&(swPosCanvas[0]), &(posArr_3[0]));
		UtilClass::UnsgndIntToStrng(&(inArr_3[0]), myRef->AddSgndToPairIn(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1),0));
				CanvasTextSet(&(swPosCanvas[1]), &(inArr_3[0]));
				UtilClass::IntToPercStrng(&(valArr_3[0]), myRef->AddSgndToPairVal(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1),0),SIGNED);
				CanvasTextSet(&(swPosCanvas[2]), &(valArr_3[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvas[0]), " - ");
		CanvasTextSet(&(swPosCanvas[1]), " - ");
			CanvasTextSet(&(swPosCanvas[2]), " - ");
	}
	if(amtOfIns > 0)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_1[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0));
		CanvasTextSet(&(swPosCanvas[3]), &(posArr_1[0]));
		UtilClass::UnsgndIntToStrng(&(inArr_1[0]), myRef->AddSgndToPairIn(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0),0));
		CanvasTextSet(&(swPosCanvas[4]), &(inArr_1[0]));
		UtilClass::IntToPercStrng(&(valArr_1[0]), myRef->AddSgndToPairVal(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(swPosCanvas[5]), &(valArr_1[0]));

	}
	else
	{
		CanvasTextSet(&(swPosCanvas[3]), " - ");
		CanvasTextSet(&(swPosCanvas[4]), " - ");
		CanvasTextSet(&(swPosCanvas[5]), " - ");
	}
	if(amtOfIns > 1)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_2[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1));
		CanvasTextSet(&(swPosCanvas[6]), &(posArr_2[0]));
		UtilClass::UnsgndIntToStrng(&(inArr_2[0]), myRef->AddSgndToPairIn(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1),0));
				CanvasTextSet(&(swPosCanvas[7]), &(inArr_2[0]));
				UtilClass::IntToPercStrng(&(valArr_2[0]), myRef->AddSgndToPairVal(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1),0),SIGNED);
				CanvasTextSet(&(swPosCanvas[8]), &(valArr_2[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvas[6]), " - ");
		CanvasTextSet(&(swPosCanvas[7]), " - ");
		CanvasTextSet(&(swPosCanvas[8]), " - ");
	}

	if(column == 0)
	{
		CanvasFillColorSet(&(swPosCanvas[3]),SELECTED_PNT);
		CanvasFillColorSet(&(swPosCanvas[4]),UNSELCTED_PNT);
		CanvasFillColorSet(&(swPosCanvas[5]),UNSELCTED_PNT);
	}
	else if(column == 1)
	{
		CanvasFillColorSet(&(swPosCanvas[3]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvas[4]),SELECTED_PNT);
				CanvasFillColorSet(&(swPosCanvas[5]),UNSELCTED_PNT);
	}
	else
	{
		CanvasFillColorSet(&(swPosCanvas[3]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvas[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvas[5]),SELECTED_PNT);
	}
	WidgetPaint((tWidget *)&(swPosCanvas[0]));
}

void Src_CstmSw_Leaf_Ui::RepaintVal()
{
	UtilClass::UnsgndIntToStrng(&(activePosArr[0]),  myRef->GetPos());
	CanvasTextSet(&actPosCan, &(activePosArr[0]));
	WidgetPaint((tWidget *)&actPosCan);

	UtilClass::IntToPercStrng(&(outputArr[0]),  myRef->GetVal(), SIGNED);
		CanvasTextSet(&outputCan, &(outputArr[0]));
		WidgetPaint((tWidget *)&outputCan);
}

uint16_t Src_CstmSw_Leaf_Ui::GetItmSel()
{
	return 0;
}

uint16_t Src_CstmSw_Leaf_Ui::GetCanSel()
{
	return 0;
}

void Src_CstmSw_Leaf_Ui::RemFcnBtns()
{
	WidgetRemove((tWidget *)&cstmSwBtns);
}
void Src_CstmSw_Leaf_Ui::ConFcnBtns()
{
	WidgetPaint((tWidget *)cstmSwBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)cstmSwBtns);
}

void Src_CstmSw_Leaf_Ui::AddIn()
{
	myRef->AddChnlPair();
	Paint();
}

void Src_CstmSw_Leaf_Ui::DelIn()
{
	myRef->DelChnlPairAt(inSel);
	if((inSel >= myRef->GetAmtOfPairs()) && (inSel > 0))inSel--;
	Paint();
}

void Src_CstmSw_Leaf_Ui::RefreshButtons()
{
	for(unsigned int i=0; i<2; i++)
	{
		cstmSwBtns[i].ui32FillColor = UNSELCTED_PNT;
	}
	if(GetRotaryState() == ROTARY_IS_DOWN)cstmSwBtns[btnSel].ui32FillColor = SELECTED_PNT;
	WidgetPaint((tWidget *)&cstmSwBtns);
}
