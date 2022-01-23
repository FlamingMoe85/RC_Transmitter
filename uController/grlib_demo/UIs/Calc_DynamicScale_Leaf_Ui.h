/*
 * Calc_DynamicScale_Leaf_Ui.h
 *
 *  Created on: 21.11.2020
 *      Author: Justus
 */

#ifndef UIS_CALC_DYNAMICSCALE_LEAF_UI_H_
#define UIS_CALC_DYNAMICSCALE_LEAF_UI_H_

#include"../../../share/Graph_App/Calc_DynamicScale_Leaf.h"
#include"../../../share/Graph_App/Strct_PoolOwner_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Calc_DynamicScale_Leaf_Ui   : public Ui_Identifier{
public:
	Calc_DynamicScale_Leaf_Ui();
	virtual ~Calc_DynamicScale_Leaf_Ui();

	void SetDynScale_Ref(Calc_DynamicScale_Leaf* ref);

	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
	virtual void Up(){ };
	virtual void Down(){ };
	virtual void Right();
	virtual void Left();
	virtual void Grab();
	virtual void RefreshButtons();


	virtual uint16_t GetCanSel(){ };// CHECK
	virtual uint16_t GetItmSel(){ };// CHECK

	virtual void RemFcnBtns();
	virtual void ConFcnBtns();
	virtual void DelSelItm(){ };

	void SetCompPool(Strct_PoolOwner_Node* poolOwnRef);
	void EnterCompoPool();//(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	void EnterTrigCompo();

private:
	Calc_DynamicScale_Leaf* myRef;
	Strct_PoolOwner_Node* myPoolOwnerRef;
	unsigned int btnSel;
};

#endif /* UIS_CALC_DYNAMICSCALE_LEAF_UI_H_ */
