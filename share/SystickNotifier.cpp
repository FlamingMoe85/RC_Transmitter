/*
 * SystickNotifier.cpp
 *
 *  Created on: 16.11.2019
 *      Author: Justus
 */

#include "SystickNotifier.h"

SystickNotifier::SystickNotifier() {
	// TODO Auto-generated constructor stub

}

SystickNotifier::~SystickNotifier() {
	// TODO Auto-generated destructor stub
}

void SystickNotifier::Notify()
{
	for(uint16_t i=0; i<asignedTimeConsumersList.Count(); i++)
	{
		asignedTimeConsumersList.At(i)->TickNotify();
	}
}

void SystickNotifier::Subscribe(Systick_I* sub)
{
	sub->SetPos(asignedTimeConsumersList.Count());
	asignedTimeConsumersList.AddEnd(sub);
}

void SystickNotifier::Unsubscribe(Systick_I* sub)
{
	uint16_t start = sub->GetPos(), k;
	k = start;

	for(uint16_t i=start+1; i<asignedTimeConsumersList.Count(); i++)
	{
		asignedTimeConsumersList.At(i)->SetPos(k);
	}
	asignedTimeConsumersList.DelAtLoc(start);
}
