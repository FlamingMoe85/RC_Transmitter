/*
 * Machine_InternTrim.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_InternTrim.h"
#include "../Src_InternTrim_Leaf.h"

Machine_InternTrim::Machine_InternTrim() {
	// TODO Auto-generated constructor stub
	nameArr[0] = 'T';
	nameArr[1] = 'r';
	nameArr[2] = 'i';
	nameArr[3] = 'm';
	nameArr[4] = 0;

}

Machine_InternTrim::~Machine_InternTrim() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_InternTrim::GetType()
{
	return INTERN_TRIM_TYP;
}

char* Machine_InternTrim::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_InternTrim::GetInstance()
{
	return (Graph_App_I*) new Src_InternTrim_Leaf();
}

