/*
 * Time_Integrator_Leaf_Ui.h
 *
 *  Created on: 01.01.2021
 *      Author: Justus
 */

#ifndef UIS_HELPER_TIME_INTEGRATOR_LEAF_UI_H_
#define UIS_HELPER_TIME_INTEGRATOR_LEAF_UI_H_

#include "../../../share/Graph_App/Time_Integrator_Leaf.h"
#include "Ui_Identifier.h"
#include "../utils/UtilClass.h"
#include "../../../share/QuadEncConsumerBase.h"

class Time_Integrator_Leaf_Ui : public Ui_Identifier, public QuadEncConsumerBase {
public:
	Time_Integrator_Leaf_Ui();
	virtual ~Time_Integrator_Leaf_Ui();

	void SetIntegrator_Ref(Time_Integrator_Leaf* caller);

	virtual uint16_t GetItmSel();
		virtual uint16_t GetCanSel();

		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
		virtual void Up();
		virtual void Down();
		virtual void Right();
		virtual void Left();
		virtual void Grab();

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
		virtual void DelSelItm(){ };

		virtual void QuadEncNotify(int16_t val);
		void Up(int16_t val);
		void Down(int16_t val);

private:
		Time_Integrator_Leaf* myRef;
		uint16_t sel, selOld;


		void PaintVal();
		void MarkSelected();
		void PaintSelected();
};

#endif /* UIS_HELPER_TIME_INTEGRATOR_LEAF_UI_H_ */
