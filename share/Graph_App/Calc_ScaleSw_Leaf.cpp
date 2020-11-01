/*
 * Calc_ScaleSw_Leaf.cpp
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#include "Calc_ScaleSw_Leaf.h"



Calc_ScaleSw_Leaf::Calc_ScaleSw_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Scale Switch", 12);

    SetType(SCALE_SWITCH_TYP);
}

Calc_ScaleSw_Leaf::~Calc_ScaleSw_Leaf() {
	// TODO Auto-generated destructor stub
}

void Calc_ScaleSw_Leaf::Run(float* val, uint32_t itteration)
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
	}
	else
	{
		conv = (float)lastValIntPos;
	}
	*val = ((tmp) * conv) / 1000.0;

}


void Calc_ScaleSw_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Calc_ScaleSw_Leaf::GetVisitor()
{
	return myUiVisitor;
}


void Calc_ScaleSw_Leaf::Serialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	SerDest->SaveUint16(SCALE_SWITCH_TYP);
	digPairCnt = myDigPairs.Count();
	SerDest->SaveUint16(digPairCnt);
	for(uint16_t i=0; i<digPairCnt; i++)
	{
		SerDest->SaveUint16(myDigPairs.At(i)->chnl);
		SerDest->SaveInt16(myDigPairs.At(i)->valPos);
		SerDest->SaveInt16(myDigPairs.At(i)->valNeg);
	}
}

void Calc_ScaleSw_Leaf::Deserialize(SerializeDest_I* SerDest)
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

