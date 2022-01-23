/*
 * CalcAdditionLeafUI.h
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#ifndef UIS_CALCADDITIONLEAFUI_H_
#define UIS_CALCADDITIONLEAFUI_H_

#include"../../../share/Graph_App/Calc_Addition_Leaf.h"
#include "../utils/UtilClass.h"
#include "Ui_Identifier.h"

class Calc_Addition_Leaf_UI : public Ui_Identifier  {
public:
	Calc_Addition_Leaf_UI();
	virtual ~Calc_Addition_Leaf_UI();

	void SetCalcLeaf_Add_Ref(Calc_Addition_Leaf *ref);

	virtual void RemFcnBtns(){ };
	virtual void ConFcnBtns(){ };
	virtual void DelSelItm(){ };


private:
	Calc_Addition_Leaf* myRef;
	void Paint();
	virtual uint16_t GetItmSel();
	virtual uint16_t GetCanSel();

	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
    virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Up();
	virtual void Down();
	virtual void Right();
	virtual void Left();
	virtual void Grab();
	virtual void RefreshButtons() { };

	char num;
};

#endif /* UIS_CALCADDITIONLEAFUI_H_ */
