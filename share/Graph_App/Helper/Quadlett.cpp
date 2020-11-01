/*
 * Quadlett.cpp
 *
 *  Created on: 01.11.2020
 *      Author: Justus
 */

#include "Quadlett.h"
extern uint32_t digInArrBits;

Quadlett::Quadlett() {
	// TODO Auto-generated constructor stub
	nyActPos = 0;
}

Quadlett::~Quadlett() {
	// TODO Auto-generated destructor stub
}

uint32_t Quadlett::GetDigIn()
{
	return digInArrBits;
}

uint16_t Quadlett::GetPos()
{
	return nyActPos;
}

int16_t Quadlett::GetValPos()
{
	return lastValIntPos;
}

int16_t Quadlett::GetValNeg()
{
	return lastValIntNeg;
}

void Quadlett::AddChnlPair()
{
	digChnlPair* tmpPair = new digChnlPair;
	tmpPair->chnl = 0;
	tmpPair->valNeg = 1000;
	tmpPair->valPos = 1000;
	myDigPairs.AddEnd(tmpPair);
}
void Quadlett::DelChnlPairAt(uint16_t delLoc)
{
	digChnlPair* delPtr;
	delPtr = myDigPairs.DelAtLoc(delLoc);
	delete delPtr;
}
uint16_t Quadlett::GetAmtOfPairs()
{
	return myDigPairs.Count();
}


uint16_t Quadlett::AddSgndToPairIn(uint16_t loc, int16_t val)
{
	if(val < 0)
	{
		val = val*(-1);
		if(val > myDigPairs.At(loc)->chnl) myDigPairs.At(loc)->chnl = 0;
		else myDigPairs.At(loc)->chnl--;
	}
	else
	{
		myDigPairs.At(loc)->chnl += val;
	}
	return myDigPairs.At(loc)->chnl;
}


int16_t Quadlett::AddSgndToPairValPos(uint16_t loc, int16_t val)
{
	return (myDigPairs.At(loc)->valPos += val);
}
int16_t Quadlett::AddSgndToPairValNeg(uint16_t loc, int16_t val)
{
	return (myDigPairs.At(loc)->valNeg += val);
}

int16_t Quadlett::CalcVal()
{
	uint16_t loc;
	for(loc=0; loc<myDigPairs.Count(); loc++)
	{
		if(digInArrBits &  (1<<myDigPairs.At(loc)->chnl))
		{
			return myDigPairs.At(loc)->valPos;
		}
	}
	return 0;
}


void Quadlett::SetIn(uint16_t loc, int16_t val)
{
    if(val < 0) return;
    myDigPairs.At(loc)->chnl = val;
}

void Quadlett::SetValPos(uint16_t loc, int16_t val)
{
    myDigPairs.At(loc)->valPos = val;
}

void Quadlett::SetValNeg(uint16_t loc, int16_t val)
{
    myDigPairs.At(loc)->valNeg = val;
}

