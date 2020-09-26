/*
 * QuadEncNofityer.cpp
 *
 *  Created on: 22.12.2019
 *      Author: Justus
 */

#include "QuadEncNofityer.h"

QuadEncNofityer::QuadEncNofityer() {
	// TODO Auto-generated constructor stub

}

QuadEncNofityer::~QuadEncNofityer() {
	// TODO Auto-generated destructor stub
}

void QuadEncNofityer::Enter(QuadEnc_I* a)
{
	currentQuadEncSink = a;
}

void QuadEncNofityer::Leave()
{
	currentQuadEncSink = 0;
}

void QuadEncNofityer::Notify(int16_t val)
{
	if(currentQuadEncSink != 0) currentQuadEncSink->QuadEncNotify(val);
}
