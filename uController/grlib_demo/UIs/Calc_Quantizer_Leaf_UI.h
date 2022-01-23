/*
 * Calc_Quantizer_Leaf_UI.h
 *
 *  Created on: 30.03.2020
 *      Author: Justus
 */

#ifndef UIS_CALC_QUANTIZER_LEAF_UI_H_
#define UIS_CALC_QUANTIZER_LEAF_UI_H_

#include"../../../share/Graph_App/Calc_Quantizer_Leaf.h"
#include "../utils/UtilClass.h"
#include "Ui_Identifier.h"
#include "../../../share/QuadEncConsumerBase.h"

class Calc_Quantizer_Leaf_UI  : public Ui_Identifier, public QuadEncConsumerBase{
public:
	Calc_Quantizer_Leaf_UI();
	virtual ~Calc_Quantizer_Leaf_UI();

	void SetQuantizer_Ref(Calc_Quantizer_Leaf *ref);

	virtual void RemFcnBtns();
	virtual void ConFcnBtns();
	virtual void DelSelItm(){ };

	virtual uint16_t GetItmSel();
	virtual uint16_t GetCanSel();

	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
	virtual void Up();
	virtual void Down();
	virtual void Right();
	virtual void Left();
	virtual void Grab();
	virtual void RefreshButtons();
	void Up(int16_t val);
	void Down(int16_t val);

	virtual void QuadEncNotify(int16_t val);

	void Paint();
	void RepaintVal();
	void AddMark();
	void DelMark();

private:
	Calc_Quantizer_Leaf* myRef;
	uint16_t inSel;
	uint16_t column;
	unsigned int btnSel;
};

#endif /* UIS_CALC_QUANTIZER_LEAF_UI_H_ */
