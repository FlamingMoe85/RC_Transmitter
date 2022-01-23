/*
 * Calc_ScaleSw_Leaf_Ui.h
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#ifndef UIS_Calc_ScaleSw_Leaf_Ui_H_
#define UIS_Calc_ScaleSw_Leaf_Ui_H_

#include"../../../share/Graph_App/Calc_ScaleSw_Leaf.h"
#include "../utils/UtilClass.h"
#include "Helper/Quadlet.h"

class Calc_ScaleSw_Leaf_Ui : public Quadlet{
public:
	Calc_ScaleSw_Leaf_Ui();
	virtual ~Calc_ScaleSw_Leaf_Ui();

	void SetScaleSw_Ref(Calc_ScaleSw_Leaf *ref);

};

#endif /* UIS_Calc_ScaleSw_Leaf_Ui_H_ */
