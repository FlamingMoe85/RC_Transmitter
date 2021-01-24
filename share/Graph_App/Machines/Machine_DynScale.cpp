/*
 * Machine_DynScale.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_DynScale.h"
#include "../Calc_DynamicScale_Leaf.h"

Machine_DynScale::Machine_DynScale() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'D';
	nameArr[1] = 'y';
	nameArr[2] = 'n';
	nameArr[3] = ' ';
	nameArr[4] = 'S';
	nameArr[5] = 'c';
	nameArr[6] = 'a';
	nameArr[7] = 'l';
	nameArr[8] = 'e';
	nameArr[9] = 0;
}

Machine_DynScale::~Machine_DynScale() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_DynScale::GetType()
{
	return DYNSCALE_TYP;
}

char* Machine_DynScale::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_DynScale::GetInstance()
{
	return (Graph_App_I*) new Calc_DynamicScale_Leaf();
}
