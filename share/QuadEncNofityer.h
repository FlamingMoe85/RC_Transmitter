/*
 * QuadEncNofityer.h
 *
 *  Created on: 22.12.2019
 *      Author: Justus
 */

#ifndef SHARE_QUADENCNOFITYER_H_
#define SHARE_QUADENCNOFITYER_H_

#include "QuadEnc_I.hpp"

class QuadEncNofityer {
public:
	QuadEncNofityer();
	virtual ~QuadEncNofityer();

	void Enter(QuadEnc_I* a);
	void Leave();

	void Notify(int16_t val);

private:
	QuadEnc_I* currentQuadEncSink;
};

#endif /* SHARE_QUADENCNOFITYER_H_ */
