/*
 * Visitor_InternTrim.h
 *
 *  Created on: 08.09.2019
 *      Author: Justus
 */

#ifndef SHARE_VISITOR_INTERNTRIM_H_
#define SHARE_VISITOR_INTERNTRIM_H_

#include "Notifier_InternTrimm.h"

class Src_InternTrim_Leaf;

class Visitor_InternTrim {
public:
	Visitor_InternTrim();
	virtual ~Visitor_InternTrim();

	void SetTrimNotfier(Notifier_InternTrimm* trimNote);
	void Subscribe(Src_InternTrim_Leaf* src);
	void Unsubscribe(Src_InternTrim_Leaf* src);

private:
	Notifier_InternTrimm* myTrimNotifier;
};

#endif /* SHARE_VISITOR_INTERNTRIM_H_ */
