/*
 * Strct_PoolOwner_Leaf.h
 *
 *  Created on: 06.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_STRCT_POOLOWNER_LEAF_H_
#define SHARE_GRAPH_APP_STRCT_POOLOWNER_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "PoolOwnerUtils.h"

#include "Strct_Dummy_Leaf.h"

class Strct_PoolOwner_Node : public Graph_Node<Graph_App_I>, public PoolOwnerUtils{
public:
	Strct_PoolOwner_Node();
	virtual ~Strct_PoolOwner_Node();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void SetUiVisitor(UI_Visitor_I* uiVisRef);
    void Show();

private:
    Strct_Dummy_Leaf dummy_1;
    Strct_Dummy_Leaf dummy_2;
    Strct_Dummy_Leaf dummy_3;
    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_STRCT_POOLOWNER_LEAF_H_ */
