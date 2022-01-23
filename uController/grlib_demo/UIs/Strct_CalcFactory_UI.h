/*
 * Strct_CalcFactory_UI.h
 *
 *  Created on: 04.05.2019
 *      Author: Justus
 */

#ifndef UIS_STRCT_CALCFACTORY_UI_H_
#define UIS_STRCT_CALCFACTORY_UI_H_

#include"../../../share/Graph_App/Strct_CalcFactory.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Strct_CalcFactory_UI : public Ui_Identifier  {//: public ItemSelector{
public:
	Strct_CalcFactory_UI();
	virtual ~Strct_CalcFactory_UI();

	void ItemSel(uint16_t itmSel, uint16_t cSel);
	void Paint();
	void SetCalcFactory_Ref(Strct_CalcFactory* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void Up();
	virtual void Down();
	virtual void Right(){ };
	virtual void Left(){ };
	virtual void Grab(){ };
	virtual void RefreshButtons() { };

	virtual uint16_t GetCanSel(){return 0; };
	virtual uint16_t GetItmSel(){return 0; };

	virtual void RemFcnBtns(){ };
	virtual void ConFcnBtns(){ };
	virtual void DelSelItm(){ };

private:
	Strct_CalcFactory* myRef;
	uint16_t curItem;
	uint16_t canSel;
	char counter_1[3], counter_2[3], counter_3[3];
};

#endif /* UIS_STRCT_CALCFACTORY_UI_H_ */
