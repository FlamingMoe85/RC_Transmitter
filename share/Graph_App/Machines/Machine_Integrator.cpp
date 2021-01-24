/*
 * Machine_Integrator.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_Integrator.h"
#include "../Time_Integrator_Leaf.h"

Machine_Integrator::Machine_Integrator() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'I';
	nameArr[1] = 'n';
	nameArr[2] = 't';
	nameArr[3] = 'e';
	nameArr[4] = 'g';
	nameArr[5] = 'r';
	nameArr[6] = 'a';
	nameArr[7] = 't';
	nameArr[8] = 'o';
	nameArr[9] = 'r';
	nameArr[10] = 0;

}

Machine_Integrator::~Machine_Integrator() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_Integrator::GetType()
{
	return INTEGRATOR_TYP;
}

char* Machine_Integrator::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_Integrator::GetInstance()
{
	return (Graph_App_I*) new Time_Integrator_Leaf();
}

