/*
 * Time_Blinker_Leaf.cpp
 *
 *  Created on: 27.12.2019
 *      Author: Justus
 */

#include "Time_Blinker_Leaf.h"

Time_Blinker_Leaf::Time_Blinker_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Blinker", 7);
	noteCntr = 0;
	curSlot = 0;
	Subscribe(this);
    SetType(BLINK_TYP);
	SetMyType(BLINK_TYP);
}

Time_Blinker_Leaf::~Time_Blinker_Leaf() {
	// TODO Auto-generated destructor stub
	Unsubscribe(this);
}

void Time_Blinker_Leaf::Run(float* val, uint32_t itteration)
{
	float trigVal = 0.0;
	uint32_t trigItt;
	if(GetTrigCompo() != 0)GetTrigCompo()->Run(&trigVal, trigItt);

	if(trigVal < 500.0)
	{
		noteCntr = 0;
		curSlot = 0;
	}

	if(mySlots.Count() > curSlot)
	{
		*val += mySlots.At(curSlot)->val;
	}
}

uint16_t Time_Blinker_Leaf::GetPos()
{
//	return nyActPos;
}

int16_t Time_Blinker_Leaf::GetVal()
{
	return lastValInt;
}
void Time_Blinker_Leaf::SetBlnkDur(uint16_t loc, uint16_t val)
{
    if(val < 0) return;
    mySlots.At(loc)->dur = val;
}
void Time_Blinker_Leaf::SetBlnkVal(uint16_t loc, int16_t val)
{
    mySlots.At(loc)->val = val;
}

void Time_Blinker_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	SetVisitor(UiVisitor);
	UiVisitor->DispShowCall(this);
}

void Time_Blinker_Leaf::AddSlot()
{
	mySlots.AddEnd(new timeSlot);
}

void Time_Blinker_Leaf::DelSlotAt(uint16_t delLoc)
{
	timeSlot* delPtr;
	delPtr = mySlots.DelAtLoc(delLoc);
	delete delPtr;
}
uint16_t Time_Blinker_Leaf::GetAmtOfSlots()
{
	return mySlots.Count();
}


uint16_t Time_Blinker_Leaf::AddSgndToSlotDur(uint16_t loc, int16_t val)
{
	if(val < 0)
	{
		val = val*(-1);
		if(val > mySlots.At(loc)->dur) mySlots.At(loc)->dur = 0;
		else mySlots.At(loc)->dur--;
	}
	else
	{
		mySlots.At(loc)->dur += val;
	}
	return mySlots.At(loc)->dur;
}
uint16_t Time_Blinker_Leaf::AddSgndToSlotVal(uint16_t loc, int16_t val)
{
	return (mySlots.At(loc)->val += val);
}

void Time_Blinker_Leaf::TickNotify()
{
	noteCntr++;
	if(mySlots.Count() > 0)
	{
		if(mySlots.At(curSlot)->dur <= noteCntr)
		{
			noteCntr = 0;
			curSlot++;
			if(curSlot >= mySlots.Count())curSlot = 0;
		}
	}
}

