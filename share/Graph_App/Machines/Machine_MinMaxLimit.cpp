/*
 * Machine_MinMaxLimit.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "MachineM_inMaxLimit.h"
#include "../Calc_MinMaxLimit_Leaf.h"

Machine_MinMaxLimit::Machine_MinMaxLimit() {
	// TODO Auto-generated constructor stub

	nameArr[0] = 'L';
	nameArr[1] = 'i';
	nameArr[2] = 'm';
	nameArr[3] = 'i';
	nameArr[4] = 't';
	nameArr[5] = 'e';
	nameArr[6] = 'r';
	nameArr[7] = 0;
}

Machine_MinMaxLimit::~Machine_MinMaxLimit() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_MinMaxLimit::GetType()
{
	return MINMAXLIMITER_TYP;
}

char* Machine_MinMaxLimit::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_MinMaxLimit::GetInstance()
{
	return (Graph_App_I*) new Calc_MinMaxLimit_Leaf();
}
