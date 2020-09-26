/*
 * QuadEnc_I.hpp
 *
 *  Created on: 22.12.2019
 *      Author: Justus
 */

#ifndef SHARE_QUADENC_I_HPP_
#define SHARE_QUADENC_I_HPP_


#include <stdint.h>

class QuadEnc_I
{
public:
	virtual void QuadEncNotify(int16_t val) = 0;
};


#endif /* SHARE_QUADENC_I_HPP_ */
