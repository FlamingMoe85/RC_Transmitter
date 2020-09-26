/*
 * TimeCalc_Ramp_Leaf_UI.h
 *
 *  Created on: 15.11.2019
 *      Author: Justus
 */

#ifndef UIS_TIMECALC_RAMP_LEAF_UI_H_
#define UIS_TIMECALC_RAMP_LEAF_UI_H_

#include "../../../share/Graph_App/TimeCalc_Ramp_Leaf.h"
#include "Ui_Identifier.h"
#include "../utils/UtilClass.h"
#include "../../../share/QuadEncConsumerBase.h"

class TimeCalc_Ramp_Leaf_UI : public Ui_Identifier, public QuadEncConsumerBase{
public:
	TimeCalc_Ramp_Leaf_UI();
	virtual ~TimeCalc_Ramp_Leaf_UI();

	void SetTimeCalc_Ramp_Ref(TimeCalc_Ramp_Leaf* ref);

	virtual uint16_t GetItmSel();
		virtual uint16_t GetCanSel();

		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
			virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
		virtual void Up();
		virtual void Down();
		virtual void Right();
		virtual void Left();
		virtual void Grab(){ };

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
		virtual void DelSelItm(){ };

		virtual void QuadEncNotify(int16_t val);
		void Up(int16_t val);
		void Down(int16_t val);

private:
	TimeCalc_Ramp_Leaf* myRef;
	uint16_t sel;

	void PaintVal();
	void MarkSelected();
};

#endif /* UIS_TIMECALC_RAMP_LEAF_UI_H_ */
