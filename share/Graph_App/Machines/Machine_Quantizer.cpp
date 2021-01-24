/*
 * Machine_Quantizer.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_Quantizer.h"
#include "../Calc_Quantizer_Leaf.h"

Machine_Quantizer::Machine_Quantizer() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'Q';
	nameArr[1] = 'u';
	nameArr[2] = 'a';
	nameArr[3] = 'n';
	nameArr[4] = 't';
	nameArr[5] = 'i';
	nameArr[6] = 'z';
	nameArr[7] = 'e';
	nameArr[8] = 'r';
	nameArr[9] = 0;

}

Machine_Quantizer::~Machine_Quantizer() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_Quantizer::GetType()
{
	return QUANTIZER_TYP;
}

char* Machine_Quantizer::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_Quantizer::GetInstance()
{
	return (Graph_App_I*) new Calc_Quantizer_Leaf();
}

