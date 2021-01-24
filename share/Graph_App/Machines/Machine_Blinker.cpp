/*
 * Machine_Blinker.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_Blinker.h"
#include "../Time_Blinker_Leaf.h"

Machine_Blinker::Machine_Blinker() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'B';
	nameArr[1] = 'l';
	nameArr[2] = 'i';
	nameArr[3] = 'n';
	nameArr[4] = 'k';
	nameArr[5] = 'e';
	nameArr[6] = 'r';
	nameArr[7] = 0;

}

Machine_Blinker::~Machine_Blinker() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_Blinker::GetType()
{
	return BLINK_TYP;
}

char* Machine_Blinker::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_Blinker::GetInstance()
{
	return (Graph_App_I*) new Time_Blinker_Leaf();
}

