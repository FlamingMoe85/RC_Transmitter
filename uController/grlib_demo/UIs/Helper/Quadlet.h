/*
 * Quadlet.h
 *
 *  Created on: 31.10.2020
 *      Author: Justus
 */

#ifndef UIS_HELPER_QUADLET_H_
#define UIS_HELPER_QUADLET_H_

#include "../../../../share/Graph_App/Calc_ScaleSw_Leaf.h"
#include "../../utils/UtilClass.h"
#include "../Ui_Identifier.h"
#include "../../../../share/QuadEncConsumerBase.h"
#include "../../../../share/Graph_App/Helper/I_Quadlet.hpp"


class Quadlet  : public Ui_Identifier, public QuadEncConsumerBase{
public:
	Quadlet();
	virtual ~Quadlet();

	virtual void RemFcnBtns();
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
	virtual void Grab() { };
	void Up(int16_t val);
	void Down(int16_t val);


	void RepaintVal();

	void SetModuleName(char* name, uint16_t length);
	void SetRubric_3_Name(char* name, uint16_t length);
	void SetRubric_4_Name(char* name, uint16_t length);

	virtual void QuadEncNotify(int16_t val);

	void SetCRef(I_Quadlet* cRefArg);
	uint16_t GetInSel();
	void CorrectInSel();
	uint16_t GetAmtPairsOfCRef();
	void OnRefSet();

private:

	uint16_t inSel;
	uint16_t column;
	uint16_t myType;

};

#endif /* UIS_HELPER_QUADLET_H_ */
