/*
 * Machine_uCAdc.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_uCAdc.h"
#include "../../globaldefinesshare.h"
#include "../Calc_uCAdc_Leaf.h"

Machine_uCAdc::Machine_uCAdc() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'A';
	nameArr[1] = 'D';
	nameArr[2] = 'C';
	nameArr[3] = 0;
}

Machine_uCAdc::~Machine_uCAdc() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_uCAdc::GetType()
{
	return ADCuC_TYP;
}

char* Machine_uCAdc::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_uCAdc::GetInstance()
{
	return (Graph_App_I*) new Calc_uCAdc_Leaf();
}
