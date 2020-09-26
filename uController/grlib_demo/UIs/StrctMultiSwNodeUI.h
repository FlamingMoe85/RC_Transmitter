/*
 * StrctMultiSwNodeUI.h
 *
 *  Created on: 22.04.2019
 *      Author: Justus
 */

#ifndef UIS_STRCTMULTISWNODEUI_H_
#define UIS_STRCTMULTISWNODEUI_H_

#include"../../../share/Graph_App/Strct_MultSw_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class StrctMultiSwNodeUI : public ItemSelector{
public:
	StrctMultiSwNodeUI();
	virtual ~StrctMultiSwNodeUI();

	void SetMultSw_Ref(Strct_MultSw_Node* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	void SetCompPool(Strct_PoolOwner_Node* poolOwnRef);
	void EnterCompoPool(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void RemFcnBtns();
	virtual void ConFcnBtns();
	virtual void DelSelItm();

private:
	Strct_MultSw_Node* myRef;
	Strct_PoolOwner_Node* myPoolOwnerRef;
};

#endif /* UIS_STRCTMULTISWNODEUI_H_ */
