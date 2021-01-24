/*
 * MachineRamp.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "MachineRamp.h"
#include "../TimeCalc_Ramp_Leaf.h"

Machine_Ramp::Machine_Ramp() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'R';
	nameArr[1] = 'a';
	nameArr[2] = 'm';
	nameArr[3] = 'p';
	nameArr[5] = 0;

}

Machine_Ramp::~Machine_Ramp() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_Ramp::GetType()
{
	return RAMP_TYP;
}

char* Machine_Ramp::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_Ramp::GetInstance()
{
	return (Graph_App_I*) new TimeCalc_Ramp_Leaf();
}

