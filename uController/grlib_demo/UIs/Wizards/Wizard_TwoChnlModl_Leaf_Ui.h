/*
 * Wizard_TwoChnlModl_Leaf_Ui.h
 *
 *  Created on: 28.01.2021
 *      Author: Justus
 */

#ifndef UIS_WIZARDS_WIZARD_TWOCHNLMODL_LEAF_UI_H_
#define UIS_WIZARDS_WIZARD_TWOCHNLMODL_LEAF_UI_H_



#include"../../../../share/Graph_App/Wizards/Wizard_TwoChnlModl_Leaf.h"
#include "../ItemSelector.h"
#include "../Ui_Identifier.h"
#include "../../../../share/QuadEncConsumerBase.h"

class Wizard_TwoChnlModl_Leaf_Ui : public Ui_Identifier, public QuadEncConsumerBase{
public:
	Wizard_TwoChnlModl_Leaf_Ui();
	virtual ~Wizard_TwoChnlModl_Leaf_Ui();

	void SetTwoChnlModl_Ref(Wizard_TwoChnlModl_Leaf* ref);


		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Up();
		virtual void Down();
		virtual void Right();//No need
		virtual void Left();//No need
		virtual void Grab(){ };//No need

		void Left(int16_t val);
		void Right(int16_t val);


		virtual uint16_t GetCanSel(){ };// CHECK
		virtual uint16_t GetItmSel(){ };// CHECK

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
		virtual void DelSelItm(){ };

		virtual void QuadEncNotify(int16_t val);

private:
		Wizard_TwoChnlModl_Leaf* myRef;
		uint16_t curSel;

		void PaintAll();
		void MarkSelected();
		void RepaintSelVal();
		void FillVal(uint16_t sel);
};

#endif /* UIS_WIZARDS_WIZARD_TWOCHNLMODL_LEAF_UI_H_ */
