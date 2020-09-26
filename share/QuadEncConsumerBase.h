/*
 * QuadEncConsumerBase.h
 *
 *  Created on: 22.12.2019
 *      Author: Justus
 */

#ifndef SHARE_QUADENCCONSUMERBASE_H_
#define SHARE_QUADENCCONSUMERBASE_H_

#include "QuadEnc_I.hpp"
#include "QuadEncNofityer.h"

class QuadEncConsumerBase : public QuadEnc_I{
public:
	QuadEncConsumerBase();
	virtual ~QuadEncConsumerBase();

	void Sign(QuadEnc_I* a);
	void Leave();
};

#endif /* SHARE_QUADENCCONSUMERBASE_H_ */
