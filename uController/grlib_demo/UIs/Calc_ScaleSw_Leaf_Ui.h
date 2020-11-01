/*
 * Calc_ScaleSw_Leaf_Ui.h
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#ifndef UIS_Calc_ScaleSw_Leaf_Ui_H_
#define UIS_Calc_ScaleSw_Leaf_Ui_H_

#include"../../../share/Graph_App/Calc_ScaleSw_Leaf.h"
#include "../utils/UtilClass.h"
#include "Helper/Quadlet.h"

class Calc_ScaleSw_Leaf_Ui : public Quadlet{
public:
	Calc_ScaleSw_Leaf_Ui();
	virtual ~Calc_ScaleSw_Leaf_Ui();

	void SetScaleSw_Ref(Calc_ScaleSw_Leaf *ref);

/*		virtual void RemFcnBtns();
		virtual void ConFcnBtns();
		virtual void DelSelItm(){ };

		void Paint();
		virtual uint16_t GetItmSel();
		virtual uint16_t GetCanSel();

		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	    virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
		virtual void Up();
		virtual void Down();
		virtual void Right();
		virtual void Left();
		virtual void Grab();
		void Up(int16_t val);
		void Down(int16_t val);

		void AddIn();
		void DelIn();

		void RepaintVal();

		virtual void QuadEncNotify(int16_t val);

private:
		Calc_ScaleSw_Leaf* myRef;
		uint16_t inSel;
		uint16_t column;
		*/
};

#endif /* UIS_Calc_ScaleSw_Leaf_Ui_H_ */
