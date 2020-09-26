/*
 * SystickConsumerBase.h
 *
 *  Created on: 16.11.2019
 *      Author: Justus
 */

#ifndef SHARE_SYSTICKCONSUMERBASE_H_
#define SHARE_SYSTICKCONSUMERBASE_H_

#include "Systick_I.hpp"
#include "SystickNotifier.h"
#include <stdint.h>

class SystickConsumerBase : public Systick_I{
public:
	SystickConsumerBase();
	virtual ~SystickConsumerBase();

	virtual void SetPos(uint16_t pos);
	virtual uint16_t GetPos();

	void Subscribe(Systick_I* sub);
	void Unsubscribe(Systick_I* unsub);

private:
	uint16_t myPos;
};

#endif /* SHARE_SYSTICKCONSUMERBASE_H_ */
