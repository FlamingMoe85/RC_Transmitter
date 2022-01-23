/*
 * Time_Blinker_Leaf_UI.cpp
 *
 *  Created on: 27.12.2019
 *      Author: Justus
 */

#include "Time_Blinker_Leaf_UI.h"
#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

#include "../../../share/Graph_App/Strct_PoolOwner_Node.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;
extern tCanvasWidget g_psPanels[];
//extern Graph_App_I* currentNode;

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
static char durArr_1[3];
static char durArr_2[3];
static char durArr_3[3];
static char valArr_1[6];
static char valArr_2[6];
static char valArr_3[6];

static Time_Blinker_Leaf_UI* instPtr;
//static char activePosArr[] = "   ";
//static char outputArr[] = "      ";

extern void BlinkerAddInPrs();
extern void BlinkerDelInPrs();
void CompPoolPrs(tWidget *psWidget);
void NewCompPrs(tWidget *psWidget);
void EnterTriggerPrs(tWidget *psWidget);

Time_Blinker_Leaf* myRef_C;

Canvas(blinkerName, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT, UNSELCTED_PNT, ClrGray, ClrWhite, &g_sFontCm22, "Blinker", 0, 0);
Canvas(blinkerCov_1, 0, 0, 0, &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, 220, 90, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
Canvas(blinkerCov_2, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 90, 320, 150, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0);
/*
Canvas(actPosCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 190, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
			UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "-", 0, 0);

Canvas(outputCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 200, 215, 110, 25, CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
		 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, " ", 0, 0);
*/
#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT		ClrOrange




tCanvasWidget rubricBlnkCanvas[] =
{
    CanvasStruct(0, 0,rubricBlnkCanvas+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Pos", 0, 0),
    CanvasStruct(rubricBlnkCanvas,  0,rubricBlnkCanvas + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 45, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Dur", 0, 0),

    CanvasStruct(rubricBlnkCanvas, 0,0,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 45, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Val", 0, 0)
};

tCanvasWidget blnkrPosCanvas[] =
{
    CanvasStruct(0, 0,blnkrPosCanvas+1,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "1", 0, 0),

    CanvasStruct(blnkrPosCanvas,  0,blnkrPosCanvas + 2,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 90, 50, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "a", 0, 0),

    CanvasStruct(blnkrPosCanvas, 0,blnkrPosCanvas + 3,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 90, 110, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "A", 0, 0),

								    CanvasStruct(0, 0,blnkrPosCanvas + 4,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 120, 50, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "2", 0, 0),

								    CanvasStruct(blnkrPosCanvas,  0,blnkrPosCanvas + 5,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 120, 50, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "b", 0, 0),

								    CanvasStruct(blnkrPosCanvas, 0,blnkrPosCanvas + 6,
								                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 120, 110, CAN_Y_WIDTH,
												 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
												 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "B", 0, 0),


																    CanvasStruct(0, 0,blnkrPosCanvas+7,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 150, 50, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "3", 0, 0),

																    CanvasStruct(blnkrPosCanvas,  0,blnkrPosCanvas + 8,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+50, 150, 50, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "c", 0, 0),

																    CanvasStruct(blnkrPosCanvas, 0,0,
																                 &g_sKentec320x240x16_SSD2119, CAN_X_POS+100, 150, 110, CAN_Y_WIDTH,
																				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
																				 				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "C", 0, 0),

};

tPushButtonWidget blinkerBtns[] =
{
		RectangularButtonStruct(0, 0, blinkerBtns+1,//myCanvacsesAdd+1,
	                 &g_sKentec320x240x16_SSD2119, 0, 120, 50, 50,
					 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
					 UNSELCTED_PNT,
					 UNSELCTED_PNT,
					 ClrGray, TEXT_COLR, &g_sFontCm22, "+", 0, 0, 0, 0, 0),//BlinkerAddInPrs),

						RectangularButtonStruct(blinkerBtns, 0, blinkerBtns+2,//myCanvacsesAdd+1,
					                 &g_sKentec320x240x16_SSD2119, 50, 120, 50, 50,
									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 UNSELCTED_PNT,
									 UNSELCTED_PNT,
									 ClrGray, TEXT_COLR, &g_sFontCm22, "-", 0, 0, 0, 0, 0),//BlinkerDelInPrs),

									 RectangularButtonStruct(blinkerBtns+1, 0, blinkerBtns+3,//myCanvacsesAdd+1,
									 					     &g_sKentec320x240x16_SSD2119, 0, 190, 100, 50,
									 						 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 						UNSELCTED_PNT,
									 						UNSELCTED_PNT,
									 						ClrGray, TEXT_COLR, &g_sFontCm22, "Comp Pool", 0, 0, 0, 0, 0),//CompPoolPrs),

									RectangularButtonStruct(blinkerBtns+2, 0, blinkerBtns+4,//myCanvacsesAdd+1,
															&g_sKentec320x240x16_SSD2119, 100, 190, 100, 50,
															CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
															UNSELCTED_PNT,
															UNSELCTED_PNT,
															ClrGray, TEXT_COLR, &g_sFontCm22, "New Compo", 0, 0, 0, 0, 0),//NewCompPrs),

									RectangularButtonStruct(blinkerBtns+3, 0, 0,//myCanvacsesAdd+1,
															&g_sKentec320x240x16_SSD2119, 200, 190, 100, 50,
															CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
															UNSELCTED_PNT,
															UNSELCTED_PNT,
															ClrGray, TEXT_COLR, &g_sFontCm22, "Trigger", 0, 0, 0, 0, 0)//EnterTriggerPrs)



};

Time_Blinker_Leaf_UI::Time_Blinker_Leaf_UI() {
	// TODO Auto-generated constructor stub
	btnSel = 0;
}

Time_Blinker_Leaf_UI::~Time_Blinker_Leaf_UI() {
	// TODO Auto-generated destructor stub
}

void Time_Blinker_Leaf_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	Leave();
	RemFcnBtns();
	(**curNode).Esc(curNode);
	WidgetPaint((tWidget *)&blinkerCov_1);
	WidgetPaint((tWidget *)&blinkerCov_2);
	(**curNode).Show(UiVis);
}

void Time_Blinker_Leaf_UI::SetTime_Blinker_Ref(Time_Blinker_Leaf *ref)
{
	myRef = ref;
	myRef_C = ref;
	instPtr = this;
	this->SetActUi(this->GetStackPos());
	Sign(this);
	WidgetPaint((tWidget *)&blinkerCov_1);
	WidgetPaint((tWidget *)&blinkerCov_2);
	WidgetPaint((tWidget *)&blinkerName);
	//UtilClass::SgndIntToStrng(&(nameArr[0]), myRef->GetChnlVal());
	//CanvasTextSet(&srcCstmSwValue, &(nameArr[0]));
	//WidgetPaint((tWidget *)&srcCstmSwValue);
	WidgetPaint((tWidget *)&(rubricBlnkCanvas[0]));
	//
	Paint();
	ConFcnBtns();
}

void Time_Blinker_Leaf_UI::SetCompPool(Strct_PoolOwner_Node* poolOwnRef)
{
	myPoolOwnerRef = poolOwnRef;
}

void Time_Blinker_Leaf_UI::EnterCompoPool()//(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	myPoolOwnerRef->SetEntry(
			myRef);
	(*(myRef->GetCurNodePtrLoc())) = (Graph_App_I*)myPoolOwnerRef;
	//currentNode = (Graph_App_I*)myPoolOwnerRef;

	RemFcnBtns();
	WidgetPaint((tWidget *)&blinkerCov_1);
	WidgetPaint((tWidget *)&blinkerCov_2);
	myPoolOwnerRef->Show();
}

void CompPoolPrs(tWidget *psWidget)
{
	instPtr->EnterCompoPool();
}

void NewCompPrs(tWidget *psWidget)
{
	myRef_C->NewTrigCompo();
}

void Time_Blinker_Leaf_UI::EnterTrigCompo()
{
	if(myRef->GetTrigCompo() != 0)
	{
		myRef->GetTrigCompo()->SetEntry(myRef);
		(*(myRef->GetCurNodePtrLoc())) = (Graph_App_I*)myRef->GetTrigCompo();
		//currentNode = (Graph_App_I*)myRef->GetTrigCompo();

		RemFcnBtns();
		WidgetPaint((tWidget *)&blinkerCov_1);
		WidgetPaint((tWidget *)&blinkerCov_2);

		myRef->GetTrigCompo()->Show(myRef->GetVisitor());
	}
}

void EnterTriggerPrs(tWidget *psWidget)
{
	instPtr->EnterTrigCompo();
}

void Time_Blinker_Leaf_UI::Up()
{
	Up(1);
}
void Time_Blinker_Leaf_UI::Up(int16_t val)
{
	if(column == 0)
	{
		if(inSel < myRef->GetAmtOfSlots()-1)inSel++;
		else  inSel = 0;
	}
	else if((column == 1) && (myRef->GetAmtOfSlots()>0))
	{
		myRef->AddSgndToSlotDur(inSel, val);
	}
	else if(myRef->GetAmtOfSlots()>0)
	{
		myRef->AddSgndToSlotVal(inSel, val*VALUE_STEP_UINT);
	}
	Paint();
}

void Time_Blinker_Leaf_UI::Down()
{
	Down(-1);
}
void Time_Blinker_Leaf_UI::Down(int16_t val)
{
	if(column == 0)
	{
		if(inSel > 0)inSel--;
		else inSel = myRef->GetAmtOfSlots()-1;
	}
	else if((column == 1) && (myRef->GetAmtOfSlots()>0))
	{
		myRef->AddSgndToSlotDur(inSel, val );
	}
	else if(myRef->GetAmtOfSlots()>0)
	{
		myRef->AddSgndToSlotVal(inSel, val * VALUE_STEP_UINT);
	}
	Paint();
}

void Time_Blinker_Leaf_UI::QuadEncNotify(int16_t val)
{
	if(val > 0)Up(val);
	else if(val < 0) Down(val);
}

void Time_Blinker_Leaf_UI::Right()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		btnSel++;
		if(btnSel >= 5)btnSel=0;
		RefreshButtons();
	}
	else
	{
		if(column < 2) column++;
		else column = 0;
		Paint();
	}
}

void Time_Blinker_Leaf_UI::Left()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel > 0)btnSel--;
		else btnSel=4;
		RefreshButtons();
	}
	else
	{
		if(column > 0) column--;
		else column = 2;
		Paint();
	}
}

void Time_Blinker_Leaf_UI::Grab()
{
	if(GetRotaryState() == ROTARY_IS_DOWN)
	{
		if(btnSel == 0)BlinkerAddInPrs();
		if(btnSel == 1)BlinkerDelInPrs();
		if(btnSel == 2)instPtr->EnterCompoPool();
		if(btnSel == 3)myRef->NewTrigCompo();
		if(btnSel == 4)instPtr->EnterTrigCompo();
	}
	else
	{

	}
}

void Time_Blinker_Leaf_UI::Paint()
{
	uint16_t amtOfIns = myRef->GetAmtOfSlots();
	if(amtOfIns > 2)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_3[0]), UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, -1));
		CanvasTextSet(&(blnkrPosCanvas[0]), &(posArr_3[0]));
		UtilClass::UnsgndIntToStrng(&(durArr_3[0]), myRef->AddSgndToSlotDur(UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, -1),0));
				CanvasTextSet(&(blnkrPosCanvas[1]), &(durArr_3[0]));
				UtilClass::IntToPercStrng(&(valArr_3[0]), myRef->AddSgndToSlotVal(UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, -1),0),SIGNED);
				CanvasTextSet(&(blnkrPosCanvas[2]), &(valArr_3[0]));
	}
	else
	{
		CanvasTextSet(&(blnkrPosCanvas[0]), " - ");
		CanvasTextSet(&(blnkrPosCanvas[1]), " - ");
			CanvasTextSet(&(blnkrPosCanvas[2]), " - ");
	}
	if(amtOfIns > 0)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_1[0]), UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, 0));
		CanvasTextSet(&(blnkrPosCanvas[3]), &(posArr_1[0]));
		UtilClass::UnsgndIntToStrng(&(durArr_1[0]), myRef->AddSgndToSlotDur(UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, 0),0));
		CanvasTextSet(&(blnkrPosCanvas[4]), &(durArr_1[0]));
		UtilClass::IntToPercStrng(&(valArr_1[0]), myRef->AddSgndToSlotVal(UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, 0),0),SIGNED);
		CanvasTextSet(&(blnkrPosCanvas[5]), &(valArr_1[0]));

	}
	else
	{
		CanvasTextSet(&(blnkrPosCanvas[3]), " - ");
		CanvasTextSet(&(blnkrPosCanvas[4]), " - ");
		CanvasTextSet(&(blnkrPosCanvas[5]), " - ");
	}
	if(amtOfIns > 1)
	{
		UtilClass::UnsgndIntToStrng(&(posArr_2[0]), UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, 1));
		CanvasTextSet(&(blnkrPosCanvas[6]), &(posArr_2[0]));
		UtilClass::UnsgndIntToStrng(&(durArr_2[0]), myRef->AddSgndToSlotDur(UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, 1),0));
				CanvasTextSet(&(blnkrPosCanvas[7]), &(durArr_2[0]));
				UtilClass::IntToPercStrng(&(valArr_2[0]), myRef->AddSgndToSlotVal(UtilClass::CatchWrap(myRef->GetAmtOfSlots(), inSel, 1),0),SIGNED);
				CanvasTextSet(&(blnkrPosCanvas[8]), &(valArr_2[0]));
	}
	else
	{
		CanvasTextSet(&(blnkrPosCanvas[6]), " - ");
		CanvasTextSet(&(blnkrPosCanvas[7]), " - ");
		CanvasTextSet(&(blnkrPosCanvas[8]), " - ");
	}

	if(column == 0)
	{
		CanvasFillColorSet(&(blnkrPosCanvas[3]),SELECTED_PNT);
		CanvasFillColorSet(&(blnkrPosCanvas[4]),UNSELCTED_PNT);
		CanvasFillColorSet(&(blnkrPosCanvas[5]),UNSELCTED_PNT);
	}
	else if(column == 1)
	{
		CanvasFillColorSet(&(blnkrPosCanvas[3]),UNSELCTED_PNT);
				CanvasFillColorSet(&(blnkrPosCanvas[4]),SELECTED_PNT);
				CanvasFillColorSet(&(blnkrPosCanvas[5]),UNSELCTED_PNT);
	}
	else
	{
		CanvasFillColorSet(&(blnkrPosCanvas[3]),UNSELCTED_PNT);
				CanvasFillColorSet(&(blnkrPosCanvas[4]),UNSELCTED_PNT);
				CanvasFillColorSet(&(blnkrPosCanvas[5]),SELECTED_PNT);
	}
	WidgetPaint((tWidget *)&(blnkrPosCanvas[0]));
}

void Time_Blinker_Leaf_UI::RepaintVal()
{
	/*
	UtilClass::UnsgndIntToStrng(&(activePosArr[0]),  myRef->GetPos());
	CanvasTextSet(&actPosCan, &(activePosArr[0]));
	WidgetPaint((tWidget *)&actPosCan);

	UtilClass::IntToPercStrng(&(outputArr[0]),  myRef->GetVal(), SIGNED);
		CanvasTextSet(&outputCan, &(outputArr[0]));
		WidgetPaint((tWidget *)&outputCan);+
		*/
}

uint16_t Time_Blinker_Leaf_UI::GetItmSel()
{
	return 0;
}

uint16_t Time_Blinker_Leaf_UI::GetCanSel()
{
	return 0;
}

void Time_Blinker_Leaf_UI::RemFcnBtns()
{
	WidgetRemove((tWidget *)&blinkerBtns);
}
void Time_Blinker_Leaf_UI::ConFcnBtns()
{
	WidgetPaint((tWidget *)blinkerBtns);
	WidgetAdd(WIDGET_ROOT, (tWidget *)blinkerBtns);
}

void Time_Blinker_Leaf_UI::AddIn()
{
	myRef->AddSlot();
	Paint();
}

void Time_Blinker_Leaf_UI::DelIn()
{
	myRef->DelSlotAt(inSel);
	if((inSel >= myRef->GetAmtOfSlots()) && (inSel > 0))inSel--;
	Paint();
}

void Time_Blinker_Leaf_UI::RefreshButtons()
{
	for(unsigned int i=0; i<5; i++)
	{
		blinkerBtns[i].ui32FillColor = UNSELCTED_PNT;
	}
	if(GetRotaryState() == ROTARY_IS_DOWN)blinkerBtns[btnSel].ui32FillColor = SELECTED_PNT;
	WidgetPaint((tWidget *)&blinkerBtns);
}

