/*
 * Calc_Quantizer_Leaf.cpp
 *
 *  Created on: 30.03.2020
 *      Author: Justus
 */

#include "Calc_Quantizer_Leaf.h"

Calc_Quantizer_Leaf::Calc_Quantizer_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Quantizer", 9);
	nyActPos = 0;
    SetType(QUANTIZER_TYP);
}

Calc_Quantizer_Leaf::~Calc_Quantizer_Leaf() {
	// TODO Auto-generated destructor stub
}

void Calc_Quantizer_Leaf::Run(float* val, uint32_t itteration)
{
	float conv;
	uint16_t actPos = 0, neutChnl, neutPos;
	int16_t valInt = (int)((*val)), tmpInt=0, tmpIntOld=0;
	lastValInt = 0;
	if(valInt > 0)
	{
		for(actPos=0; actPos<myLevelPairs.Count(); actPos++)
		{
			tmpInt = myLevelPairs.At(actPos)->mark;
			if((valInt < tmpInt) && (tmpInt > 0))break;
		}
		if(myLevelPairs.Count() == 0) lastValInt = 0;
		else if(actPos == myLevelPairs.Count()) lastValInt = (myLevelPairs.At(myLevelPairs.Count()-1)->val);
		else if(actPos > 0)
		{
			if(myLevelPairs.At(actPos-1)->val > 0)lastValInt = (myLevelPairs.At(actPos-1)->val);
			else lastValInt = 0;
		}
		else lastValInt = 0;
	}
	else if(valInt < 0)
	{
		for(actPos=0; actPos<myLevelPairs.Count(); actPos++)
		{
			tmpInt = myLevelPairs.At(actPos)->mark;
			if((valInt <= tmpInt))break;
		}

		if(myLevelPairs.Count() == 0) lastValInt = 0;
		else if(actPos == myLevelPairs.Count())lastValInt = 0;
		else if(actPos == 0) lastValInt = (myLevelPairs.At(0)->val);
		else if(actPos > 0)
		{
			if(myLevelPairs.At(actPos)->val < 0)lastValInt = (myLevelPairs.At(actPos)->val);
			else lastValInt = 0;
		}
		else lastValInt = 0;
	}
	//if(myLevelPairs.Count() > 0)
		//{
		//if(actPos == myLevelPairs.Count()) actPos = neutPos;
		nyActPos = actPos;
		//lastValInt = myLevelPairs.At(nyActPos)->val;
		conv = (float)lastValInt;
	//}
	*val = conv;
}

void Calc_Quantizer_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	UiVisitor->DispShowCall(this);
}

UI_Visitor_I*Calc_Quantizer_Leaf:: GetVisitor()
{
	return myUiVisitor;
}

void Calc_Quantizer_Leaf::Serialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	SerDest->SaveUint16(QUANTIZER_TYP);
	digPairCnt = myLevelPairs.Count();
	SerDest->SaveUint16(digPairCnt);
	for(uint16_t i=0; i<digPairCnt; i++)
	{
		SerDest->SaveInt16(myLevelPairs.At(i)->mark);
		SerDest->SaveInt16(myLevelPairs.At(i)->val);
	}
}

void Calc_Quantizer_Leaf::Deserialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	digPairCnt = SerDest->GetUint16();
	for(uint16_t i=0; i<digPairCnt; i++)
	{
		AddMark();
		myLevelPairs.At(i)->mark = SerDest->GetInt16();
		myLevelPairs.At(i)->val = SerDest->GetInt16();
	}
}

void Calc_Quantizer_Leaf::AddMark()
{
	quantPair* tmpPair = new quantPair;
	tmpPair->mark = 0;
	tmpPair->val = 0;
	myLevelPairs.AddEnd(tmpPair);
}

void Calc_Quantizer_Leaf::DelMark(uint16_t delLoc)
{
	quantPair* delPtr;
	delPtr = myLevelPairs.DelAtLoc(delLoc);
	delete delPtr;
}

int16_t Calc_Quantizer_Leaf::AddSgndToLevel(uint16_t levSel, int16_t val)
{
	return (myLevelPairs.At(levSel)->mark += val);
}

int16_t Calc_Quantizer_Leaf::AddSgndToLevelVal(uint16_t levSel, int16_t val)
{
	return (myLevelPairs.At(levSel)->val += val);
}

uint16_t Calc_Quantizer_Leaf::GetAmtOfPairs()
{
	return myLevelPairs.Count();
}

uint16_t Calc_Quantizer_Leaf::GetPos()
{
	return nyActPos;
}

int16_t Calc_Quantizer_Leaf::GetVal()
{
	return lastValInt;
}

void Calc_Quantizer_Leaf::SetLevelAt(uint16_t levSel, int16_t val)
{
    myLevelPairs.At(levSel)->mark = val;
}

void Calc_Quantizer_Leaf::SetValAt(uint16_t levSel, int16_t val)
{
    myLevelPairs.At(levSel)->val = val;
}
