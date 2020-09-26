/*
 * Notifier_InternTrimm.cpp
 *
 *  Created on: 07.09.2019
 *      Author: Justus
 */

#include "Notifier_InternTrimm.h"

Notifier_InternTrimm::Notifier_InternTrimm() {
	// TODO Auto-generated constructor stub

}

Notifier_InternTrimm::~Notifier_InternTrimm() {
	// TODO Auto-generated destructor stub
}

void Notifier_InternTrimm::Notify(uint16_t trimDigs)
{
	for(uint16_t i=0; i<asignedTrimsList.Count(); i++)
	{
		asignedTrimsList.At(i)->Notify(trimDigs);
	}
}

void Notifier_InternTrimm::Sign(Src_InternTrim_Leaf* trim)
{
	trim->SetNotifierPos(asignedTrimsList.Count());
	asignedTrimsList.AddEnd(trim);
}

void Notifier_InternTrimm::Unsign(Src_InternTrim_Leaf* trim)
{
	uint16_t start = trim->GetNotifierPos(), k;
	k = start;

	for(uint16_t i=start+1; i<asignedTrimsList.Count(); i++)
	{
		asignedTrimsList.At(i)->SetNotifierPos(k);
	}
	asignedTrimsList.DelAtLoc(start);
}
