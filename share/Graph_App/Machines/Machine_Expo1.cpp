/*
 * Machine_Expo1.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_Expo1.h"
#include "../Calc_Expo1_Leaf.h"

Machine_Expo1::Machine_Expo1() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'E';
	nameArr[1] = 'x';
	nameArr[2] = 'p';
	nameArr[3] = 'o';
	nameArr[4] = ' ';
	nameArr[5] = '1';
	nameArr[6] = 0;

}

Machine_Expo1::~Machine_Expo1() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_Expo1::GetType()
{
	return EXPO1_TYP;
}

char* Machine_Expo1::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_Expo1::GetInstance()
{
	return (Graph_App_I*) new Calc_Expo1_Leaf();
}

