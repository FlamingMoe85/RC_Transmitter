/*
 * Strct_TopMenue_Node.h
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_STRCT_TOPMENUE_NODE_H_
#define SHARE_GRAPH_APP_STRCT_TOPMENUE_NODE_H_

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Strct_TopMenue_Node : public Graph_Node<Graph_App_I> {
public:
	Strct_TopMenue_Node();
	virtual ~Strct_TopMenue_Node();

    virtual void Run(float* val, uint32_t itteration){ };
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Show();
    virtual void Serialize(SerializeDest_I* SerDest){ };
    virtual void Deserialize(SerializeDest_I* SerDest){ };
    virtual void NullSerCntr(){ };

private:
    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_STRCT_TOPMENUE_NODE_H_ */
