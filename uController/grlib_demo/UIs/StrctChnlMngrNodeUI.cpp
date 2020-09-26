/*
 * StrctChnlMngrNodeUI.cpp
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#include "StrctChnlMngrNodeUI.h"

#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

extern const tDisplay g_sKentec320x240x16_SSD2119;


#define CAN_X_POS	100
#define CAN_X_WIDTH	200
#define CAN_Y_WIDTH	30
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)
#define NXT_X_WIDTH	24
#define NXT_Y_WIDTH NXT_X_WIDTH
#define NXT_X_POS	(CAN_X_POS+CAN_X_WIDTH-NXT_X_WIDTH-3)

#define UNSELCTED_PNT 	ClrSaddleBrown
#define TEXT_COLR		ClrSilver

tCanvasWidget myCanvacsesChMnr[] =
{
    CanvasStruct(0, 0,0,
                 &g_sKentec320x240x16_SSD2119, CAN_X_POS, 0, CAN_X_WIDTH, CAN_Y_WIDTH,
				 CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE | CANVAS_STYLE_TEXT,
				 UNSELCTED_PNT, ClrGray, TEXT_COLR, &g_sFontCm22, "Chnl Mngr", 0, 0)
};


Strct_ChnlMngr_Node_UI::Strct_ChnlMngr_Node_UI() {
	// TODO Auto-generated constructor stub

}

Strct_ChnlMngr_Node_UI::~Strct_ChnlMngr_Node_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_ChnlMngr_Node_UI::SetStrctChnlMngr_Ref(Strct_ChnlMngr_Node *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	this->ItemSel(GetItmSel(),1);
	//WidgetPaint((tWidget *)&(myCanvacsesChMnr[0]));
	this->SetName(myRef->GetNameArr());
	Paint();
}

void Strct_ChnlMngr_Node_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Enter(curNode, this->GetItmSel());
	//WidgetRemove((tWidget *)&cmpBtns);
	//WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}


void Strct_ChnlMngr_Node_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	//WidgetRemove((tWidget *)&cmpBtns);
	//WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}



/*
void Strct_ChnlMngr_Node_UI::Up()
{

}

void Strct_ChnlMngr_Node_UI::Down()
{

}*/

/*
void Strct_ChnlMngr_Node_UI::Paint()
{

    WidgetPaint((tWidget *)&(myCanvacsesChMnr[0]));
}*/

