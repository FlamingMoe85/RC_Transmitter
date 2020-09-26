/*
 * Systick_I.hpp
 *
 *  Created on: 16.11.2019
 *      Author: Justus
 */

#ifndef SHARE_SYSTICK_I_HPP_
#define SHARE_SYSTICK_I_HPP_

#include <stdint.h>

class Systick_I
{
public:
	virtual void TickNotify() = 0;
	virtual void SetPos(uint16_t pos) = 0;
	virtual uint16_t GetPos() = 0;
};



#endif /* SHARE_SYSTICK_I_HPP_ */
