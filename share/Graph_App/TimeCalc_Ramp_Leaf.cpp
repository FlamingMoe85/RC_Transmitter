/*
 * TimeCalc_Ramp_Leaf.cpp
 *
 *  Created on: 15.11.2019
 *      Author: Justus
 */

#include "TimeCalc_Ramp_Leaf.h"

TimeCalc_Ramp_Leaf::TimeCalc_Ramp_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Ramp" , (uint16_t)4);
	Subscribe(this);

	for(int i=0; i<4; i++)
	{
		SetPercPerSec(i, 500);
	}
	nullPoint = 0;
	noteCntr = 0.0;
	lastOut = 0.0;
}

TimeCalc_Ramp_Leaf::~TimeCalc_Ramp_Leaf() {
	// TODO Auto-generated destructor stub
	Unsubscribe(this);
}

void TimeCalc_Ramp_Leaf::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* TimeCalc_Ramp_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void TimeCalc_Ramp_Leaf::Run(float* val, uint32_t itteration)
{
	//float diff = *val - lastOut;
	diff = *val - lastOut;

	if(lastOut > nullPoint)
	{
		if(diff > 0.0)//above zero rising
		{
			diff = lastOut + (stepPairs[ABOVE_RISING].deltaStep*noteCntr);
			if(diff > *val) diff = *val;//*val = lastOut;
			*val = diff;
			lastOut = *val;
		}
		else // above zero falling
		{
			diff = lastOut - (stepPairs[ABOVE_FALLING].deltaStep*noteCntr);
			if(diff < *val) diff = *val;//*val = lastOut;
			*val = diff;
			lastOut = *val;
		}
	}
	else if(lastOut < nullPoint)
	{
		if(diff > 0.0)//below zero rising
		{
			diff = lastOut + (stepPairs[BELOW_RISING].deltaStep*noteCntr);
			if(diff > *val) diff = *val;//*val = lastOut;
			*val = diff;
			lastOut = *val;
		}
		else//below zero falling
		{
			diff = lastOut - (stepPairs[BELOW_FALLING].deltaStep*noteCntr);
			if(diff < *val) diff = *val;//*val = lastOut;
			*val = diff;
			lastOut = *val;
		}
	}
	else
	{
		if(diff > 0.0)//above zero rising
		{
			diff = lastOut + (stepPairs[ABOVE_RISING].deltaStep*noteCntr);
			if(diff > *val) diff = *val;//*val = lastOut;
			*val = diff;
			lastOut = *val;
		}
		else//below zero falling
		{
			diff = lastOut - (stepPairs[BELOW_FALLING].deltaStep*noteCntr);
			if(diff < *val) diff = *val;//*val = lastOut;
			*val = diff;
			lastOut = *val;
		}
	}
	noteCntr = 0.0;
}

void TimeCalc_Ramp_Leaf::TickNotify()
{
	noteCntr = noteCntr + 1.0;
}

void TimeCalc_Ramp_Leaf::SetPercPerSec(uint16_t sel,uint16_t val)
{
	float tmpF;
	tmpF = ((float)val);
	if(sel > 3) return;
	stepPairs[sel].deltaStep = tmpF / 50.0;
	stepPairs[sel].percPerSec = val;
}

uint16_t TimeCalc_Ramp_Leaf::GetPercPerSec(uint16_t sel)
{
	if(sel > 3) return 0;
	return stepPairs[sel].percPerSec;
}

void TimeCalc_Ramp_Leaf::SetNullPoint(int16_t nPoint)
{
	nullPoint = nPoint;
}

int16_t TimeCalc_Ramp_Leaf::GetNullPoint()
{
	return nullPoint;
}

void TimeCalc_Ramp_Leaf::Serialize(SerializeDest_I* SerDest)
{
	SerDest->SaveUint16(RAMP_TYP);
	for(int i=0; i<4; i++)
	{
		SerDest->SaveUint16(stepPairs[i].percPerSec);
	}
	SerDest->SaveInt16(nullPoint);
}

void TimeCalc_Ramp_Leaf::Deserialize(SerializeDest_I* SerDest)
{
	for(int i=0; i<4; i++)
	{
		SetPercPerSec(i, SerDest->GetUint16());
	}
	nullPoint = SerDest->GetInt16();
}
