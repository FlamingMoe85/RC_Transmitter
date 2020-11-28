/*
 * Calc_DynamicScale_Leaf.cpp
 *
 *  Created on: 21.11.2020
 *      Author: Justus
 */

#include "Calc_DynamicScale_Leaf.h"

Calc_DynamicScale_Leaf::Calc_DynamicScale_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Dyn Scale", 9);
	SetType(DYNSCALE_TYP);
	SetMyType(DYNSCALE_TYP);
}

Calc_DynamicScale_Leaf::~Calc_DynamicScale_Leaf() {
	// TODO Auto-generated destructor stub
}

void Calc_DynamicScale_Leaf::Show(UI_Visitor_I *UiVisitor)
{
	SetVisitor(UiVisitor);
    UiVisitor->DispShowCall(this);
}


void Calc_DynamicScale_Leaf::Run(float* val, uint32_t itteration)
{
	int16_t intConv;
	float floatConv;
	float expPerc = 0.0;
	uint32_t trigItt;

	if(GetTrigCompo() != 0)GetTrigCompo()->Run(&expPerc, trigItt);
	else expPerc = 1000.0;

	*val = *val * (expPerc / 1000.0);
}



