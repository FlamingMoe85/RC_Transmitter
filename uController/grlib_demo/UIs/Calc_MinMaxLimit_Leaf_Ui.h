/*
 * Calc_MinMaxLimit_Leaf_Ui.h
 *
 *  Created on: 01.11.2020
 *      Author: Justus
 */

#ifndef UIS_CALC_MINMAXLIMIT_LEAF_UI_H_
#define UIS_CALC_MINMAXLIMIT_LEAF_UI_H_

#include"../../../share/Graph_App/Calc_ScaleSw_Leaf.h"
#include "../utils/UtilClass.h"
#include "Helper/Quadlet.h"

class Calc_MinMaxLimit_Leaf_Ui  : public Quadlet{
public:
	Calc_MinMaxLimit_Leaf_Ui();
	virtual ~Calc_MinMaxLimit_Leaf_Ui();

	void SetLimiter_Ref(Calc_MinMaxLimit_Leaf* ref);
};

#endif /* UIS_CALC_MINMAXLIMIT_LEAF_UI_H_ */
