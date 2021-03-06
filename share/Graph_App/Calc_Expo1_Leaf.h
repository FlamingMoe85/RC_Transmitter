/*
 * Calc_Expo1_Leaf.h
 *
 *  Created on: 14.11.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_CALC_EXPO1_LEAF_H_
#define SHARE_GRAPH_APP_CALC_EXPO1_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../std/List.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "PoolOwnerUtils.h"
#include "Strct_Compo_Node.h"
#include "Helper/Source.h"

class Calc_Expo1_Leaf : public Source{ //public Graph_Leaf<Graph_App_I>, public PoolOwnerUtils{
public:
	Calc_Expo1_Leaf();
	virtual ~Calc_Expo1_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
private:
};

#endif /* SHARE_GRAPH_APP_CALC_EXPO1_LEAF_H_ */
