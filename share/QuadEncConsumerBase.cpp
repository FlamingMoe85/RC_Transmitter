/*
 * QuadEncConsumerBase.cpp
 *
 *  Created on: 22.12.2019
 *      Author: Justus
 */

#include "QuadEncConsumerBase.h"

extern QuadEncNofityer quadNoty;

QuadEncConsumerBase::QuadEncConsumerBase() {
	// TODO Auto-generated constructor stub

}

QuadEncConsumerBase::~QuadEncConsumerBase() {
	// TODO Auto-generated destructor stub
}

void QuadEncConsumerBase::Sign(QuadEnc_I* a)
{
	quadNoty.Enter(a);
}

void QuadEncConsumerBase::Leave()
{
	quadNoty.Leave();
}

