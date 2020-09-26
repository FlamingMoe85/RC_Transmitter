/*
 * Notifier_InternTrimm.h
 *
 *  Created on: 07.09.2019
 *      Author: Justus
 */

#ifndef SHARE_NOTIFIER_INTERNTRIMM_H_
#define SHARE_NOTIFIER_INTERNTRIMM_H_

#include "std/List.hpp"
#include "Graph_App/Src_InternTrim_Leaf.h"

class Notifier_InternTrimm {
public:
	Notifier_InternTrimm();
	virtual ~Notifier_InternTrimm();

	void Notify(uint16_t trimDigs);
	void Sign(Src_InternTrim_Leaf* trim);
	void Unsign(Src_InternTrim_Leaf* trim);

private:
	List<Src_InternTrim_Leaf*> asignedTrimsList;
};

#endif /* SHARE_NOTIFIER_INTERNTRIMM_H_ */
