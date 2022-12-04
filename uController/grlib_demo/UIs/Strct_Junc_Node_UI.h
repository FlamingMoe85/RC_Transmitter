/*
 * Strct_Junc_Node_UI.h
 *
 *  Created on: 18.09.2019
 *      Author: Justus
 */

#ifndef UIS_STRCT_JUNC_NODE_UI_H_
#define UIS_STRCT_JUNC_NODE_UI_H_

#include"../../../share/Graph_App/Strct_Junc_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Strct_Junc_Node_UI : public ItemSelector{
public:
	Strct_Junc_Node_UI();
	virtual ~Strct_Junc_Node_UI();

	void SetJunc_Ref(Strct_Junc_Node* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	void SetCompPool(Strct_PoolOwner_Node* poolOwnRef);
	void EnterCompoPool(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void RemFcnBtns();
	virtual void ConFcnBtns();
	virtual void DelSelItm();


	virtual void Up();
	virtual void Down();
	virtual void Right();
	virtual void Left();
	virtual void Grab();
	virtual void RefreshButtons();

private:
	Strct_Junc_Node* myRef;
	Strct_PoolOwner_Node* myPoolOwnerRef;
	unsigned int btnSel;
};

#endif /* UIS_STRCT_JUNC_NODE_UI_H_ */
