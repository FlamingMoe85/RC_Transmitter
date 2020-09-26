/*
 * Strct_Dummy_Leaf.h
 *
 *  Created on: 05.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_STRCT_DUMMY_LEAF_H_
#define SHARE_GRAPH_APP_STRCT_DUMMY_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Strct_Dummy_Leaf : public Graph_Leaf<Graph_App_I>{
public:
	Strct_Dummy_Leaf();
	virtual ~Strct_Dummy_Leaf();

    virtual void Run(float* val, uint32_t itteration){ };
    virtual void Show(UI_Visitor_I* UiVisitor){ };
    virtual UI_Visitor_I* GetVisitor() { };
    virtual void Serialize(SerializeDest_I* SerDest){ };
    virtual void Deserialize(SerializeDest_I* SerDest){ };
    virtual void NullSerCntr(){ };
};

#endif /* SHARE_GRAPH_APP_STRCT_DUMMY_LEAF_H_ */
