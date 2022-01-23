//*****************************************************************************
//
// fonttest.c - Simple font testcase.
//
// Copyright (c) 2013-2015 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.2.111 of the EK-TM4C1294XL Firmware Package.
//
//*****************************************************************************

//#define PC
#define CONTROLLER
//#define BT_LINK
#define EEPROM_READ

#include "../../share/UIs/Ui_Visitor.h"
#include "../../share/Graph_App/Calc_Addition_Leaf.h"


#include "UIs/CalcAdditionLeafUI.h"
#include "UIs/CalcMultiplicationLeafUI.h"
#include "UIs/StrctChnlMngrNodeUI.h"
#include "UIs/StrctChnlNodeUI.h"
#include "UIs/StrctCompoNodeUI.h"
#include "UIs/StrctMultiSwNodeUI.h"
#include "UIs/Strct_CalcFactory_UI.h"
#include "UIs/Strct_PoolOwner_UI.h"
#include "UIs/Calc_uCAdc_Leaf_UI.h"
#include "UIs/Src_CstmSw_Leaf_Ui.h"
#include "UIs/Strct_TopMenue_Node_UI.h"
#include "UIs/Strct_SaveLoad_Node_UI.h"
#include "UIs/Src_InternTrim_Leaf_UI.h"
#include "UIs/Strct_Junc_Node_UI.h"
#include "UIs/TimeCalc_Ramp_Leaf_UI.h"
#include "UIs/Time_Blinker_Leaf_UI.h"
#include "UIs/Calc_ScaleSw_Leaf_Ui.h"
#include "UIs/Calc_Quantizer_Leaf_UI.h"
#include "UIs/Calc_DeadArea_Leaf_Ui.h"
#include "UIs/Calc_MinMaxLimit_Leaf_Ui.h"
#include "UIs/Calc_Expo1_Leaf_Ui.h"
#include "UIs/Calc_DynamicScale_Leaf_Ui.h"
#include "UIs/Time_Integrator_Leaf_Ui.h"
#include "../../share/Graph_App/Strct_PoolOwner_Node.h"


#include "UIs/Z_SystemConfig_Leaf_UI.h"
#include "UIs/Z_Wizard_Node_Ui.h"

#include "UIs/Wizards/Wizard_IntTrim_Ui.h"
#include "UIs/Wizards/Wizard_TwoChnlModl_Leaf_Ui.h"

#include "Storage/StorageHandler.h"
#include "Storage/ModelManager.h"

#include "../../share/Visitor_InternTrim.h"
#include "../../share/Notifier_InternTrimm.h"
#include "../../share/SystickNotifier.h"
#include "../../share/QuadEncNofityer.h"

#include "../../share/Graph_App/Strct_CalcFactory.h"

extern "C"
{
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/flash.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"
#include "driverlib/udma.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/eeprom.h"
#include "driverlib/qei.h"
#include "grlib/grlib.h"
#include "grlib/widget.h"
#include "grlib/canvas.h"
#include "grlib/checkbox.h"
#include "grlib/container.h"
#include "grlib/pushbutton.h"
#include "grlib/radiobutton.h"
#include "grlib/keyboard.h"
#include "grlib/slider.h"
#include "utils/ustdlib.h"
#include "drivers/Kentec320x240x16_ssd2119_8bit.h"
#include "drivers/touch.h"
#include "images.h"

#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "inc/tm4c1294ncpdt.h"
#include "driverlib/eeprom.h"

void PpmMatchIntHandler(void);
}



//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Graphics Library Demonstration (grlib_demo)</h1>
//!
//! This application provides a demonstration of the capabilities of the
//! TivaWare Graphics Library.  A series of panels show different features of
//! the library.  For each panel, the bottom provides a forward and back button
//! (when appropriate), along with a brief description of the contents of the
//! panel.
//!
//! The first panel provides some introductory text and basic instructions for
//! operation of the application.
//!
//! The second panel shows the available drawing primitives: lines, circles,
//! rectangles, strings, and images.
//!
//! The third panel shows the canvas widget, which provides a general drawing
//! surface within the widget hierarchy.  A text, image, and application-drawn
//! canvas are displayed.
//!
//! The fourth panel shows the check box widget, which provides a means of
//! toggling the state of an item.  Four check boxes are provided, with each
//! having a red ``LED'' to the right.  The state of the LED tracks the state
//! of the check box via an application callback.
//!
//! The fifth panel shows the container widget, which provides a grouping
//! construct typically used for radio buttons.  Containers with a title, a
//! centered title, and no title are displayed.
//!
//! The sixth panel shows the push button widget.  Two columns of push buttons
//! are provided; the appearance of each column is the same but the left column
//! does not utilize auto-repeat while the right column does.  Each push button
//! has a red ``LED'' to its left, which is toggled via an application callback
//! each time the push button is pressed.
//!
//! The seventh panel shows the radio button widget.  Two groups of radio
//! buttons are displayed, the first using text and the second using images for
//! the selection value.  Each radio button has a red ``LED'' to its right,
//! which tracks the selection state of the radio buttons via an application
//! callback.  Only one radio button from each group can be selected at a time,
//! though the radio buttons in each group operate independently.
//!
//! The eighth and final panel shows the slider widget.  Six sliders
//! constructed using the various supported style options are shown.  The
//! slider value callback is used to update two widgets to reflect the values
//! reported by sliders.  A canvas widget near the top right of the display
//! tracks the value of the red and green image-based slider to its left and
//! the text of the grey slider on the left side of the panel is update to show
//! its own value.  The slider on the right is configured as an indicator
//! which tracks the state of the upper slider and ignores user input.
//!
//! The LCD BoosterPack (EB-LM4F120-L35) should be installed on
//! BoosterPack 2 interface headers.
//
//*****************************************************************************
//
//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

//*****************************************************************************
//
// Gloal variable used to store the frequency of the system clock.
//
//*****************************************************************************
uint32_t g_ui32SysClock;
//extern "C" void TouchScreenInit(uint32_t ui32SysClock);
//*****************************************************************************
//
// The DMA control structure table.
//
//*****************************************************************************
#ifdef ewarm
#pragma data_alignment=1024
tDMAControlTable psDMAControlTable[64];
#elif defined(ccs)
//#pragma DATA_ALIGN(i16DMAControlTable, 1024)
#pragma DATA_ALIGN(1024)
tDMAControlTable psDMAControlTable[64];
#else
tDMAControlTable psDMAControlTable[64] __attribute__ ((aligned(1024)));
#endif

//*****************************************************************************
//
// Forward declarations for the globals required to define the widgets at
// compile-time.
//
//*****************************************************************************
void OnEnter(tWidget *psWidget);
void OnEsc(tWidget *psWidget);
void OnUp(tWidget *psWidget);
void OnDown(tWidget *psWidget);
void OnLeft(tWidget *psWidget);
void OnRight(tWidget *psWidget);
void OnGrab(tWidget *psWidget);

void AddCompPoolPrs(tWidget *psWidget);

void SavePrs(tWidget *psWidget);
void LoadPrs(tWidget *psWidget);
void FormatPrs();

Strct_CalcFactory GlobalModFactory;

unsigned int headerSend = 0, stopSend = 0, adcVals = 0, digVals = 0;
uint8_t fourAdcsSend[18], digsSend[5], sendTrig = 0;
uint32_t recChannels[7];
uint16_t nibleCntr, numCntr, msgLength, charCntr, amtRecValsTop;
char curRecChar;

float fourAdcs[12];
uint32_t fourAdcsRaw[4];
uint32_t fourAdcsOffset[8];
uint16_t externADCs[4];
uint16_t externADCsBT[4];
int externAdcCnt = 0;
int externAdcCntBT = 0;
unsigned int extAdcCnt = 0;
unsigned int extAdcCntBT = 0;
int16_t initialAdcRead = 0;

#define BT_START	192
#define BT_STOP		128
unsigned char btTx[14], btflag = 0;
unsigned int btSendCntr = 0;

#define DIG_BEGIN			128
#define DIG_END				128+32
#define ADC_BEGIN 			128 + 64
#define ADC_END 			128 + 64 + 32
#define MSG_AMT_REQ_BEG		64
#define MSG_AMT_REQ_END		64 + 32

#define EXT_INIT		2
#define EXT_DIG_REQ		0
#define EXT_ADC_REQ		1
#define EXT_BT_REQ		3

volatile uint16_t amtOfExtAdc = 0, amtOfExtDigs = 0, extMode = EXT_INIT, askForAdcFlag = 0;
#define RETRYTIME 50
volatile uint16_t retry = RETRYTIME + 1;


uint32_t digInArrBits;
unsigned int expanInByteCntr = 0;
unsigned int expanInByteCntrBT = 0;
uint16_t trimmDigBits = 0;
static volatile uint16_t trimPins = 0;
uint16_t guiRefreshCntr = 0;
static int16_t quadPos;
unsigned char menuDigs = 0, menuDigsOld = 0;
#define UP_MEN		1
#define DOWN_MEN	2
#define LEFT_MEN	4
#define RIGHT_MEN	8
#define GRAB_MEN	16
#define ENTER_MEN	64
#define	ESC_MEN		32
#define ROTARY_DOWN	128

extern tCanvasWidget g_psPanels[];

volatile uint32_t seperatorArr[8] = {400*120, 400*120, 400*120, 400*120, 400*120, 400*120, 400*120, 400*120};
volatile int32_t chnlValArr[8] = {1500*120, 1500*120, 1500*120, 1500*120, 1500*120, 1500*120, 1500*120, ((20000*120) - ((8*400*120) + (7*1500*120))) };
volatile uint32_t runTrigger = 1, runTriggerOld =0;


//*****************************************************************************
//
// The first panel, which contains introductory text explaining the
// application.
//
//*****************************************************************************
Canvas(g_sIntroduction, g_psPanels, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 0,
       320, 240, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, 0);


Canvas(dummyCan, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 220, 300, 140, CANVAS_STYLE_FILL, ClrYellow, 0, 0, 0, 0, 0, 0);

#define SLIDER_TEXT_VAL_INDEX   0
#define SLIDER_LOCKED_INDEX     2
#define SLIDER_CANVAS_VAL_INDEX 4

#define NUM_SLIDERS (sizeof(g_psSliders) / sizeof(g_psSliders[0]))

#define UNSELCTED_PNT 	ClrBlue
#define SELECTED_PNT	ClrOrange
#define TEXT_COLR		ClrWhite


 RectangularButton(saveLoadBtnsMain, 0, 0, 0,
									 					                 &g_sKentec320x240x16_SSD2119, 0, 130, 100, 50,
									 									 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
									 									 UNSELCTED_PNT,
									 									 UNSELCTED_PNT,
									 									 ClrGray, TEXT_COLR, &g_sFontCm22, "Form", 0, 0, 0, 0, 0);//FormatPrs);

/*
RectangularButton(upBtn, g_psPanels,  0, 0,  &g_sKentec320x240x16_SSD2119, 30, 0,
							30, 30, PB_STYLE_FILL, ClrWhite, ClrOrange, 0, 0,
							  0, 0, 0, 0, 0, 0,
                  OnUp);
RectangularButton(dwnBtn, g_psPanels, &upBtn, 0, &g_sKentec320x240x16_SSD2119, 30, 60,
							30, 30, PB_STYLE_FILL, ClrWhite, ClrOrange, 0, 0,
							  0, 0, 0, 0, 0, 0,
							  OnDown);
RectangularButton(lftBtn, g_psPanels, &dwnBtn, 0, &g_sKentec320x240x16_SSD2119, 0, 30,
							30, 30, PB_STYLE_FILL, ClrWhite, ClrOrange, 0, 0,
							  0, 0, 0, 0, 0, 0,
							  OnLeft);
RectangularButton(rgtBtn, g_psPanels, &lftBtn, 0, &g_sKentec320x240x16_SSD2119, 60, 30,
							30, 30, PB_STYLE_FILL, ClrWhite, ClrOrange, 0, 0,
							  0, 0, 0, 0, 0, 0,
							  OnRight);
RectangularButton(ntrBtn, g_psPanels, &rgtBtn, 0, &g_sKentec320x240x16_SSD2119, 0, 60,
							30, 30, PB_STYLE_FILL, ClrGreen, ClrOrange, 0, 0,
							  0, 0, 0, 0, 0, 0,
							  OnEnter);
RectangularButton(escBtn, g_psPanels, &ntrBtn, 0, &g_sKentec320x240x16_SSD2119, 60, 60,
					30, 30, PB_STYLE_FILL, ClrRed, ClrOrange, 0, 0,
				  0, 0, 0, 0, 0, 0,
				  OnEsc);
RectangularButton(grabBtn, g_psPanels, &escBtn, 0, &g_sKentec320x240x16_SSD2119, 30, 30,
					30, 30, PB_STYLE_FILL, ClrBlue, ClrOrange, 0, 0,
				  0, 0, 0, 0, 0, 0,
				  OnGrab);

*/

//*****************************************************************************
//
// An array of canvas widgets, one per panel.  Each canvas is filled with
// black, overwriting the contents of the previous panel.
//
//*****************************************************************************
tCanvasWidget g_psPanels[] =
{
    CanvasStruct(0, 0, 0/*&grabBtn*/, &g_sKentec320x240x16_SSD2119, 0, 0,
                 320, 240, CANVAS_STYLE_FILL, ClrCrimson, 0, 0, 0, 0, 0, 0),
};

//*****************************************************************************
//
// The number of panels.
//
//*****************************************************************************


#define NUM_PANELS              (sizeof(g_psPanels) / sizeof(g_psPanels[0]))




//*****************************************************************************
//
// The panel that is currently being displayed.
//
//*****************************************************************************
uint32_t g_ui32Panel;


//*****************************************************************************
//
// Handles paint requests for the primitives canvas widget.
//
//*****************************************************************************


//*****************************************************************************
//
// A simple demonstration of the features of the TivaWare Graphics Library.
//
//*****************************************************************************

Graph_App_I* currentNode;
Ui_Visitor UiVisitor;
Visitor_InternTrim VisitorInternTrim;
Notifier_InternTrimm NotifyerInternTrim;
SystickNotifier sysTickNoty;
QuadEncNofityer quadNoty;

Strct_ChnlMngr_Node_UI chnlMngrUi;
Strct_Chnl_Node_UI chnlUi;
Strct_Compo_Node_UI cmpoNodUi;
Calc_Addition_Leaf_UI addUi;
Calc_Multiplication_Leaf_UI mulUi;
StrctMultiSwNodeUI mltSwUi;
Strct_CalcFactory_UI calcFacUi;
Strct_PoolOwner_UI poolOwnUi;
Calc_uCAdc_Leaf_UI uCAdcUi;
Src_CstmSw_Leaf_Ui srcCstmSwUi;
Strct_TopMenue_Node_UI strctTopMenUi;
Strct_SaveLoad_Node_UI strctSaveLoadUi;
Src_InternTrim_Leaf_UI srcInternTrimUi;
Strct_Junc_Node_UI strctJuncUi;
TimeCalc_Ramp_Leaf_UI timeCalcRampUi;
Time_Blinker_Leaf_UI timeBlinkerUi;
Calc_ScaleSw_Leaf_Ui scaleSwUi;
Calc_Quantizer_Leaf_UI quantiUi;
Calc_DeadArea_Leaf_Ui deadSpanUi;
Calc_MinMaxLimit_Leaf_Ui limiterUi;
Z_SystemConfig_Leaf_UI sysConfUi;
Calc_Expo1_Leaf_Ui expo1Ui;
Calc_DynamicScale_Leaf_Ui dynSclUi;
Time_Integrator_Leaf_Ui integrUi;
Z_Wizard_Node_Ui wizardMenUi;
Wizard_IntTrim_Ui wizardIntTrimUi;
Wizard_TwoChnlModl_Leaf_Ui wizTwoChnlModlUi;

Ui_Identifier_I* uiIdArr[] = {&chnlMngrUi, &chnlUi, &cmpoNodUi, &addUi, &mulUi, &mltSwUi, &calcFacUi,
								&poolOwnUi, &uCAdcUi, &srcCstmSwUi, &strctTopMenUi, &strctSaveLoadUi,
								&srcInternTrimUi, &strctJuncUi, &timeCalcRampUi, &timeBlinkerUi,
								&scaleSwUi, &quantiUi, &deadSpanUi, &limiterUi, &sysConfUi, &expo1Ui,
								&dynSclUi, &integrUi, &wizardMenUi, &wizardIntTrimUi, &wizTwoChnlModlUi};

Calc_Addition_Leaf add;
Calc_Multiplication_Leaf mul;
Strct_ChnlMngr_Node rootNode;
Strct_Chnl_Node chnl;
Strct_Compo_Node cmpoNod;
Strct_MultSw_Node mltSwNod;
Strct_CalcFactory calcFac;
Strct_PoolOwner_Node poolOwn;
Calc_uCAdc_Leaf uCAdc;
Strct_TopMenue_Node topMen;
Strct_SaveLoad_Node saveLoad;
Z_SystemConfig_Leaf sysConf;
Z_Wizard_Node wizardMen;

uint16_t uiSel = 0;


void DisplUi(uint16_t uS)
{
	if( uS == 0)add.Show(&UiVisitor);
	if( uS == 1)mul.Show(&UiVisitor);
	if( uS == 2)rootNode.Show(&UiVisitor);
	if( uS == 3)chnl.Show(&UiVisitor);
	if( uS == 4)cmpoNod.Show(&UiVisitor);
	if( uS == 5)mltSwNod.Show(&UiVisitor);
	if( uS == 6)calcFac.Show(&UiVisitor);
	if( uS == 7)poolOwn.Show(&UiVisitor);
	if( uS == 8)uCAdc.Show(&UiVisitor);
}

void OnUp()
{
	uiIdArr[chnlMngrUi.GetActUi()]->Up();
}

void OnDown()
{
	uiIdArr[chnlMngrUi.GetActUi()]->Down();
}


void OnLeft()
{
	uiIdArr[chnlMngrUi.GetActUi()]->Left();
}
void OnRight()
{
	uiIdArr[chnlMngrUi.GetActUi()]->Right();
}

void OnEnter()
{
	//(*currentNode).Enter(&currentNode, uiIdArr[chnlMngrUi.GetActUi()]->GetItmSel());
	uiIdArr[chnlMngrUi.GetActUi()]->Enter(&currentNode, &UiVisitor);
	//(*currentNode).Show(&UiVisitor);
	if(chnlMngrUi.GetActUi() == 10)
	{
		WidgetAdd(WIDGET_ROOT, (tWidget *)&saveLoadBtnsMain);
		WidgetPaint((tWidget *)&saveLoadBtnsMain);
	}
	else
	{
		WidgetRemove((tWidget *)&saveLoadBtnsMain);
	}
}

void OnEsc()
{
	//(*currentNode).Esc(&currentNode);
	uiIdArr[chnlMngrUi.GetActUi()]->Esc(&currentNode, &UiVisitor);
	//currentNode->Show(&UiVisitor);
	if(chnlMngrUi.GetActUi() == 10)
		{
			WidgetAdd(WIDGET_ROOT, (tWidget *)&saveLoadBtnsMain);
			WidgetPaint((tWidget *)&saveLoadBtnsMain);
		}
	else
	{
		WidgetRemove((tWidget *)&saveLoadBtnsMain);
	}
}

void OnGrab()
{
	uiIdArr[chnlMngrUi.GetActUi()]->Grab();
}

void OnUp(tWidget *psWidget)
{
	OnUp();
	//uiIdArr[chnlMngrUi.GetActUi()]->Up();
}

void OnDown(tWidget *psWidget)
{
	OnDown();
	//uiIdArr[chnlMngrUi.GetActUi()]->Down();
}


void OnLeft(tWidget *psWidget)
{
	OnLeft();
	//uiIdArr[chnlMngrUi.GetActUi()]->Left();
}
void OnRight(tWidget *psWidget)
{
	OnRight();
	//uiIdArr[chnlMngrUi.GetActUi()]->Right();
}

void OnEnter(tWidget *psWidget)
{
	OnEnter();
	/*
	//(*currentNode).Enter(&currentNode, uiIdArr[chnlMngrUi.GetActUi()]->GetItmSel());
	uiIdArr[chnlMngrUi.GetActUi()]->Enter(&currentNode, &UiVisitor);
	//(*currentNode).Show(&UiVisitor);
	if(chnlMngrUi.GetActUi() == 10)
	{
		WidgetAdd(WIDGET_ROOT, (tWidget *)&saveLoadBtnsMain);
		WidgetPaint((tWidget *)&saveLoadBtnsMain);
	}
	else
	{
		WidgetRemove((tWidget *)&saveLoadBtnsMain);
	}
	*/
}

void OnEsc(tWidget *psWidget)
{
	OnEsc();
	/*
	//(*currentNode).Esc(&currentNode);
	uiIdArr[chnlMngrUi.GetActUi()]->Esc(&currentNode, &UiVisitor);
	//currentNode->Show(&UiVisitor);
	if(chnlMngrUi.GetActUi() == 10)
		{
			WidgetAdd(WIDGET_ROOT, (tWidget *)&saveLoadBtnsMain);
			WidgetPaint((tWidget *)&saveLoadBtnsMain);
		}
	else
	{
		WidgetRemove((tWidget *)&saveLoadBtnsMain);
	}
	*/
}

void OnGrab(tWidget *psWidget)
{
	OnGrab();
//	uiIdArr[chnlMngrUi.GetActUi()]->Grab();
}

void OnRotaryDown()
{
	uiIdArr[chnlMngrUi.GetActUi()]->RotaryDown(ROTARY_IS_DOWN);
}

void OnRotaryUp()
{
	uiIdArr[chnlMngrUi.GetActUi()]->RotaryDown(ROTARY_IS_UP);
}



void AddModPrs()
{
	cmpoNodUi.EnterModFac(&currentNode, &UiVisitor);
}

void CompPoolPrs_CompNode()
{
	cmpoNodUi.EnterCompoPool(&currentNode, &UiVisitor);
}

//void CompPoolPrs_MultSwNode(tWidget *psWidget)
void CompPoolPrs_MultSwNode()
{
	mltSwUi.EnterCompoPool(&currentNode, &UiVisitor);
}


//void CompPoolPrs_JuncNode(tWidget *psWidget)
void CompPoolPrs_JuncNode()
{
	strctJuncUi.EnterCompoPool(&currentNode, &UiVisitor);
}

void RemBtns_ItmSel()
{
	uiIdArr[chnlMngrUi.GetActUi()]->RemFcnBtns();
}

void ConBtns_ItmSel()
{
	uiIdArr[chnlMngrUi.GetActUi()]->ConFcnBtns();
}

//void DelPrs(tWidget *psWidget)
void DelPrs()
{
	uiIdArr[chnlMngrUi.GetActUi()]->DelSelItm();
}

//void DelJuncPrs(tWidget *psWidget)
void DelJuncPrs()
{
	uiIdArr[chnlMngrUi.GetActUi()]->DelSelItm();
}

void CstmSwAddInPrs(tWidget *psWidget)
{
	srcCstmSwUi.AddIn();
}
void CstmSwDelInPrs(tWidget *psWidget)
{
	srcCstmSwUi.DelIn();
}

void BlinkerAddInPrs()
{
	timeBlinkerUi.AddIn();
}

void BlinkerDelInPrs()
{
	timeBlinkerUi.DelIn();
}

void ReadEEPROM()
{
#ifdef EEPROM_READ
uint32_t eepromVal;
uint16_t upper16, lower16, k;
char valArr[6];

	for(uint16_t i=0; i<6144; i += 4)
	{
		EEPROMRead(&eepromVal, i, 4);
		lower16 = eepromVal;
		upper16 = eepromVal>>16;
		UtilClass::UnsgndIntToStrng(&(valArr[0]), upper16);
		k= 0;
		while(valArr[k] != '\0')
		{
			UARTCharPut(UART7_BASE, valArr[k]);
			k++;
		}
		UARTCharPut(UART7_BASE, '_');

		UtilClass::UnsgndIntToStrng(&(valArr[0]), lower16);
		k= 0;
		while(valArr[k] != '\0')
		{
			UARTCharPut(UART7_BASE, valArr[k]);
			k++;
		}
		UARTCharPut(UART7_BASE, ' ');
	}
#endif
}

StorageHandler storageHandler;
ModelManager modMan;

#define amtTestFigs 200
int16_t eeTestWrtArr[amtTestFigs];
int16_t eeTestRdArr[amtTestFigs];
uint32_t RdArr32[amtTestFigs];
char writeName[25];
char readName[100];

void SavePrs()
{
	storageHandler.NewAccessStrobe();
	uint16_t compoNodes;
	compoNodes = cmpoNod.GetPoolLst()->Count();
	for(uint16_t i=0; i<compoNodes; i++)
	{
		cmpoNod.GetPoolLst()->At(i)->ClearSerFlag();
	}

	strctSaveLoadUi.SaveMod();
	rootNode.Serialize(&modMan);
	storageHandler.FinalSaveStrobe();
	strctSaveLoadUi.ItemSel(strctSaveLoadUi.GetItmSel(),1);
}
void LoadPrs()
{
	char dummyName[20];
	modMan.SetCurModByNmbr(strctSaveLoadUi.GetItmSel());
	SysCtlReset();
}


void AutoLoad()
{
	char dummyName[20];
static volatile uint32_t amtMs, modNmbr;

amtMs = modMan.GetAmtOfModels();
modNmbr = modMan.GetCurModNmbr();

	if(modMan.GetAmtOfModels() > modMan.GetCurModNmbr())
	{
		modMan.SetCurModByNmbr(modMan.GetCurModNmbr());
		modMan.GetNameOfModel(&(dummyName[0]),modMan.GetCurModNmbr());
		rootNode.Deserialize(&modMan);
	}
}

void FormatPrs()
{
	storageHandler.Format();
}

void DelModPrs()
{
	modMan.DelSelctdMod(strctSaveLoadUi.GetItmSel());
	strctSaveLoadUi.ItemSel(strctSaveLoadUi.GetItmSel(),1);
}


void ExportPrs()
{
	void ReadEEPROM();
}
void ImportPrs()
{

}

void NullArr(char *arr, int length)
{
	for(uint16_t i=0; i<length; i++)
	{
		arr[i] = 'a';
	}
}

void CheckIntToAscConv()
{
	char valArr[6];
	uint16_t k;

	for(uint16_t val = 32766; val<32770; val++)
	{
		UtilClass::UnsgndIntToStrng(&(valArr[0]), val);
		k= 0;
		while(valArr[k] != '\0')
		{
			UARTCharPut(UART7_BASE, valArr[k]);
			k++;
		}
		UARTCharPut(UART7_BASE, '\0');
	}
}

int
main(void)
 {
	char strngArr[10];
	uint32_t tmpPins;

	poolOwn.SetUiVisitor(&UiVisitor);
    tContext sContext;
    cmpoNodUi.SetCompPool(&poolOwn);
    mltSwUi.SetCompPool(&poolOwn);
    strctJuncUi.SetCompPool(&poolOwn);
    timeBlinkerUi.SetCompPool(&poolOwn);
    expo1Ui.SetCompPool(&poolOwn);
    dynSclUi.SetCompPool(&poolOwn);
    VisitorInternTrim.SetTrimNotfier(&NotifyerInternTrim);



    for(int16_t i=0; i<amtTestFigs ;i++)
    {

    	if((i & 1)==1) eeTestWrtArr[i] = (i);
    	else eeTestWrtArr[i] = i;
    	eeTestRdArr[i] = 4321;
    /*	writeName[i] = ('A' + i);
    	readName[i] = 0;*/
    }
   // if(amtTestFigs < 20)writeName[amtTestFigs] = 0;
    modMan.SetMemHandler(&storageHandler);
    saveLoad.SetModMngr(&modMan);
    //
    // The FPU should be enabled because some compilers will use floating-
    // point registers, even for non-floating-point code.  If the FPU is not
    // enabled this will cause a fault.  This also ensures that floating-
    // point operations could be added to this application and would work
    // correctly and use the hardware floating-point unit.  Finally, lazy
    // stacking is enabled for interrupt handlers.  This allows floating-
    // point instructions to be used within interrupt handlers, but at the
    // expense of extra stack usage.
    //
    FPUEnable();
    FPULazyStackingEnable();

    //
    // Run from the PLL at 120 MHz.
    //
    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL |
                                             SYSCTL_CFG_VCO_480), 120000000);

    //
    // Initialize the display driver.
    //
     Kentec320x240x16_SSD2119Init(g_ui32SysClock);

    //
    // Initialize the graphics context.
    //
     GrContextInit(&sContext, &g_sKentec320x240x16_SSD2119);



    //
    // Configure and enable uDMA
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);
    SysCtlDelay(10);
    uDMAControlBaseSet(&psDMAControlTable[0]);
    uDMAEnable();

    SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0); // EEPROM activate
        EEPROMInit(); // EEPROM start
    //
    // Initialize the touch screen driver and have it route its messages to the
    // widget tree.
    //
     TouchScreenInit(g_ui32SysClock);
     TouchScreenCallbackSet(WidgetPointerMessage);

    //
    // Add the first panel to the widget tree.
    //
    g_ui32Panel = 0;
     WidgetAdd(WIDGET_ROOT, (tWidget *)g_psPanels);


    //
    // Issue the initial paint request to the widgets.
    //
     WidgetPaint(WIDGET_ROOT);
    UiVisitor.SetCalcAdd_UiRef(&addUi);
    UiVisitor.SetCalcMult_UiRef(&mulUi);
	UiVisitor.SetChnl_UiRef(&chnlUi);
	UiVisitor.SetChnl_UiRef(&chnlMngrUi);
	UiVisitor.SetCompNodeUiRef(&cmpoNodUi);
	UiVisitor.SetMultSw_UiRef(&mltSwUi);
	UiVisitor.SetCalcFac_UiRef(&calcFacUi);
	UiVisitor.SetPoolOwn_UiRef(&poolOwnUi);
	UiVisitor.SetuCAdc_UiRef(&uCAdcUi);
	UiVisitor.SetCstmSw_UiRef(&srcCstmSwUi);
	UiVisitor.SetTopMen_UiRef(&strctTopMenUi);
	UiVisitor.SetSaveLoad_UiRef(&strctSaveLoadUi);
	UiVisitor.SetInternTrim_UiRef(&srcInternTrimUi);
	UiVisitor.SetJunc_UiRef(&strctJuncUi);
	UiVisitor.SetRamp_UiRef(&timeCalcRampUi);
	UiVisitor.SetBlinker_UiRef(&timeBlinkerUi);
	UiVisitor.SetScaleSwitch_UiRef(&scaleSwUi);
	UiVisitor.SetQuanti_UiRef(&quantiUi);
	UiVisitor.SetDeadSpanUiRef(&deadSpanUi);
	UiVisitor.SetLimiter_UiRef(&limiterUi);
	UiVisitor.SetSysConf_UiRef(&sysConfUi);
	UiVisitor.SetExpo1_UiRef(&expo1Ui);
	UiVisitor.SetDynScale_UiRef(&dynSclUi);
	UiVisitor.SetIntegrator_UiRef(&integrUi);
	UiVisitor.SetWizard_UiRef(&wizardMenUi);
	UiVisitor.SetIntTrimWizard_UiRef(&wizardIntTrimUi);
	UiVisitor.SetIntTrimWizard_UiRef(&wizTwoChnlModlUi);

	Graph_App_I* tmpNamingPtr;

	rootNode.RunKindaConst();

	    rootNode.GetChildList()->AddEnd(new Strct_Chnl_Node);
	    rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->FillNameArray(rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->GetNameArr(), "Channel 1", 9);

	    rootNode.GetChildList()->AddEnd(new Strct_Chnl_Node);
	    rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->FillNameArray(rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->GetNameArr(), "Channel 2", 9);

	    rootNode.GetChildList()->AddEnd(new Strct_Chnl_Node);
	    rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->FillNameArray(rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->GetNameArr(), "Channel 3", 9);

	    rootNode.GetChildList()->AddEnd(new Strct_Chnl_Node);
	    rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->FillNameArray(rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->GetNameArr(), "Channel 4", 9);

	    rootNode.GetChildList()->AddEnd(new Strct_Chnl_Node);
	    rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->FillNameArray(rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->GetNameArr(), "Channel 5", 9);

	    rootNode.GetChildList()->AddEnd(new Strct_Chnl_Node);
	    rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->FillNameArray(rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->GetNameArr(), "Channel 6", 9);

	    rootNode.GetChildList()->AddEnd(new Strct_Chnl_Node);
	    rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->FillNameArray(rootNode.GetChildList()->At(rootNode.GetChildList()->Count()-1)->GetNameArr(), "Channel 7", 9);

	    topMen.GetChildList()->AddEnd(&rootNode);
	    topMen.GetChildList()->AddEnd(&saveLoad);
	    topMen.GetChildList()->AddEnd(&sysConf);
	    topMen.GetChildList()->AddEnd(&wizardMen);

	    currentNode = &topMen;//rootNode;
 	    currentNode->Show(&UiVisitor);

		ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	    ROM_GPIODirModeSet(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);

	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	    //ROM_GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_MODE_IN);
	    //MAP_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);


	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	    /*
	    ROM_GPIODirModeSet(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);
	    */

	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	    ROM_GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);

		ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	    ROM_GPIODirModeSet(GPIO_PORTG_BASE, GPIO_PIN_0, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTG_BASE, GPIO_PIN_0, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);

	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
	    ROM_GPIODirModeSet(GPIO_PORTH_BASE, GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTH_BASE, GPIO_PIN_2 | GPIO_PIN_3, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);
	    ROM_GPIODirModeSet(GPIO_PORTH_BASE, GPIO_PIN_2 , GPIO_DIR_MODE_OUT);
	    	    MAP_GPIOPadConfigSet(GPIO_PORTH_BASE,  GPIO_PIN_2 , GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD);


	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
	    ROM_GPIODirModeSet(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);

	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
	    ROM_GPIODirModeSet(GPIO_PORTK_BASE, GPIO_PIN_0 | GPIO_PIN_3, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTK_BASE, GPIO_PIN_0 | GPIO_PIN_3, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);

	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	    ROM_GPIODirModeSet(GPIO_PORTL_BASE, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTL_BASE, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);



	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
	    ROM_GPIODirModeSet(GPIO_PORTM_BASE, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTM_BASE, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);



	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
	    ROM_GPIODirModeSet(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_MODE_IN);
	    MAP_GPIOPadConfigSet(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPD);

	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
	    ROM_GPIODirModeSet(GPIO_PORTP_BASE, GPIO_PIN_2 , GPIO_DIR_MODE_OUT);
	    MAP_GPIOPadConfigSet(GPIO_PORTP_BASE,  GPIO_PIN_2 , GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD);

	                SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

	                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	                GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
	                ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 2);
	                ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH0);
	                ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_CH1);
	                ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_CH2);
	                ADCSequenceStepConfigure(ADC0_BASE, 1, 3, ADC_CTL_CH3|ADC_CTL_IE|ADC_CTL_END);
	                ADCSequenceEnable(ADC0_BASE, 1);

	                /**/
	                ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

	                               GPIOPinConfigure(GPIO_PA0_U0RX);
	                               GPIOPinConfigure(GPIO_PA1_U0TX);
	                               ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	                               ROM_UARTConfigSetExpClk(UART0_BASE, g_ui32SysClock, 9600,
	                                                       (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
	                                                        UART_CONFIG_PAR_NONE));

	                ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);

	                	                               GPIOPinConfigure(GPIO_PC4_U7RX);
	                	                               GPIOPinConfigure(GPIO_PC5_U7TX);
	                	                               ROM_GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
	                	                               ROM_UARTConfigSetExpClk(UART7_BASE, g_ui32SysClock, 115200,
	                	                                                       (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
	                	                                                        UART_CONFIG_PAR_NONE));
	                               //ROM_IntEnable(INT_UART0);
	                               //ROM_UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);



	                               SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
	                               UARTFIFOEnable(UART5_BASE);
	                               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	                               GPIOPinConfigure(GPIO_PC6_U5RX);
	                               GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_6, GPIO_STRENGTH_6MA, GPIO_PIN_TYPE_STD_WPU);
	                                  GPIOPinConfigure(GPIO_PC7_U5TX);
	                                  GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	                                  UARTConfigSetExpClk(UART5_BASE, g_ui32SysClock, 9600,//38400,
	                                                              (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
	                                                               UART_CONFIG_PAR_NONE));
	                                  //IntEnable(INT_UART5);
	                                  //UARTIntEnable(UART5_BASE, UART_INT_RX);// | UART_INT_RT);
	                                      //UARTFIFODisable(UART5_BASE);
	                                      UARTFIFOLevelSet(UART5_BASE, 0x00000000, 0x00000000);

	                                      ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	                                      	    ROM_GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_2,  GPIO_DIR_MODE_IN);
	                                      	    MAP_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


	                                      	MAP_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_3, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
	                                       GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 0);
/**/
	                                   	GPIOPinConfigure(GPIO_PL1_PHA0);
	                                   	GPIOPinConfigure(GPIO_PL2_PHB0);
	                                   	SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
	                                   	GPIOPinTypeQEI(GPIO_PORTL_BASE, GPIO_PIN_1|GPIO_PIN_2);
	                                   	QEIConfigure(QEI0_BASE, QEI_CONFIG_CAPTURE_A_B | QEI_CONFIG_QUADRATURE, 10000);
	                                   	QEIEnable(QEI0_BASE);
	                                   	QEIPositionSet(QEI0_BASE, 5000);

	                                       SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	                                       	                               TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);//TIMER_CFG_SPLIT_PAIR |TIMER_CFG_A_PWM);
	                                       	                               TimerUpdateMode(TIMER0_BASE, TIMER_A, TIMER_UP_LOAD_TIMEOUT);
	                                       	                               /*tmp = HWREG(TIMER0_BASE + 0x00000004);
	                                       	                               tmp |= 256;
	                                       	                               HWREG(TIMER0_BASE + 0x00000004) = tmp;*/
	                                       	                               TimerMatchSet(TIMER0_BASE, TIMER_A, 2000);//seperatorArr[0]);
	                                       	                               TimerLoadSet(TIMER0_BASE, TIMER_A, 4000);//seperatorArr[0]+chnlValArr[0]);
	                                       	                               TimerEnable(TIMER0_BASE, TIMER_A);
	                                       	                               IntEnable(INT_TIMER0A);
	                                       	                               	                               TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);//TIMER_TIMA_MATCH);//
	                                       	                               	                               IntMasterEnable();

	 menuDigsOld = (GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1));
	 menuDigsOld = menuDigsOld << 4;
	 menuDigs = menuDigsOld;
	//if((SysCtlResetCauseGet() & SYSCTL_CAUSE_SW) == SYSCTL_CAUSE_SW)
    if((menuDigsOld & GRAB_MEN) != GRAB_MEN)
	{
		//SysCtlResetCauseClear(SYSCTL_CAUSE_SW | SYSCTL_CAUSE_POR);
		AutoLoad();
	}
/*
	else if((SysCtlResetCauseGet() & SYSCTL_CAUSE_POR) == SYSCTL_CAUSE_POR)
    {
          SysCtlResetCauseClear(SYSCTL_CAUSE_SW | SYSCTL_CAUSE_POR);
          AutoLoad();
    }
*/

	//ReadEEPROM();
	//CheckIntToAscConv();

    while(1)
    {

    	if((askForAdcFlag == 1) && (retry > RETRYTIME))
    	{
    		retry = 0;
    		if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_2))
    		{
    			askForAdcFlag = 0;
    			UARTCharPut(UART5_BASE, ADC_END);
    		}
    	}
        //
        // Process any messages in the widget message queue.
        //
#ifdef CONTROLLER
WidgetMessageQueueProcess();
#endif
#ifdef PC
         if(sendTrig == 1)
         {
        	 bool tmpBool = true;

        	 if(headerSend == 0)
        	 {
        		 stopSend = 0;
        		 if(ROM_UARTCharPutNonBlocking(UART7_BASE, 2) == true)
        		 {
        			 headerSend = 1;
        		 }
        	 }
        	 if((headerSend == 1) && (adcVals < 8))
        	 {
        		 while((tmpBool == true) && (adcVals < 8))
        		 {
        			 tmpBool = ROM_UARTCharPutNonBlocking(UART7_BASE, fourAdcsSend[adcVals]);
        			 if(tmpBool == true)
        			 {
        				 adcVals++;
        			 }
        		 }
        	 }
        	 if((adcVals == 8) && (digVals < 2))
        	 {
        		 tmpBool = true;
        		 while((tmpBool == true) && (digVals < 2))
        		 {
        			 tmpBool = ROM_UARTCharPutNonBlocking(UART7_BASE, digsSend[digVals]);
        			 if(tmpBool == true)
        			 {
        				 digVals++;
        			 }
        		 }
        	 }
        	 if((digVals == 2) && (stopSend == 0))
        	 {
        		 if(ROM_UARTCharPutNonBlocking(UART7_BASE, 8))
        		 {
        			 stopSend++;
        		 }
        	 }
			 if((digVals == 2) && (stopSend == 1))
			 {
				 if(ROM_UARTCharPutNonBlocking(UART7_BASE, 10))
				 {
					 sendTrig = 0;
					 adcVals = 0;
					 digVals = 0;
					 headerSend = 0;
					 stopSend = 0;
				 }
			 }
         }
#endif //PC
        if(runTrigger != runTriggerOld)
        {
#ifdef BT_LINK
        	ROM_UARTCharPutNonBlocking(UART7_BASE, ADC_BEGIN);
#endif
        	int32_t tmp32;
        	unsigned char tmpMenuDigs;
        	runTriggerOld = runTrigger;
        	sysTickNoty.Notify();
#ifdef CONTROLLER
        	rootNode.Run();
#endif
        	for(uint16_t i=0; i<7; i++)
        	{
        		tmp32 = (int32_t)(rootNode.GetChnlVal(i));


#ifdef CONTROLLER
        		chnlValArr[i] = (NEUTRAL + (tmp32 * 0.5));
#ifdef BT_TX
        		btTx[i*2] = ((chnlValArr[i] & 4032) >> 6);
        		btTx[(i*2)+1] = ((chnlValArr[i] & 63));
#endif
        		chnlValArr[i] = chnlValArr[i]*120;
#endif
        		//if(chnlValArr[i] > (2000.0*120.0))chnlValArr[i] = (2000.0*120);
        		//if(chnlValArr[i] < (500.0*120))chnlValArr[i] = 500.0*12.0;
        	}
#ifdef BT_TX
        	btTx[0] |= BT_START;
        	btTx[13] |= BT_STOP;
        	if(btflag == 0)
        	{
        		btflag = 1;
        		btSendCntr = 0;
        	}
#endif
        	quadPos = (int16_t)QEIPositionGet(QEI0_BASE);
        	/**/
       	if(quadPos != 5000)quadNoty.Notify( quadPos - 5000);
       	QEIPositionSet(QEI0_BASE, 5000);


       	tmpMenuDigs = (menuDigs ^ menuDigsOld);
       	if((tmpMenuDigs & 128) == 128)
       	{
			if((menuDigs & ROTARY_DOWN) == ROTARY_DOWN)
			{
				OnRotaryDown();
			}
			else if((menuDigs & ROTARY_DOWN) == 0)
			{
				OnRotaryUp();
			}
       	}

       	tmpMenuDigs = (tmpMenuDigs &  menuDigs);
       	menuDigsOld = menuDigs;
       	if((tmpMenuDigs & UP_MEN) == UP_MEN)
       	{
       		OnUp();
        }
		if((tmpMenuDigs & DOWN_MEN) == DOWN_MEN)
       	{
			OnDown();
		}
		if((tmpMenuDigs & LEFT_MEN) == LEFT_MEN)
       	{
			OnLeft();
		}
		if((tmpMenuDigs & RIGHT_MEN) == RIGHT_MEN)
       	{
			OnRight();
		}
		if((tmpMenuDigs & GRAB_MEN) == GRAB_MEN)
       	{
			OnGrab();
		}
		if((tmpMenuDigs & ENTER_MEN) == ENTER_MEN)
       	{
			OnEnter();
		}
       	if((tmpMenuDigs & ESC_MEN) == ESC_MEN)
       	{
       		OnEsc();
        }

     }
#ifdef BT_TX
        while((btflag == 1) && (ROM_UARTCharPutNonBlocking(UART7_BASE, btTx[btSendCntr])))
        {
        	btSendCntr++;
        	if(btSendCntr >= 14)
        	{
        		btflag = 0;
        	}
        }
#endif
        if(ADCIntStatus(ADC0_BASE, 1, false))
                	{

        				trimPins = 0;
                		ADCIntClear(ADC0_BASE, 1);
                		//ADCSequenceDataGet(ADC0_BASE, 1, fourAdcsRaw);
                		if(initialAdcRead < 5)
                		{
                			ADCSequenceDataGet(ADC0_BASE, 1, fourAdcsOffset);
                			initialAdcRead++;
                		}
                		else
                		{
                			ADCSequenceDataGet(ADC0_BASE, 1, fourAdcsRaw);
                			static int32_t tmpErg;
                			uint16_t i;
                			for(i =0; i<4; i++)
                			{
                				fourAdcs[i] = (float)((int32_t)fourAdcsRaw[i] - (int32_t)fourAdcsOffset[i]);
                			}
#ifdef PC
                			for(i =0; i<4; i++)
                			{

                				fourAdcsSend[(i*2)] = fourAdcsRaw[i] & 1;//1 Bit
                				fourAdcsSend[(i*2)] |= ((fourAdcsRaw[i] & 2) << 1); // 1 Bit
                				fourAdcsSend[(i*2)] |= ((fourAdcsRaw[i] & 60) << 2);// 4 Bit
                				fourAdcsSend[(i*2)+1] = ((fourAdcsRaw[i] & 64) >> 6);// 1 Bit
                				fourAdcsSend[(i*2)+1] |= ((fourAdcsRaw[i] & 128) >> 5);// 1 Bit
                				fourAdcsSend[(i*2)+1] |= ((fourAdcsRaw[i] & 3840) >> 4);// 4 Bit
                			}
                			digsSend[0] = digInArrBits & 1;//1 Bit
                			digsSend[0] |= ((digInArrBits & 2) << 1); // 1 Bit
                			digsSend[0] |= ((digInArrBits & 60) << 2);// 4 Bit
                			digsSend[1] = ((digInArrBits & 64) >> 6);// 1 Bit
                			digsSend[1] |= ((digInArrBits & 128) >> 5);// 1 Bit
                			digsSend[1] |= ((digInArrBits & 3840) >> 4);// 4 Bit

                			if(sendTrig == 0)sendTrig = 1;
#endif // PC
                		}

 #ifdef CONTROLLER
                		//digInArrBits = 0;
                		//	 digInArrBits |= (GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_6)>>6);//1/32

                		                		tmpPins = (GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3));
                		                		//    digInArrBits |= (tmpPins << 1);//5/31

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5));
                		                	    //  digInArrBits |= (tmpPins << 1);//7/31

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4));
                		                	    trimPins = ((tmpPins & 15) << 4);
                		                	    //  digInArrBits |= (tmpPins << 7);//12/31

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTG_BASE, GPIO_PIN_0));
                		                	    if(tmpPins == 0)
                		                	    {
                		                	    	menuDigs = ROTARY_DOWN;
                		                	    }
                		                	    else
                		                	    {
                		                	    	menuDigs = 0;
                		                	    }
                		                	    //different than the others, G is set to pull up
                		                	    //if(!tmpPins) menuDigs |= ROTARY_DOWN;
                		                	    //else menuDigs &= ~ROTARY_DOWN;
                		                	    //    digInArrBits |= (tmpPins << 12);//13/31

                		                	    //tmpPins = (GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_2 | GPIO_PIN_3));
                		                	    //digInArrBits |= (tmpPins << 11);//15/31

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1));
                		                	    //digInArrBits |= (tmpPins << 15);//17/31
                		                	    menuDigs |= (tmpPins & 1)<<4;

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_0));
                		                	    //    digInArrBits |= (tmpPins << 17);//18/31
                		                	    tmpPins = (GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_3));
                		                	    //    digInArrBits |= (tmpPins << 15);//19/31

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTL_BASE, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5));
                		                	    trimPins |= (tmpPins >> 2);
                		                	    //  digInArrBits |= (tmpPins << 17);//23/31
                		                	    trimPins |= (tmpPins >> 3);

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTM_BASE, GPIO_PIN_4 | GPIO_PIN_5));
                		                	    //digInArrBits |= (tmpPins << 20);//26/32
                		                	    menuDigs |= (tmpPins << 1);
                		                	    tmpPins = (GPIOPinRead(GPIO_PORTM_BASE, GPIO_PIN_3));

                		                	    tmpPins = (GPIOPinRead(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3));
                		                	    //digInArrBits |= (tmpPins << 26);//30/32
                		                	    menuDigs |= tmpPins;

                	    //tmpPins = (GPIOPinRead(GPIO_PORTP_BASE, GPIO_PIN_2));
                	    //digInArrBits |= (tmpPins << 28);//19/32
                	   NotifyerInternTrim.Notify(trimPins);
                	   if(chnlMngrUi.GetActUi() == 12)
                	   {
                		   guiRefreshCntr++;
                		   if(guiRefreshCntr >= 25)
                		   {
                			   guiRefreshCntr = 0;
                			   srcInternTrimUi.RepaintVals();
                		   }
                	   }
                	   if(chnlMngrUi.GetActUi() == 16)
                	                   	   {
                	                   		   guiRefreshCntr++;
                	                   		   if(guiRefreshCntr >= 25)
                	                   		   {
                	                   			   guiRefreshCntr = 0;
                	                   			   scaleSwUi.RepaintVal();
                	                   		   }
                	                   	   }
                	   else if(chnlMngrUi.GetActUi() == 8)
                	                   	   {
                	                   		   guiRefreshCntr++;
                	                   		   if(guiRefreshCntr >= 12)
                	                   		   {
                	                   			   guiRefreshCntr = 0;
                	                   			uCAdcUi.RepaintVal();
                	                   		   }
                	                   	   }
                	   else if(chnlMngrUi.GetActUi() == 9)
                	   		{
                	              guiRefreshCntr++;
                	              if(guiRefreshCntr >= 12)
                	               {
                	                   guiRefreshCntr = 0;
                	                   srcCstmSwUi.RepaintVal();
                	               }
                	         }
                	   else if(chnlMngrUi.GetActUi() == 17)
                	   {
                	       guiRefreshCntr++;
                	       if(guiRefreshCntr >= 12)
                	       {
                	            guiRefreshCntr = 0;
                	            quantiUi.RepaintVal();
                	       }
                	    }
                	   else
                	   {
                		   guiRefreshCntr = 0;
                	   }
#endif   //Controller
                	}
/*
#define DIG_BEGIN			128
#define DIG_END				128+32
#define ADC_BEGIN 			128 + 64
#define ADC_BEGIN 			128 + 64 + 32
#define MSG_AMT_REQ_BEG		64
#define MSG_AMT_REQ_END		64 + 32
volatile uint16_t amtOfExtAdc = 0, amtOfExtDigs = 0, extMode = EXT_INIT, askForAdcFlag = 0;
#define RETRYTIME 50
volatile uint16_t retry = RETRYTIME + 1;
*/
        while(UARTCharsAvail(UART5_BASE))
        {
        	unsigned char uartExtIO;
        	static int staticByte;
        	ROM_GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_3,  GPIO_DIR_MODE_OUT);
        	uartExtIO = UARTCharGetNonBlocking(UART5_BASE);

        	if(((uartExtIO & (128+64+32))== DIG_BEGIN))//msgBegin
        	{
        	     expanInByteCntr = 1;
        	     extAdcCnt = 0;
        	     digInArrBits = (uartExtIO & 31);
        	}
        	else if((uartExtIO & (128+64+32)) == ADC_BEGIN)//msgBegin
        	{
        		expanInByteCntr = 1;
        		extAdcCnt = 0;
        		staticByte = (uartExtIO & 31)<<5;
        	}
        	else if((uartExtIO & (128+64+32)) == DIG_END)//msgEnd
        	{
        		digInArrBits = (digInArrBits << 5);
        		digInArrBits += (uartExtIO & 31);
        		askForAdcFlag = 1;
        		extMode = EXT_ADC_REQ;
        		retry = RETRYTIME + 1;
        	}
        	else if((uartExtIO & (128+64+32)) == ADC_END)
        	{
				if((expanInByteCntr & 1) == 0)
				{
					externADCs[extAdcCnt] = (uartExtIO & 31);//most sig six of 12 bits
					externADCs[extAdcCnt] = externADCs[extAdcCnt] << 5;
				}
				else
				{
					externADCs[extAdcCnt] += (uartExtIO & 31);//low sig six of 12 bits
					//if(extAdcCnt < 4) extAdcCnt++;
					if(extAdcCnt < 3) extAdcCnt++;
				}
				//if(extAdcCnt == 4)
				if(extAdcCnt == 3)
				{
					//if(externAdcCnt == 4)
					if(externAdcCnt == 3)
					{
						fourAdcs[8] = (((float)externADCs[0]) - fourAdcsOffset[4]);
						fourAdcs[9] = (((float)externADCs[1]) - fourAdcsOffset[5]);
						fourAdcs[10] = (((float)externADCs[2]) - fourAdcsOffset[6]);
						//fourAdcs[11] = (float)(externADCs[3] - fourAdcsOffset[7]);
					}
					else
					{
						externAdcCnt++;
						fourAdcsOffset[4] = externADCs[0];
						fourAdcsOffset[5] = externADCs[1];
						fourAdcsOffset[6] = externADCs[2];
						//fourAdcsOffset[7] = externADCs[3];
					}
				}
#ifdef BT_LINK
				extMode = EXT_BT_REQ;//EXT_DIG_REQ;//hier Trigger für BT_Req einbauen
#else
				extMode = EXT_DIG_REQ;//hier Trigger für BT_Req einbauen
#endif
				ROM_UARTCharPutNonBlocking(UART7_BASE, ADC_END);
        		retry = RETRYTIME + 1;
        	}//still End msg
        	else if((uartExtIO & (128+64+32)) == MSG_AMT_REQ_BEG)//msgBegin
        	{
        		expanInByteCntr = 1;
        		amtOfExtAdc = 0;
        		amtOfExtDigs = (uartExtIO & 31);//most sig six of 12 bits
        	}
        	else if((uartExtIO & (128+64+32)) == MSG_AMT_REQ_END)//amtOfExtDigs
        	{
        		amtOfExtAdc += (uartExtIO & 31);//low sig six of 12 bits
        		if(extAdcCnt < 4) extAdcCnt++;
        		extMode = EXT_DIG_REQ;
        		expanInByteCntr = 0;
        		retry = RETRYTIME + 1;
        	}//end msg
        	else
        	{
        		if(extMode == EXT_DIG_REQ)
        		{
        			digInArrBits = digInArrBits << 5;
					digInArrBits += (uartExtIO & 31);
					expanInByteCntr++;
        		}
        		if(extMode == EXT_ADC_REQ)
        		{
					if(expanInByteCntr == 1)
					{
						externADCs[extAdcCnt] = staticByte + (uartExtIO & 31);
						extAdcCnt++;
					}
					else if((expanInByteCntr & 1) == 0)
					{
						externADCs[extAdcCnt] = (uartExtIO & 31)<<5;//most sig six of 12 bits
					}
					else
					{
						externADCs[extAdcCnt] += (uartExtIO & 31);//low sig six of 12 bits
						if(extAdcCnt < 4) extAdcCnt++;
					}
					expanInByteCntr++;
        		}
        		else if(extMode == EXT_INIT)//amtOfExtDigs
        		{
					if((expanInByteCntr & 1) == 0)
					{
						amtOfExtAdc += (uartExtIO & 31);//most sig six of 12 bits
					}
					else
					{
						amtOfExtDigs += (uartExtIO & 31);//low sig six of 12 bits
					}
					expanInByteCntr++;

        		}

        	}
        	//ROM_UARTCharPutNonBlocking(UART0_BASE, digInArrBits);
        }
        ROM_GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_3,  GPIO_DIR_MODE_IN);

#ifdef BT_LINK
        while(UARTCharsAvail(UART7_BASE))
        {
        	unsigned char uartExtIO;
        	static unsigned int staticByte;
        	uartExtIO = UARTCharGetNonBlocking(UART7_BASE);
        	if((uartExtIO & (128+64+32)) == ADC_BEGIN)//msgBegin
        	{
        	      expanInByteCntrBT = 1;
        	      extAdcCntBT = 0;
        	      staticByte = (uartExtIO & 31)<<5;
        	}
        	else if((uartExtIO & (128+64+32)) == ADC_END)
        	{
        		if((expanInByteCntrBT & 1) == 0)
        		{
        			externADCsBT[extAdcCntBT] = (uartExtIO & 31);//most sig six of 12 bits
        			externADCsBT[extAdcCntBT] = externADCsBT[extAdcCntBT] << 5;
        		}
        		else
        		{
        			externADCsBT[extAdcCntBT] += (uartExtIO & 31);//low sig six of 12 bits
        			if(extAdcCntBT < 4) extAdcCntBT++;
        		}
        		if(extAdcCntBT == 4)
        		{
        			fourAdcs[4] = externADCsBT[0];
        			fourAdcs[5] = externADCsBT[1];
        			fourAdcs[6] = externADCsBT[2];
        			fourAdcs[7] = externADCsBT[3];
        		}
        		extMode = EXT_DIG_REQ;
        	    retry = RETRYTIME + 1;
        	}
        	else if(extMode == EXT_BT_REQ)
    		{
				if(expanInByteCntrBT == 1)
				{
					externADCsBT[extAdcCntBT] = staticByte + (uartExtIO & 31);
					extAdcCntBT++;
				}
				else if((expanInByteCntrBT & 1) == 0)
				{
					externADCsBT[extAdcCntBT] = (uartExtIO & 31)<<5;//most sig six of 12 bits
				}
				else
				{
					externADCsBT[extAdcCntBT] += (uartExtIO & 31);//low sig six of 12 bits
					if(extAdcCntBT < 4) extAdcCntBT++;
				}
				expanInByteCntrBT++;
    		}
        }
#endif

#ifdef PC
        while(ROM_UARTCharsAvail(UART7_BASE))
        {
        	curRecChar = ROM_UARTCharGetNonBlocking(UART7_BASE);
        	if(curRecChar == 3)
        	{
        		nibleCntr = 0;
        		numCntr = 0;
        		msgLength = 0;
        		charCntr = 1;
        	}
        	else if((curRecChar & 1) == 1)
        	{
        		if(numCntr < 8)
        		{
        			recChannels[numCntr] = ((curRecChar & 252)>>2);
        		}
        	}
        	else if((curRecChar & 2) == 2)
        	{
        		if(numCntr < 8)
        		{
        			recChannels[numCntr] += ((curRecChar & 252)<<4);
        			recChannels[numCntr] *= 120;
        			chnlValArr[numCntr] = recChannels[numCntr];
        			numCntr++;
        		}
        	}
        }
#endif // PC

        /*
         *uint32_t recChannels[7];
uint16_t nibleCntr, numCntr, msgLength, charCntr. amtRecValsTop;
         * */

    }
}

void PpmMatchIntHandler(void)
{
	static volatile uint32_t locator = 1;
	static volatile uint32_t actInact = 0;
	static volatile uint32_t sum = 0;
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

	if(actInact == 0)
	{
		actInact = 1;
		sum += seperatorArr[locator];
		TimerLoadSet(TIMER0_BASE, TIMER_A, seperatorArr[locator]);
		GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, 0);
	}
	else
	{
		actInact = 0;
		if(locator < 7)
		{
			sum += (chnlValArr[locator] - seperatorArr[locator]);
			TimerLoadSet(TIMER0_BASE, TIMER_A, (chnlValArr[locator] - seperatorArr[locator]));
		}
		else
		{
			TimerLoadSet(TIMER0_BASE, TIMER_A, (20000*120) - sum);
			sum = 0;
			retry++;
			if((GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_2)) && (retry > RETRYTIME))
			{
				retry = 0;
				UARTCharPut(UART5_BASE, DIG_END);
				extMode = EXT_DIG_REQ;
				/*
				if(extMode == EXT_DIG_REQ)
				{
					UARTCharPut(UART5_BASE, DIG_END);
				}
				else if(extMode == EXT_INIT)
				{
					UARTCharPut(UART5_BASE, MSG_AMT_REQ_END);
				}
				if(extMode == EXT_ADC_REQ)
		    	{
		    		UARTCharPut(UART5_BASE, ADC_END);
		    	}
				*/
			}
		}
			GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, GPIO_PIN_2);


		locator++;
		if(locator == 8)
		{
			locator = 0;
			sum = 0;
			ADCProcessorTrigger(ADC0_BASE, 1);
			runTrigger++;
		}
	}


}
