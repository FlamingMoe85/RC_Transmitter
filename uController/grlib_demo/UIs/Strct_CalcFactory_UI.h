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

class Strct_CalcFactory_UI  : public ItemSelector{
public:
	Strct_CalcFactory_UI();
	virtual ~Strct_CalcFactory_UI();

	void SetCalcFactory_Ref(Strct_CalcFactory* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void RemFcnBtns(){ };
	virtual void ConFcnBtns(){ };
	virtual void DelSelItm(){ };

private:
	Strct_CalcFactory* myRef;
};

#endif /* UIS_STRCT_CALCFACTORY_UI_H_ */
