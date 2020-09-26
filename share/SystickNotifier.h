/*
 * SystickNotifier.h
 *
 *  Created on: 16.11.2019
 *      Author: Justus
 */

#ifndef SHARE_SYSTICKNOTIFIER_H_
#define SHARE_SYSTICKNOTIFIER_H_

#include "Systick_I.hpp"
#include "std/List.hpp"
#include <stdint.h>

class SystickNotifier {
public:
	SystickNotifier();
	virtual ~SystickNotifier();

	void Notify();
	void Subscribe(Systick_I* sub);
	void Unsubscribe(Systick_I* sub);

private:
	List<Systick_I*> asignedTimeConsumersList;
};

#endif /* SHARE_SYSTICKNOTIFIER_H_ */
