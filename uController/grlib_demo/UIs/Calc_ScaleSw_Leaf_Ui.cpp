/*
 * Calc_ScaleSw_Leaf_Ui.cpp
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#include "Calc_ScaleSw_Leaf_Ui.h"
#include <stdint.h>
#include <stdbool.h>
#include "./grlib/grlib.h"
#include "./grlib/widget.h"
#include "./grlib/canvas.h"
#include "./grlib/pushbutton.h"


Calc_ScaleSw_Leaf_Ui::Calc_ScaleSw_Leaf_Ui() {
	// TODO Auto-generated constructor stub
	SetModuleName("Scale Switch", 12);
	SetRubric_3_Name("Pos %", 5);
	SetRubric_4_Name("Neg %", 5);
}

Calc_ScaleSw_Leaf_Ui::~Calc_ScaleSw_Leaf_Ui() {
	// TODO Auto-generated destructor stub
}

void Calc_ScaleSw_Leaf_Ui::SetScaleSw_Ref(Calc_ScaleSw_Leaf *ref)
{

	this->SetActUi(this->GetStackPos());
	Sign(this);
	OnRefSet();
	SetCRef(ref);
	Paint();
	ConFcnBtns();
}

