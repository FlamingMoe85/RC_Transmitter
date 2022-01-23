/*
 * CalcMultiplicationLeafUI.h
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#ifndef UIS_CALCMULTIPLICATIONLEAFUI_H_
#define UIS_CALCMULTIPLICATIONLEAFUI_H_

#include"../../../share/Graph_App/Calc_Multiplication_Leaf.h"
#include "../utils/UtilClass.h"
#include "Ui_Identifier.h"
#include "../../../share/QuadEncConsumerBase.h"

class Calc_Multiplication_Leaf_UI : public Ui_Identifier, public QuadEncConsumerBase  {
public:
	Calc_Multiplication_Leaf_UI();
	virtual ~Calc_Multiplication_Leaf_UI();

	void SetCalcLeaf_Mult_Ref(Calc_Multiplication_Leaf* ref);

private:
	Calc_Multiplication_Leaf* myRef;
	void Paint();
	virtual uint16_t GetItmSel();
	virtual uint16_t GetCanSel();

	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
	virtual void Up();
	virtual void Down();
	virtual void Right(){ };
	virtual void Left(){ };
	virtual void Grab(){ };
	virtual void RefreshButtons() { };

	virtual void RemFcnBtns(){ };
	virtual void ConFcnBtns(){ };
	virtual void DelSelItm(){ };

	virtual void QuadEncNotify(int16_t val);
	void Up(int16_t val);
	void Down(int16_t val);
};

#endif /* UIS_CALCMULTIPLICATIONLEAFUI_H_ */
