/*
 * Ui_Identifier_I.hpp
 *
 *  Created on: 25.09.2018
 *      Author: Justus
 */

#ifndef UIS_UI_IDENTIFIER_I_HPP_
#define UIS_UI_IDENTIFIER_I_HPP_

#include "stdint.h"
#include "../../../share/Graph_App/graph_app_i.h"
#include "../../../share/UIs/Ui_Visitor_I.hpp"

#define ROTARY_IS_DOWN 	1
#define ROTARY_IS_UP	0

class Ui_Identifier_I
{
public:

	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis) = 0;
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis) = 0;
	virtual void Up() = 0;
	virtual void Down() = 0;
	virtual void Right() = 0;
	virtual void Left() = 0;
	virtual void Grab() = 0;
	virtual void RotaryDown(unsigned int rotaryPrsState) = 0;
	virtual unsigned int GetRotaryState() = 0;
	virtual void RefreshButtons() = 0;

	virtual uint16_t GetCanSel() = 0;
	virtual uint16_t GetItmSel() = 0;
	virtual uint16_t GetStackPos() = 0;
	virtual uint16_t GetActUi() = 0;
	virtual void SetActUi(uint16_t acUi) = 0;

	virtual void RemFcnBtns() = 0;
	virtual void ConFcnBtns() = 0;
	virtual void DelSelItm() = 0;

};



#endif /* UIS_UI_IDENTIFIER_I_HPP_ */
