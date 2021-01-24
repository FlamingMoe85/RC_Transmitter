/*
 * Machine_DeadArea.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_DeadArea.h"
#include "../Clac_DeadArea_Leaf.hpp"

Machine_DeadArea::Machine_DeadArea() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'D';
	nameArr[1] = 'e';
	nameArr[2] = 'a';
	nameArr[3] = 'd';
	nameArr[4] = ' ';
	nameArr[5] = 'A';
	nameArr[6] = 'r';
	nameArr[7] = 'e';
	nameArr[8] = 'a';
	nameArr[9] = 0;

}

Machine_DeadArea::~Machine_DeadArea() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_DeadArea::GetType()
{
	return DEADSPAN_TYP;
}

char* Machine_DeadArea::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_DeadArea::GetInstance()
{
	return (Graph_App_I*) new Clac_DeadArea_Leaf();
}

