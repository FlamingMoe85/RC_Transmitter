/*
 * SystickConsumerBase.cpp
 *
 *  Created on: 16.11.2019
 *      Author: Justus
 */

#include "SystickConsumerBase.h"

extern SystickNotifier sysTickNoty;

SystickConsumerBase::SystickConsumerBase() {
	// TODO Auto-generated constructor stub
	myPos = 0;
}

SystickConsumerBase::~SystickConsumerBase() {
	// TODO Auto-generated destructor stub
}

void SystickConsumerBase::SetPos(uint16_t pos)
{
	myPos = pos;
}

uint16_t SystickConsumerBase::GetPos()
{
	return myPos;
}

void SystickConsumerBase::Subscribe(Systick_I* sub)
{
	sysTickNoty.Subscribe(sub);
}

void SystickConsumerBase::Unsubscribe(Systick_I* unsub)
{
	sysTickNoty.Unsubscribe(unsub);
}
