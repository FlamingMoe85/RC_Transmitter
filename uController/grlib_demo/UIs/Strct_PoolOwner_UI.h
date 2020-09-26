/*
 * Strct_PoolOwner_UI.h
 *
 *  Created on: 06.05.2019
 *      Author: Justus
 */

#ifndef UIS_STRCT_POOLOWNER_UI_H_
#define UIS_STRCT_POOLOWNER_UI_H_

#include"../../../share/Graph_App/Strct_PoolOwner_Node.h"
#include "Ui_Identifier.h"


class Strct_PoolOwner_UI : public Ui_Identifier{
public:
	Strct_PoolOwner_UI();
	virtual ~Strct_PoolOwner_UI();

	void Paint();
	void ItemSel(uint16_t sel, uint16_t cSel); //CHECK -> ItemSelector

	void SetPoolOwner_Ref(Strct_PoolOwner_Node* ref); // CHECK
	//void EnterCompoPool(Graph_App_I** curNode, UI_Visitor_I* UiVis);


	/**/
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);	// CHECK
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);	// CHECK
	virtual void Up();// CHECK
	virtual void Down();// CHECK
	virtual void Right();//No need
	virtual void Left();//No need
	virtual void Grab();//No need


	virtual uint16_t GetCanSel();// CHECK
	virtual uint16_t GetItmSel();// CHECK

	virtual void RemFcnBtns(){ };
	virtual void ConFcnBtns(){ };
	virtual void DelSelItm(){ };
	//void RmoveNameBtn();
	//void ConctNameBtn();

private:
	uint16_t curItem;
	uint16_t canSel;
	Strct_PoolOwner_Node* myRef;
};

#endif /* UIS_STRCT_POOLOWNER_UI_H_ */
