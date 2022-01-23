/*
 * StrctCompoNodeUI.h
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#ifndef UIS_STRCTCOMPONODEUI_H_
#define UIS_STRCTCOMPONODEUI_H_

#include"../../../share/Graph_App/Strct_Compo_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Strct_Compo_Node_UI : public ItemSelector  {
public:
	Strct_Compo_Node_UI();
	virtual ~Strct_Compo_Node_UI();

	void SetStrctCmp_Ref(Strct_Compo_Node* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	void EnterModFac(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	void SetCompPool(Strct_PoolOwner_Node* poolOwnRef);
	void EnterCompoPool(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void RemFcnBtns();
	virtual void ConFcnBtns();
	virtual void DelSelItm();


	virtual void Up(){ItemUp();};
	virtual void Down(){ItemDown();};
	virtual void Right();
	virtual void Left();
	virtual void Grab();
	virtual void RefreshButtons();

private:
	Strct_Compo_Node* myRef;
	Strct_PoolOwner_Node* myPoolOwnerRef;
	unsigned int btnSel;
};

#endif /* UIS_STRCTCOMPONODEUI_H_ */
