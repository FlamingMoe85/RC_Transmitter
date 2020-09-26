/*
 * Strct_TopMenue_Node_UI.cpp
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#include "Strct_TopMenue_Node_UI.h"

Strct_TopMenue_Node_UI::Strct_TopMenue_Node_UI() {
	// TODO Auto-generated constructor stub

}

Strct_TopMenue_Node_UI::~Strct_TopMenue_Node_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_TopMenue_Node_UI::SetTopMenue_Ref(Strct_TopMenue_Node* ref)
{
	myRef = ref;
	//myRef_C = ref;
	this->ConctNameBtn();
	//WidgetAdd(WIDGET_ROOT, (tWidget *)moduleBtns);
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	ItemSel(GetItmSel(), 1);
	this->SetName(myRef->GetNameArr());
	//WidgetPaint((tWidget *)&moduleBtns);
	Paint();
}

void Strct_TopMenue_Node_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	this->RmoveNameBtn();
	//WidgetRemove((tWidget *)&moduleBtns);
	//WidgetPaint((tWidget *)&modBtnsCov);
	(**curNode).Show(UiVis);
}

void Strct_TopMenue_Node_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	EscItmSel();
	(**curNode).Enter(curNode, this->GetItmSel());
	this->RmoveNameBtn();
	//WidgetRemove((tWidget *)&moduleBtns);
	//WidgetPaint((tWidget *)&modBtnsCov);
	(**curNode).Show(UiVis);
}
