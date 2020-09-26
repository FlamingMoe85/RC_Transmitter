/*
 * Calc_Quantizer_Leaf_UI.cpp
 *
 *  Created on: 30.03.2020
 *      Author: Justus
 */

#include "Calc_Quantizer_Leaf_UI.h"
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

static Calc_Quantizer_Leaf_UI* instPtr;

void QuantAddLevPrs(tWidget *psWidget);
void QuantAddDelPrs(tWidget *psWidget);

Canvas(clcQuantizerName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 120, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Quantizer", 0, 0);
Canvas(clcQuantCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(clcQuantCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(actPosCanQuant, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 190, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "-", 0, 0);

Canvas(outputCanQuant, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 215, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " ", 0, 0);

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT		ClrOrange

tCanvasWidget rubricCanvasQuant[] =
{
    CanvasStruct(0, 0,rubricCanvasQuant+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Pos", 0, 0),
    CanvasStruct(rubricCanvasQuant,  0,rubricCanvasQuant + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 45, 80, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Lev", 0, 0),

    CanvasStruct(rubricCanvasQuant, 0,0,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+130, 45, 80, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Val", 0, 0)
};

tCanvasWidget swPosCanvasQuant[] =
{
    CanvasStruct(0, 0,swPosCanvasQuant+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "1", 0, 0),

    CanvasStruct(swPosCanvasQuant,  0,swPosCanvasQuant + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 90, 80, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "a", 0, 0),

    CanvasStruct(swPosCanvasQuant, 0,swPosCanvasQuant + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+130, 90, 80, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "A", 0, 0),

								    CanvasStruct(0, 0,swPosCanvasQuant + 4,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 120, 50, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "2", 0, 0),

								    CanvasStruct(swPosCanvasQuant,  0,swPosCanvasQuant + 5,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 120, 80, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "b", 0, 0),

								    CanvasStruct(swPosCanvasQuant, 0,swPosCanvasQuant + 6,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+130, 120, 80, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "B", 0, 0),


																    CanvasStruct(0, 0,swPosCanvasQuant+7,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 150, 50, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "3", 0, 0),

																    CanvasStruct(swPosCanvasQuant,  0,swPosCanvasQuant + 8,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 150, 80, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "c", 0, 0),

																    CanvasStruct(swPosCanvasQuant, 0,0,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+130, 150, 80, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "C", 0, 0),

};

tPushButtonWidget quantBtns[] =
{
		RectangularButtonStruct(0, 0, quantBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 190, 100, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 UNSELCTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, "Add Level", 0, 0, 0, 0, QuantAddLevPrs),

						RectangularButtonStruct(quantBtns, 0, 0,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 100, 190, 100, 50,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, "Del Level", 0, 0, 0, 0, QuantAddDelPrs)




};

Canvas(srcQuantValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 110, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);

Calc_Quantizer_Leaf_UI::Calc_Quantizer_Leaf_UI() {
	// TODO Auto-generated constructor stub

}

Calc_Quantizer_Leaf_UI::~Calc_Quantizer_Leaf_UI() {
	// TODO Auto-generated destructor stub
}

void QuantAddLevPrs(tWidget *psWidget)
{
	instPtr->AddMark();
}

void QuantAddDelPrs(tWidget *psWidget)
{
	instPtr->AddMark();
}

void Calc_Quantizer_Leaf_UI::SetQuantizer_Ref(Calc_Quantizer_Leaf *ref)
{
	myRef = ref;
	instPtr = this;
	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&clcQuantCov_1);
	WidgetPaint((tWidget *)&clcQuantCov_2);
	WidgetPaint((tWidget *)&clcQuantizerName);
	WidgetPaint((tWidget *)&srcQuantValue);
	WidgetPaint((tWidget *)&(rubricCanvasQuant[0]));
	Paint();
	ConFcnBtns();
}

void Calc_Quantizer_Leaf_UI::RemFcnBtns()
{
	WidgetRemove((tWidget *)&quantBtns);
}

void Calc_Quantizer_Leaf_UI::ConFcnBtns()
{
	WidgetPaint((tWidget *)quantBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)quantBtns);
}


uint16_t Calc_Quantizer_Leaf_UI::GetItmSel()
{
	return 0;
}

uint16_t Calc_Quantizer_Leaf_UI::GetCanSel()
{
	return 0;
}

void Calc_Quantizer_Leaf_UI::AddMark()
{
	myRef->AddMark();
	Paint();
}

void Calc_Quantizer_Leaf_UI::DelMark()
{
	myRef->DelMark(inSel);
	if((inSel >= myRef->GetAmtOfPairs()) && (inSel > 0))inSel--;
	Paint();
}

void Calc_Quantizer_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	RemFcnBtns();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&clcQuantCov_1);
	WidgetPaint((tWidget *)&clcQuantCov_2);
	(**curNode).Show(UiVis);
}

void Calc_Quantizer_Leaf_UI::Up()
{
	Up(1);
}
void Calc_Quantizer_Leaf_UI::Up(int16_t val)
{
	if(column == 0)
	{
		if(inSel < myRef->GetAmtOfPairs()-1)inSel++;
		else  inSel = 0;
	}
	else if((column == 1) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToLevel(inSel, val);
	}
	else if(myRef->GetAmtOfPairs()>0)
	{
		myRef->AddSgndToLevelVal(inSel, val);
	}
	Paint();
}
void Calc_Quantizer_Leaf_UI::Down()
{
	Down(-1);
}
void Calc_Quantizer_Leaf_UI::Down(int16_t val)
{
	if(column == 0)
	{
		if(inSel > 0)inSel--;
		else inSel = myRef->GetAmtOfPairs()-1;
	}
	else if((column == 1) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToLevel(inSel, val);
	}
	else if(myRef->GetAmtOfPairs()>0)
	{
		myRef->AddSgndToLevelVal(inSel, val);
	}
	Paint();
}

void Calc_Quantizer_Leaf_UI::Right()
{
	if(column < 2) column++;
	else column = 0;
	Paint();
}

void Calc_Quantizer_Leaf_UI::Left()
{
	if(column > 0) column--;
	else column = 2;
	Paint();
}

void Calc_Quantizer_Leaf_UI::Grab()
{

}

void Calc_Quantizer_Leaf_UI::QuadEncNotify(int16_t val)
{
	if(val > 0)Up(val);
	else if(val < 0) Down(val);
}

void Calc_Quantizer_Leaf_UI::Paint()
{
	uint16_t amtOfIns = myRef->GetAmtOfPairs();
	if(amtOfIns > 2)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_3[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1));
		CanvasTextSet(&(swPosCanvasQuant[0]), &(posArr_3[0]));
		UtilClass::IntToPercStrng(&(inArr_3[0]), myRef->AddSgndToLevel(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuant[1]), &(inArr_3[0]));
		UtilClass::IntToPercStrng(&(valArr_3[0]), myRef->AddSgndToLevelVal(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuant[2]), &(valArr_3[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvasQuant[0]), " - ");
		CanvasTextSet(&(swPosCanvasQuant[1]), " - ");
			CanvasTextSet(&(swPosCanvasQuant[2]), " - ");
	}
	if(amtOfIns > 0)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_1[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0));
		CanvasTextSet(&(swPosCanvasQuant[3]), &(posArr_1[0]));
		UtilClass::IntToPercStrng(&(inArr_1[0]), myRef->AddSgndToLevel(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuant[4]), &(inArr_1[0]));
		UtilClass::IntToPercStrng(&(valArr_1[0]), myRef->AddSgndToLevelVal(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuant[5]), &(valArr_1[0]));

	}
	else
	{
		CanvasTextSet(&(swPosCanvasQuant[3]), " - ");
		CanvasTextSet(&(swPosCanvasQuant[4]), " - ");
		CanvasTextSet(&(swPosCanvasQuant[5]), " - ");
	}
	if(amtOfIns > 1)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_2[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1));
		CanvasTextSet(&(swPosCanvasQuant[6]), &(posArr_2[0]));
		UtilClass::IntToPercStrng(&(inArr_2[0]), myRef->AddSgndToLevel(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuant[7]), &(inArr_2[0]));
		UtilClass::IntToPercStrng(&(valArr_2[0]), myRef->AddSgndToLevelVal(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasQuant[8]), &(valArr_2[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvasQuant[6]), " - ");
		CanvasTextSet(&(swPosCanvasQuant[7]), " - ");
		CanvasTextSet(&(swPosCanvasQuant[8]), " - ");
	}

	if(column == 0)
	{
		CanvasFillColorSet(&(swPosCanvasQuant[3]),SELECTED_PNT);
		CanvasFillColorSet(&(swPosCanvasQuant[4]),UNSELCTED_PNT);
		CanvasFillColorSet(&(swPosCanvasQuant[5]),UNSELCTED_PNT);
	}
	else if(column == 1)
	{
		CanvasFillColorSet(&(swPosCanvasQuant[3]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuant[4]),SELECTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuant[5]),UNSELCTED_PNT);
	}
	else
	{
		CanvasFillColorSet(&(swPosCanvasQuant[3]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuant[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasQuant[5]),SELECTED_PNT);
	}
	WidgetPaint((tWidget *)&(swPosCanvasQuant[0]));
}

void Calc_Quantizer_Leaf_UI::RepaintVal()
{
	UtilClass::UnsgndIntToStrng(&(activePosArr[0]),  myRef->GetPos());
	CanvasTextSet(&actPosCanQuant, &(activePosArr[0]));
	WidgetPaint((tWidget *)&actPosCanQuant);

	UtilClass::IntToPercStrng(&(outputArr[0]),  myRef->GetVal(), SIGNED);
		CanvasTextSet(&outputCanQuant, &(outputArr[0]));
		WidgetPaint((tWidget *)&outputCanQuant);
}
