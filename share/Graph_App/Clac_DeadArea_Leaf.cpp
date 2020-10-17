/*
 * Clac_DeadArea_Leaf.cpp
 *
 *  Created on: 16.10.2020
 *      Author: Justus
 */

#include "Clac_DeadArea_Leaf.hpp"

Clac_DeadArea_Leaf::Clac_DeadArea_Leaf() {
	// TODO Auto-generated constructor stub
	nullPoint = 0.0;
	deadSpan = 0.0;
    this->FillNameArray(GetNameArr(), "Dead Span", 9);
    SetType(DEADSPAN_TYP);
}

Clac_DeadArea_Leaf::~Clac_DeadArea_Leaf() {
	// TODO Auto-generated destructor stub
}

void Clac_DeadArea_Leaf::Run(float* val, uint32_t itteration)
{
	if(*val > (nullPoint + deadSpan))
	{
		*val = *val - deadSpan;
	}
	else if(*val < (nullPoint - deadSpan))
	{
		*val = *val + deadSpan;
	}
	else
	{
		*val = nullPoint;
	}
}

void Clac_DeadArea_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Clac_DeadArea_Leaf::GetVisitor()
{
	return myUiVisitor;
}


void Clac_DeadArea_Leaf::AddSngdToNullPoint(float val)
{
	nullPoint += val;
}

void Clac_DeadArea_Leaf::SetNullPoint(float val)
{
	nullPoint = val;
}

float Clac_DeadArea_Leaf::GetNullPoint()
{
	return nullPoint;
}

void Clac_DeadArea_Leaf::AddSngdToSpan(float val)
{
	deadSpan += val;
	if(deadSpan < 0) deadSpan = 0.0;
}

void Clac_DeadArea_Leaf::SetSpan(float val)
{
	deadSpan = val;
	if(deadSpan < 0) deadSpan = 0.0;
}

float Clac_DeadArea_Leaf::GetSpan()
{
	return deadSpan;
}

void Clac_DeadArea_Leaf::Serialize(SerializeDest_I* SerDest)
{

}

void Clac_DeadArea_Leaf::Deserialize(SerializeDest_I* SerDest)
{

}
