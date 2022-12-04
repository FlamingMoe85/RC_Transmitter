/*
 * Ui_Identifier.cpp
 *
 *  Created on: 25.09.2018
 *      Author: Justus
 */

#include "Ui_Identifier.h"


static uint16_t uiIdntCntr = 0;
static uint16_t actUi;

static unsigned int rotaryState;

Ui_Identifier::Ui_Identifier() {
	// TODO Auto-generated constructor stub
	myStackPos = uiIdntCntr++;
	actUi = 0;
	rotaryState = ROTARY_IS_UP;
}

Ui_Identifier::~Ui_Identifier() {
	// TODO Auto-generated destructor stub
}



uint16_t Ui_Identifier::GetStackPos()
{
	return myStackPos;
}

uint16_t Ui_Identifier::GetActUi()
{
	return actUi;
}

void Ui_Identifier::SetActUi(uint16_t acUi)
{
	actUi = acUi;
}

void Ui_Identifier::RotaryDown(unsigned int rotaryPrsState)
{
	rotaryState = rotaryPrsState;
	RefreshButtons();
}

unsigned int Ui_Identifier::GetRotaryState()
{
	return rotaryState;
}
