/*
 * Clac_DeadArea_Leaf.hpp
 *
 *  Created on: 16.10.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_CLAC_DEADAREA_LEAF_HPP_
#define SHARE_GRAPH_APP_CLAC_DEADAREA_LEAF_HPP_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Clac_DeadArea_Leaf : public Graph_Leaf<Graph_App_I> {
public:
	Clac_DeadArea_Leaf();
	virtual ~Clac_DeadArea_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr(){ };

    void AddSngdToNullPoint(float val);
    void SetNullPoint(float val);
    float GetNullPoint();

    void AddSngdToSpan(float val);
    void SetSpan(float val);
    float GetSpan();

private:
    float nullPoint, deadSpan;
	#define NULLPOINT	0
	#define SPAN		1

    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_CLAC_DEADAREA_LEAF_HPP_ */
