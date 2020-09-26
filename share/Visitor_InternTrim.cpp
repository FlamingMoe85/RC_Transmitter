/*
 * Visitor_InternTrim.cpp
 *
 *  Created on: 08.09.2019
 *      Author: Justus
 */

#include "Visitor_InternTrim.h"

Visitor_InternTrim::Visitor_InternTrim() {
	// TODO Auto-generated constructor stub

}

Visitor_InternTrim::~Visitor_InternTrim() {
	// TODO Auto-generated destructor stub
}

void Visitor_InternTrim::SetTrimNotfier(Notifier_InternTrimm* trimNote)
{
	myTrimNotifier = trimNote;
}

void Visitor_InternTrim::Subscribe(Src_InternTrim_Leaf* src)
{
	myTrimNotifier->Sign(src);
}

void Visitor_InternTrim::Unsubscribe(Src_InternTrim_Leaf* src)
{
	myTrimNotifier->Unsign(src);
}
