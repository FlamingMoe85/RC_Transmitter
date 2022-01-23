/*
 * Calc_uCAdc_Leaf_UI.h
 *
 *  Created on: 15.05.2019
 *      Author: Justus
 */

#ifndef UIS_CALC_UCADC_LEAF_UI_H_
#define UIS_CALC_UCADC_LEAF_UI_H_

#include"../../../share/Graph_App/Calc_uCAdc_Leaf.h"
#include "../utils/UtilClass.h"
#include "Ui_Identifier.h"

class Calc_uCAdc_Leaf_UI  : public Ui_Identifier{
public:
	Calc_uCAdc_Leaf_UI();
	virtual ~Calc_uCAdc_Leaf_UI();

	void SetuCAdc_Ref(Calc_uCAdc_Leaf *ref);

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
		virtual void DelSelItm(){ };

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

		void RepaintVal();

private:

		Calc_uCAdc_Leaf* myRef;
};

#endif /* UIS_CALC_UCADC_LEAF_UI_H_ */
