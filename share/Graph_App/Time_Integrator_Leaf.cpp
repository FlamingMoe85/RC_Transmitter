/*
 * Time_Integrator_Leaf.cpp
 *
 *  Created on: 31.12.2020
 *      Author: Justus
 */

#include "Time_Integrator_Leaf.h"

extern uint32_t digInArrBits;

Time_Integrator_Leaf::Time_Integrator_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Integrator", 10);
	SetType(INTEGRATOR_TYP);
	max = +1000;
	min = -1000;
	def = 0;
	rate = 500;
	resSel = 0;
	maxF = 1000.0;
	minF = -1000.0;
	rateF = 500.0;
	defF = 0.0;
	iValue = 0.0;
	resPin = 0;
}

Time_Integrator_Leaf::~Time_Integrator_Leaf() {
	// TODO Auto-generated destructor stub
}

void Time_Integrator_Leaf::Run(float* val, uint32_t itteration)
{
	if(rateF > 0.0)iValue += (((*val)*rateF)/50000.0);
	else iValue = *val;
	if((digInArrBits & resPin)== resPin)
	{
		iValue = defF;
	}
	if(iValue > maxF)iValue = maxF;
	if(iValue < minF)iValue = minF;
	*val = iValue;
}

void Time_Integrator_Leaf::ResetIval()
{
	iValue = defF;
}

void Time_Integrator_Leaf::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Time_Integrator_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void Time_Integrator_Leaf::Show()
{
	myUiVisitor->DispShowCall(this);
}


void Time_Integrator_Leaf::Serialize(SerializeDest_I* SerDest)
{
	SerDest->SaveUint16(INTEGRATOR_TYP);
	SerDest->SaveInt16(max);
	SerDest->SaveInt16(min);
	SerDest->SaveInt16(def);

	SerDest->SaveUint16(rate);
	SerDest->SaveUint16(resSel);
}

void Time_Integrator_Leaf::Deserialize(SerializeDest_I* SerDest)
{
	SetMax(SerDest->GetInt16());
	SetMin(SerDest->GetInt16());
	SetDef(SerDest->GetInt16());

	SetRate(SerDest->GetUint16());
	SetResSel(SerDest->GetUint16());
}

void Time_Integrator_Leaf::NullSerCntr()
{

}

void Time_Integrator_Leaf::SetMax(uint16_t maxSet)
{
	max = maxSet;
	maxF = (float)max;
}

uint16_t Time_Integrator_Leaf::GetMax()
{
	return max;
}

void Time_Integrator_Leaf::SetMin(int16_t minSet)
{
	min = minSet;
	minF = (float)min;
}

int16_t Time_Integrator_Leaf::GetMin()
{
	return min;
}

void Time_Integrator_Leaf::SetRate(uint16_t rateSet)
{
	rate = rateSet;
	rateF = (float)rate;
}

uint16_t Time_Integrator_Leaf::GetRate()
{
	return rate;
}
;
void Time_Integrator_Leaf::SetDef(int16_t defSet)
{
	def = defSet;
	defF = (float)def;
}

int16_t Time_Integrator_Leaf::GetDef()
{
	return def;
}

void Time_Integrator_Leaf::SetResSel(uint16_t resSelSet)
{
	resSel = resSelSet;
	resPin = 1<<resSel;
}

uint16_t Time_Integrator_Leaf::GetResSel()
{
	return resSel+1;
}

void Time_Integrator_Leaf::AddSngMax(int16_t v)
{
	max += v;
	if(max < 0) max = 0;
	maxF = (float)max;
}

void Time_Integrator_Leaf::AddSngMin(int16_t v)
{
	min += v;
	if(min >0) min = 0;
	minF = (float)min;
}

void Time_Integrator_Leaf::AddSngRate(int16_t v)
{
	uint16_t vT;
	if(v >= 0)
	{
		rate += v;
	}
	else
	{
		vT = (uint16_t) (v *= -1);
		if(vT > rate) rate = 0;
		else rate -= vT;
	}
	rateF = (float)rate;
}

void Time_Integrator_Leaf::AddSngDef(int16_t v)
{
	def += v;
	defF = (float)def;
}

void Time_Integrator_Leaf::AddSngResSel(int16_t v)
{
	uint16_t vT;
	if(v >= 0)
	{
		resSel += v;
	}
	else
	{
		vT = (uint16_t) (v *= -1);
		if(vT > resSel) resSel = 0;
		else resSel -= vT;
	}
	resPin = 1<<resSel;
}
