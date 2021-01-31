/*
 * Wizard_IntTrim.h
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#ifndef UIS_WIZARDS_WIZARD_INTTRIM_UI_H_
#define UIS_WIZARDS_WIZARD_INTTRIM_UI_H_

#include"../../../../share/Graph_App/Wizards/Wizard_InternTrim.h"
#include "../ItemSelector.h"
#include "../Ui_Identifier.h"

class Wizard_IntTrim_Ui  : public Ui_Identifier{
public:
	Wizard_IntTrim_Ui();
	virtual ~Wizard_IntTrim_Ui();

	void SetIntTrimWiz_Ref(Wizard_InternTrim* ref);


		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Up(){ };
		virtual void Down(){ };
		virtual void Right(){ };//No need
		virtual void Left(){ };//No need
		virtual void Grab(){ };//No need


		virtual uint16_t GetCanSel(){ };// CHECK
		virtual uint16_t GetItmSel(){ };// CHECK

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
		virtual void DelSelItm(){ };

private:
		Wizard_InternTrim* myRef;
};

#endif /* UIS_WIZARDS_WIZARD_INTTRIM_UI_H_ */
