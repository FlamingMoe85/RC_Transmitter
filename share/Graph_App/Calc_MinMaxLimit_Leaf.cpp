/*
 * Calc_MinMaxLimit_Leaf.cpp
 *
 *  Created on: 01.11.2020
 *      Author: Justus
 */

#include "Calc_MinMaxLimit_Leaf.h"

Calc_MinMaxLimit_Leaf::Calc_MinMaxLimit_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Limiter", 7);

	    SetType(MINMAXLIMITER_TYP);
}

Calc_MinMaxLimit_Leaf::~Calc_MinMaxLimit_Leaf() {
	// TODO Auto-generated destructor stub
}

void Calc_MinMaxLimit_Leaf::Run(float* val, uint32_t itteration)
{
	volatile static float conv, tmp;
	uint16_t actPos, neutChnl, neutPos;

	for(actPos=0; actPos<myDigPairs.Count(); actPos++)
	{
		neutChnl = myDigPairs.At(actPos)->chnl;
		if(neutChnl != 0)
		{
			if(GetDigIn() & (1 << (neutChnl-1))) break;
		}
		else
		{
			neutPos = actPos;
		}
	}
	if(actPos == myDigPairs.Count()) actPos = neutPos;
	nyActPos = actPos;
	lastValIntPos = myDigPairs.At(nyActPos)->valPos;
	lastValIntNeg = myDigPairs.At(nyActPos)->valNeg;
	tmp = *val;
	if(tmp < 0.0)
	{
		conv = (float)lastValIntNeg;
		if(tmp < conv) tmp = conv;
	}
	else
	{
		conv = (float)lastValIntPos;
		if(tmp > conv) tmp = conv;
	}
	*val = tmp;
}


void Calc_MinMaxLimit_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Calc_MinMaxLimit_Leaf::GetVisitor()
{
	return myUiVisitor;
}


void Calc_MinMaxLimit_Leaf::Serialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	SerDest->SaveUint16(MINMAXLIMITER_TYP);
	digPairCnt = myDigPairs.Count();
	SerDest->SaveUint16(digPairCnt);
	for(uint16_t i=0; i<digPairCnt; i++)
	{
		SerDest->SaveUint16(myDigPairs.At(i)->chnl);
		SerDest->SaveInt16(myDigPairs.At(i)->valPos);
		SerDest->SaveInt16(myDigPairs.At(i)->valNeg);
	}
}

void Calc_MinMaxLimit_Leaf::Deserialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	digPairCnt = SerDest->GetUint16();
	for(uint16_t i=0; i<digPairCnt; i++)
	{
		AddChnlPair();
		myDigPairs.At(i)->chnl = SerDest->GetUint16();
		myDigPairs.At(i)->valPos = SerDest->GetInt16();
		myDigPairs.At(i)->valNeg = SerDest->GetInt16();
	}
}
