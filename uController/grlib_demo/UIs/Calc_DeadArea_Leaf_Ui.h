/*
 * Calc_DeadArea_Leaf_Ui.h
 *
 *  Created on: 16.10.2020
 *      Author: Justus
 */

#ifndef UIS_CALC_DEADAREA_LEAF_UI_H_
#define UIS_CALC_DEADAREA_LEAF_UI_H_

#include"../../../share/Graph_App/Clac_DeadArea_Leaf.hpp"
#include "../utils/UtilClass.h"
#include "Ui_Identifier.h"
#include "../../../share/QuadEncConsumerBase.h"

class Calc_DeadArea_Leaf_Ui  : public Ui_Identifier, public QuadEncConsumerBase{
public:
	Calc_DeadArea_Leaf_Ui();
	virtual ~Calc_DeadArea_Leaf_Ui();

	void SetDeadSpan_Ref(Clac_DeadArea_Leaf* ref);

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
	void Up(int16_t val);
	void Down(int16_t val);
	virtual void Right();
	virtual void Left();
	virtual void Grab();



	virtual void QuadEncNotify(int16_t val);

private:
    void MarkSelected();
	void RepaintNpVal();
	void RepaintSpanVal();
	Clac_DeadArea_Leaf* myRef;
	uint16_t sel;
};

#endif /* UIS_CALC_DEADAREA_LEAF_UI_H_ */
