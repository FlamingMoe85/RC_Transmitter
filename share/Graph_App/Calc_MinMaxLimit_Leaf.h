/*
 * Calc_MinMaxLimit_Leaf.h
 *
 *  Created on: 01.11.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_CALC_MINMAXLIMIT_LEAF_H_
#define SHARE_GRAPH_APP_CALC_MINMAXLIMIT_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../std/List.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "Helper/I_Quadlet.hpp"
#include "Helper/Quadlett.h"


class Calc_MinMaxLimit_Leaf : public Quadlett, public Graph_Leaf<Graph_App_I> {
public:
	Calc_MinMaxLimit_Leaf();
	virtual ~Calc_MinMaxLimit_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr(){ };

private :

    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_CALC_MINMAXLIMIT_LEAF_H_ */
