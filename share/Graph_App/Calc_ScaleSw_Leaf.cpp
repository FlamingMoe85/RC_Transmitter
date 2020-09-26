/*
 * Calc_ScaleSw_Leaf.cpp
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#include "Calc_ScaleSw_Leaf.h"

extern uint32_t digInArrBits;

Calc_ScaleSw_Leaf::Calc_ScaleSw_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Scale Switch", 12);
	nyActPos = 0;
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
			if(digInArrBits & (1 << (neutChnl-1))) break;
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

uint16_t Calc_ScaleSw_Leaf::GetPos()
{
	return nyActPos;
}

int16_t Calc_ScaleSw_Leaf::GetValPos()
{
	return lastValIntPos;
}

int16_t Calc_ScaleSw_Leaf::GetValNeg()
{
	return lastValIntNeg;
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

void Calc_ScaleSw_Leaf::AddChnlPair()
{
	digChnlPair* tmpPair = new digChnlPair;
	tmpPair->chnl = 0;
	tmpPair->valNeg = 1000;
	tmpPair->valPos = 1000;
	myDigPairs.AddEnd(tmpPair);
}
void Calc_ScaleSw_Leaf::DelChnlPairAt(uint16_t delLoc)
{
	digChnlPair* delPtr;
	delPtr = myDigPairs.DelAtLoc(delLoc);
	delete delPtr;
}
uint16_t Calc_ScaleSw_Leaf::GetAmtOfPairs()
{
	return myDigPairs.Count();
}


uint16_t Calc_ScaleSw_Leaf::AddSgndToPairIn(uint16_t loc, int16_t val)
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


int16_t Calc_ScaleSw_Leaf::AddSgndToPairValPos(uint16_t loc, int16_t val)
{
	return (myDigPairs.At(loc)->valPos += val);
}
int16_t Calc_ScaleSw_Leaf::AddSgndToPairValNeg(uint16_t loc, int16_t val)
{
	return (myDigPairs.At(loc)->valNeg += val);
}

int16_t Calc_ScaleSw_Leaf::CalcVal()
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


void Calc_ScaleSw_Leaf::SetIn(uint16_t loc, int16_t val)
{
    if(val < 0) return;
    myDigPairs.At(loc)->chnl = val;
}

void Calc_ScaleSw_Leaf::SetValPos(uint16_t loc, int16_t val)
{
    myDigPairs.At(loc)->valPos = val;
}

void Calc_ScaleSw_Leaf::SetValNeg(uint16_t loc, int16_t val)
{
    myDigPairs.At(loc)->valNeg = val;
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
