/*
 * Src_CstmSw_Leaf.cpp
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#include "Src_CstmSw_Leaf.h"

extern uint32_t digInArrBits;

Src_CstmSw_Leaf::Src_CstmSw_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Custom Switch", 13);
	nyActPos = 0;
    SetType(CSTMSW_TYP);
    mode = CONT_MODE;
    nyActPosOld = 0;
}

Src_CstmSw_Leaf::~Src_CstmSw_Leaf() {
	// TODO Auto-generated destructor stub
}

void Src_CstmSw_Leaf::Run(float* val, uint32_t itteration)
{
    (void)itteration;
	float conv;
    uint16_t actPos, neutChnl, neutPos = 0;
	uint32_t digBitsCopy = digInArrBits;
	for(actPos=0; actPos<myDigPairs.Count(); actPos++)
	{
		neutChnl = myDigPairs.At(actPos)->chnl;
		if(neutChnl != 0)
		{
			if(digBitsCopy & (1 << (neutChnl-1))) break;
		}
		else
		{
			neutPos = actPos;
		}
	}
	if(myDigPairs.Count() > 0)
	{
		if(actPos == myDigPairs.Count()) actPos = neutPos;
		nyActPos = actPos;
		if(mode == PULSE_MODE)
		{
			if(nyActPosOld != nyActPos)
			{
				lastValInt = myDigPairs.At(nyActPos)->val;
			}
			else
			{
				lastValInt = myDigPairs.At(0)->val;
			}
		}
		else
		{
			lastValInt = myDigPairs.At(nyActPos)->val;
		}
		nyActPosOld = nyActPos;

		conv = (float)lastValInt;
	*val += conv;
	}

}

uint16_t Src_CstmSw_Leaf::GetPos()
{
	return nyActPos;
}

int16_t Src_CstmSw_Leaf::GetVal()
{
	return lastValInt;
}

void Src_CstmSw_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Src_CstmSw_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void Src_CstmSw_Leaf::AddChnlPair()
{
	digChnlPair* tmpPair = new digChnlPair();
	tmpPair->chnl = 0 ;
	tmpPair->val = 0;
	myDigPairs.AddEnd(tmpPair);
}
void Src_CstmSw_Leaf::DelChnlPairAt(uint16_t delLoc)
{
	digChnlPair* delPtr;
	delPtr = myDigPairs.DelAtLoc(delLoc);
	delete delPtr;
}
uint16_t Src_CstmSw_Leaf::GetAmtOfPairs()
{
	return myDigPairs.Count();
}


uint16_t Src_CstmSw_Leaf::AddSgndToPairIn(uint16_t loc, int16_t val)
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
uint16_t Src_CstmSw_Leaf::AddSgndToPairVal(uint16_t loc, int16_t val)
{
	return (myDigPairs.At(loc)->val += val);
}

int16_t Src_CstmSw_Leaf::CalcVal()
{
	uint16_t loc;
	for(loc=0; loc<myDigPairs.Count(); loc++)
	{
		if(digInArrBits &  (1<<myDigPairs.At(loc)->chnl))
		{
			return myDigPairs.At(loc)->val;
		}
	}
	return 0;
}

void Src_CstmSw_Leaf::SetPairIn(uint16_t loc, int16_t val)
{
    if(val < 0) return;
    myDigPairs.At(loc)->chnl = val;
}

void Src_CstmSw_Leaf::SetPairVal(uint16_t loc, int16_t val)
{
    myDigPairs.At(loc)->val = val;
}

void Src_CstmSw_Leaf::SetMode(uint16_t m)
{
	switch(m)
	{
		case CONT_MODE:
		{
			mode = m;
			break;
		}
		case PULSE_MODE:
		{
			mode = m;
			break;
		}
	}
}

void Src_CstmSw_Leaf::CycleMode()
{
	if(mode == CONT_MODE)
	{
		mode = PULSE_MODE;
	}
	else
	{
		mode = CONT_MODE;
	}
}

uint16_t Src_CstmSw_Leaf::GetMode()
{
	return mode;
}

void Src_CstmSw_Leaf::Serialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	SerDest->SaveUint16(CSTMSW_TYP);
	SerDest->SaveUint16(mode);
	digPairCnt = myDigPairs.Count();
	SerDest->SaveUint16(digPairCnt);
	for(uint16_t i=0; i<digPairCnt; i++)
	{
		SerDest->SaveUint16(myDigPairs.At(i)->chnl);
		SerDest->SaveInt16(myDigPairs.At(i)->val);
	}
}

void Src_CstmSw_Leaf::Deserialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	digPairCnt = SerDest->GetUint16();//reads the mode
	mode = digPairCnt;
	digPairCnt = SerDest->GetUint16();
	for(uint16_t i=0; i<digPairCnt; i++)
	{
		AddChnlPair();
		myDigPairs.At(i)->chnl = SerDest->GetUint16();
		myDigPairs.At(i)->val = SerDest->GetInt16();
	}
}
