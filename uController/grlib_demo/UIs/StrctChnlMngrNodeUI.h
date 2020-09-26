/*
 * StrctChnlMngrNodeUI.h
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#ifndef UIS_STRCTCHNLMNGRNODEUI_H_
#define UIS_STRCTCHNLMNGRNODEUI_H_

#include"../../../share/Graph_App/Strct_ChnlMngr_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Strct_ChnlMngr_Node_UI : public ItemSelector {
public:
	Strct_ChnlMngr_Node_UI();
	virtual ~Strct_ChnlMngr_Node_UI();

	void SetStrctChnlMngr_Ref(Strct_ChnlMngr_Node* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void RemFcnBtns(){ };
	virtual void ConFcnBtns(){ };
	virtual void DelSelItm(){ };
	/*void Up();
	void Down();*/

private:
	Strct_ChnlMngr_Node* myRef;
	//void Paint();
};

#endif /* UIS_STRCTCHNLMNGRNODEUI_H_ */
