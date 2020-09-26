/*
 * Calc_ScaleSw_Leaf_Ui.cpp
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#include "Calc_ScaleSw_Leaf_Ui.h"
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

extern void ScaleSwAddInPrs(tWidget *psWidget);
extern void ScaleSwDelInPrs(tWidget *psWidget);

Calc_ScaleSw_Leaf** myRef_C;

Canvas(srcScaleSwName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Scale Switch", 0, 0);
Canvas(srcScaleSwCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 320, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(srcScaleSwCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);

Canvas(actPosCanSSW, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 190, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "-", 0, 0);

Canvas(outputCanSSWPos, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 100, 215, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " ", 0, 0);

Canvas(NegOutCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 215, 100, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " ", 0, 0);

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT		ClrOrange

tCanvasWidget rubricCanvasSSW[] =
{
    CanvasStruct(0, 0,rubricCanvasSSW+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Pos", 0, 0),
    CanvasStruct(rubricCanvasSSW,  0,rubricCanvasSSW + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "In", 0, 0),

    CanvasStruct(rubricCanvasSSW, 0,rubricCanvasSSW + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Pos %", 0, 0),

	CanvasStruct(rubricCanvasSSW, 0,0,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 45, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Neg %", 0, 0)
};

tCanvasWidget swPosCanvasSSW[] =
{
    CanvasStruct(0, 0,swPosCanvasSSW+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "1", 0, 0),

    CanvasStruct(swPosCanvasSSW,  0,swPosCanvasSSW + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "a", 0, 0),

    CanvasStruct(swPosCanvasSSW, 0,swPosCanvasSSW + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 90, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "A", 0, 0),

	CanvasStruct(swPosCanvasSSW, 0,swPosCanvasSSW + 4,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 90, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "AA", 0, 0),

	CanvasStruct(swPosCanvasSSW, 0,swPosCanvasSSW + 5,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS, 120, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "2", 0, 0),

	CanvasStruct(swPosCanvasSSW,  0,swPosCanvasSSW + 6,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 120, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "b", 0, 0),

	CanvasStruct(swPosCanvasSSW, 0,swPosCanvasSSW + 7,
				 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 120, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "B", 0, 0),

	CanvasStruct(swPosCanvasSSW, 0,swPosCanvasSSW + 8,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 120, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "BB", 0, 0),


	CanvasStruct(swPosCanvasSSW, 0,swPosCanvasSSW+9,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS, 150, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "3", 0, 0),

	CanvasStruct(swPosCanvasSSW,  0,swPosCanvasSSW + 10,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 150, 50, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "c", 0, 0),

	CanvasStruct(swPosCanvasSSW, 0,swPosCanvasSSW + 11,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 150, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "C", 0, 0),

	CanvasStruct(swPosCanvasSSW, 0,0,
				&g_sKentec320x240x16_SSD2119, CAN_X_POS+200, 150, 110, CAN_Y_WIDTH,
				CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "CC", 0, 0)

};

tPushButtonWidget scaleSwBtns[] =
{
		RectangularButtonStruct(0, 0, scaleSwBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 190, 50, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 UNSELCTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, "Add", 0, 0, 0, 0, ScaleSwAddInPrs),

						RectangularButtonStruct(scaleSwBtns, 0, 0,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 50, 190, 50, 50,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, "Del", 0, 0, 0, 0, ScaleSwDelInPrs)




};

Canvas(calcScaleSwValue, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 110, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "-", 0, 0);

Calc_ScaleSw_Leaf_Ui::Calc_ScaleSw_Leaf_Ui() {
	// TODO Auto-generated constructor stub
	myRef_C = &myRef;
	inSel = 0;
	column = 0;
}

Calc_ScaleSw_Leaf_Ui::~Calc_ScaleSw_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}

void Calc_ScaleSw_Leaf_Ui::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	RemFcnBtns();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&srcScaleSwCov_1);
	WidgetPaint((tWidget *)&srcScaleSwCov_2);
	(**curNode).Show(UiVis);
}

void Calc_ScaleSw_Leaf_Ui::SetScaleSw_Ref(Calc_ScaleSw_Leaf *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&srcScaleSwCov_1);
	WidgetPaint((tWidget *)&srcScaleSwCov_2);
	WidgetPaint((tWidget *)&srcScaleSwName);
	//UtilClass::SgndIntToStrng(&(nameArr[0]), myRef->GetChnlVal());
	//CanvasTextSet(&calcScaleSwValue, &(nameArr[0]));
	WidgetPaint((tWidget *)&calcScaleSwValue);
	WidgetPaint((tWidget *)&(rubricCanvasSSW[0]));
	//
	Paint();
	ConFcnBtns();
}

void Calc_ScaleSw_Leaf_Ui::Up()
{
	Up(1);
}
void Calc_ScaleSw_Leaf_Ui::Up(int16_t val)
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
	else if((column == 2) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToPairValPos(inSel, val*VALUE_STEP_UINT);
	}
	else if((column == 3) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToPairValNeg(inSel, val*VALUE_STEP_UINT);
	}
	Paint();
}

void Calc_ScaleSw_Leaf_Ui::Down()
{
	Down(-1);
}
void Calc_ScaleSw_Leaf_Ui::Down(int16_t val)
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
	else if((column == 2) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToPairValPos(inSel, val * VALUE_STEP_UINT);
	}
	else if((column == 3) && (myRef->GetAmtOfPairs()>0))
	{
		myRef->AddSgndToPairValNeg(inSel, val*VALUE_STEP_UINT);
	}
	Paint();
}

void Calc_ScaleSw_Leaf_Ui::QuadEncNotify(int16_t val)
{
	if(val > 0)Up(val);
	else if(val < 0) Down(val);
}

void Calc_ScaleSw_Leaf_Ui::Right()
{
	if(column < 3) column++;
	else column = 0;
	Paint();
}

void Calc_ScaleSw_Leaf_Ui::Left()
{
	if(column > 0) column--;
	else column = 3;
	Paint();
}

void Calc_ScaleSw_Leaf_Ui::Grab()
{

}

void Calc_ScaleSw_Leaf_Ui::Paint()
{
	uint16_t amtOfIns = myRef->GetAmtOfPairs();
	if(amtOfIns > 2)
	{
		UtilClass::UnsgndIntToStrng(&(posArrSSW_3[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1));
		CanvasTextSet(&(swPosCanvasSSW[0]), &(posArrSSW_3[0]));
		UtilClass::UnsgndIntToStrng(&(inArrSSW_3[0]), myRef->AddSgndToPairIn(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1),0));
		CanvasTextSet(&(swPosCanvasSSW[1]), &(inArrSSW_3[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_3pos[0]), myRef->AddSgndToPairValPos(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasSSW[2]), &(valArrSSW_3pos[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_3neg[0]), myRef->AddSgndToPairValNeg(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, -1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasSSW[3]), &(valArrSSW_3neg[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvasSSW[0]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[1]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[2]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[3]), " - ");
	}
	if(amtOfIns > 0)
	{
		UtilClass::UnsgndIntToStrng(&(posArrSSW_1[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0));
		CanvasTextSet(&(swPosCanvasSSW[4]), &(posArrSSW_1[0]));
		UtilClass::UnsgndIntToStrng(&(inArrSSW_1[0]), myRef->AddSgndToPairIn(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0),0));
		CanvasTextSet(&(swPosCanvasSSW[5]), &(inArrSSW_1[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_1pos[0]), myRef->AddSgndToPairValPos(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(swPosCanvasSSW[6]), &(valArrSSW_1pos[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_1neg[0]), myRef->AddSgndToPairValNeg(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(swPosCanvasSSW[7]), &(valArrSSW_1neg[0]));

	}
	else
	{
		CanvasTextSet(&(swPosCanvasSSW[4]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[5]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[6]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[7]), " - ");
	}
	if(amtOfIns > 1)
	{
		UtilClass::UnsgndIntToStrng(&(posArrSSW_2[0]), UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1));
		CanvasTextSet(&(swPosCanvasSSW[8]), &(posArrSSW_2[0]));
		UtilClass::UnsgndIntToStrng(&(inArrSSW_2[0]), myRef->AddSgndToPairIn(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1),0));
		CanvasTextSet(&(swPosCanvasSSW[9]), &(inArrSSW_2[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_2pos[0]), myRef->AddSgndToPairValPos(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasSSW[10]), &(valArrSSW_2pos[0]));
		UtilClass::IntToPercStrng(&(valArrSSW_2neg[0]), myRef->AddSgndToPairValNeg(UtilClass::CatchWrap(myRef->GetAmtOfPairs(), inSel, 1),0),SIGNED);
		CanvasTextSet(&(swPosCanvasSSW[11]), &(valArrSSW_2neg[0]));
	}
	else
	{
		CanvasTextSet(&(swPosCanvasSSW[8]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[9]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[10]), " - ");
		CanvasTextSet(&(swPosCanvasSSW[11]), " - ");
	}

	if(column == 0)
	{
		CanvasFillColorSet(&(swPosCanvasSSW[4]),SELECTED_PNT);
		CanvasFillColorSet(&(swPosCanvasSSW[5]),UNSELCTED_PNT);
		CanvasFillColorSet(&(swPosCanvasSSW[6]),UNSELCTED_PNT);
		CanvasFillColorSet(&(swPosCanvasSSW[7]),UNSELCTED_PNT);
	}
	else if(column == 1)
	{
		CanvasFillColorSet(&(swPosCanvasSSW[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[5]),SELECTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[6]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[7]),UNSELCTED_PNT);
	}
	else if(column == 2)
	{
		CanvasFillColorSet(&(swPosCanvasSSW[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[5]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[6]),SELECTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[7]),UNSELCTED_PNT);
	}
	else if(column == 3)
	{
		CanvasFillColorSet(&(swPosCanvasSSW[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[5]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[6]),UNSELCTED_PNT);
				CanvasFillColorSet(&(swPosCanvasSSW[7]),SELECTED_PNT);
	}
	WidgetPaint((tWidget *)&(swPosCanvasSSW[0]));
}

void Calc_ScaleSw_Leaf_Ui::RepaintVal()
{
	UtilClass::UnsgndIntToStrng(&(activePosArrSSW[0]),  myRef->GetPos());
	CanvasTextSet(&actPosCanSSW, &(activePosArrSSW[0]));
	WidgetPaint((tWidget *)&actPosCanSSW);

	/**/
	UtilClass::IntToPercStrng(&(outputArrSSWNeg[0]),  myRef->GetValNeg(), SIGNED);
		CanvasTextSet(&NegOutCan, &(outputArrSSWNeg[0]));
		WidgetPaint((tWidget *)&NegOutCan);

	UtilClass::IntToPercStrng(&(outputArrSSWPos[0]),  myRef->GetValPos(), SIGNED);
		CanvasTextSet(&outputCanSSWPos, &(outputArrSSWPos[0]));
		WidgetPaint((tWidget *)&outputCanSSWPos);


}

uint16_t Calc_ScaleSw_Leaf_Ui::GetItmSel()
{
	return 0;
}

uint16_t Calc_ScaleSw_Leaf_Ui::GetCanSel()
{
	return 0;
}

void Calc_ScaleSw_Leaf_Ui::RemFcnBtns()
{
	WidgetRemove((tWidget *)&scaleSwBtns);
}
void Calc_ScaleSw_Leaf_Ui::ConFcnBtns()
{
	WidgetPaint((tWidget *)scaleSwBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)scaleSwBtns);
}

void Calc_ScaleSw_Leaf_Ui::AddIn()
{
	myRef->AddChnlPair();
	Paint();
}

void Calc_ScaleSw_Leaf_Ui::DelIn()
{
	myRef->DelChnlPairAt(inSel);
	if((inSel >= myRef->GetAmtOfPairs()) && (inSel > 0))inSel--;
	Paint();
}
