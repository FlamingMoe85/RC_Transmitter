/*
 * Src_InternTrim_Leaf.cpp
 *
 *  Created on: 07.09.2019
 *      Author: Justus
 */

#include "Src_InternTrim_Leaf.h"
#include "../Visitor_InternTrim.h"

extern Visitor_InternTrim VisitorInternTrim;

Src_InternTrim_Leaf::Src_InternTrim_Leaf() {
	// TODO Auto-generated constructor stub
	pairSel = 0;
	notifierPos = 0;
	VisitorInternTrim.Subscribe(this);
	this->FillNameArray(GetNameArr(), "Trim", 4);
	trimVal = 0;
	trimValfloat = 0;
	myTrimDigs = 0;
}

Src_InternTrim_Leaf::~Src_InternTrim_Leaf() {
	// TODO Auto-generated destructor stub
}

void Src_InternTrim_Leaf::Run(float* val, uint32_t itteration)
{
	*val += trimValfloat;
}

void Src_InternTrim_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	 UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Src_InternTrim_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void Src_InternTrim_Leaf::Serialize(SerializeDest_I* SerDest)
{
	uint16_t digPairCnt;
	SerDest->SaveUint16(INTERN_TRIM_TYP);
	//digPairCnt = myDigPairs.Count();
	SerDest->SaveUint16(pairSel);
	SerDest->SaveInt16(trimVal);
}

void Src_InternTrim_Leaf::Deserialize(SerializeDest_I* SerDest)
{
	pairSel = SerDest->GetUint16();
	trimVal = SerDest->GetInt16();
	trimValfloat = trimVal;
}

void Src_InternTrim_Leaf::Notify(uint16_t trimDigs)
{
	//uint16_t mask = (3<<);
	trimDigs = (trimDigs >>(2*pairSel)) & 3;

	if(myTrimDigs != trimDigs)
	{
		if(trimDigs & 1)
		{
			IncTrim();
		}
		if(trimDigs & 2)
		{
			DecTrim();
		}
	}

	myTrimDigs = trimDigs;
}

void Src_InternTrim_Leaf::IncTrim()
{
	trimVal += VALUE_STEP_UINT;
	trimValfloat = trimVal;
}

void Src_InternTrim_Leaf::DecTrim()
{
	trimVal -= VALUE_STEP_UINT;
	trimValfloat = trimVal;
}

uint16_t Src_InternTrim_Leaf::IncPairSel()
{
	if(pairSel == 3)
	{
		pairSel = 0;
	}
	else
	{
		pairSel++;
	}
	return pairSel;
}

uint16_t Src_InternTrim_Leaf::DecPairSel()
{

	if(pairSel == 0)
	{
		pairSel = 3;
	}
	else
	{
		pairSel--;
	}
	return pairSel;
}

uint16_t Src_InternTrim_Leaf::GetPairSel()
{
	return pairSel;
}


void Src_InternTrim_Leaf::SetNotifierPos(uint16_t notePos)
{
	notifierPos = notePos;
}

uint16_t Src_InternTrim_Leaf::GetNotifierPos()
{
	return notifierPos;
}

uint16_t Src_InternTrim_Leaf::GetTrimVal()
{
	return trimVal;
}

void Src_InternTrim_Leaf::SetTrimVal(uint16_t val)
{
	trimVal = val;
	trimValfloat = trimVal;
}
