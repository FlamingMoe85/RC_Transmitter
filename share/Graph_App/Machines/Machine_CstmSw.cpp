/*
 * Machine_CstmSw.cpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#include "Machine_CstmSw.h"
#include "../Src_CstmSw_Leaf.h"

Machine_CstmSw::Machine_CstmSw() {
	// TODO Auto-generated constructor stub
		nameArr[0] = 'C';
		nameArr[1] = 'u';
		nameArr[2] = 's';
		nameArr[3] = 't';
		nameArr[4] = 'o';
		nameArr[5] = 'm';
		nameArr[6] = ' ';
		nameArr[7] = 'S';
		nameArr[8] = 'w';
		nameArr[9] = 'i';
		nameArr[10] = 't';
		nameArr[11] = 'c';
		nameArr[12] = 'h';
		nameArr[13] = 0;
}

Machine_CstmSw::~Machine_CstmSw() {
	// TODO Auto-generated destructor stub
}

uint16_t Machine_CstmSw::GetType()
{
	return CSTMSW_TYP;
}

char* Machine_CstmSw::GetNameArr()
{
	return &(nameArr[0]);
}

Graph_App_I* Machine_CstmSw::GetInstance()
{
	return (Graph_App_I*) new Src_CstmSw_Leaf();
}
