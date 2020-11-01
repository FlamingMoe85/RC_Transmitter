/*
 * Calc_MinMaxLimit_Leaf_Ui.cpp
 *
 *  Created on: 01.11.2020
 *      Author: Justus
 */

#include "Calc_MinMaxLimit_Leaf_Ui.h"
#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"

Calc_MinMaxLimit_Leaf_Ui::Calc_MinMaxLimit_Leaf_Ui() {
	// TODO Auto-generated constructor stub
	SetModuleName("Limiter", 7);
	SetRubric_3_Name("Max %", 5);
	SetRubric_4_Name("Min %", 5);
}

Calc_MinMaxLimit_Leaf_Ui::~Calc_MinMaxLimit_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}

void Calc_MinMaxLimit_Leaf_Ui::SetLimiter_Ref(Calc_MinMaxLimit_Leaf* ref)
{

	this->SetActUi(this->GetStackPos());
	Sign(this);
	OnRefSet();
	SetCRef((I_Quadlet*)ref);
	Paint();
	ConFcnBtns();
}
