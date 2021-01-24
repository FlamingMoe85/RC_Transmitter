/*
 * Machine_ScaleSwitch.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_ScaleSwitch.h"
#include "../Calc_ScaleSw_Leaf.h"

Machine_ScaleSwitch::Machine_ScaleSwitch() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'S';
	nameArr[1] = 'c';
	nameArr[2] = 'a';
	nameArr[3] = 'l';
	nameArr[4] = 'e';
	nameArr[5] = ' ';
	nameArr[6] = 'S';
	nameArr[7] = 'w';
	nameArr[8] = 'i';
	nameArr[9] = 't';
	nameArr[10] = 'c';
	nameArr[11] = 'h';
	nameArr[12] = 0;
}

Machine_ScaleSwitch::~Machine_ScaleSwitch() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_ScaleSwitch::GetType()
{
	return SCALE_SWITCH_TYP;
}

char* Machine_ScaleSwitch::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_ScaleSwitch::GetInstance()
{
	return (Graph_App_I*) new Calc_ScaleSw_Leaf();
}
