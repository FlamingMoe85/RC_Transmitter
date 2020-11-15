/*
 * Z_SystemConfig_Leaf.h
 *
 *  Created on: 11.11.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_Z_SYSTEMCONFIG_LEAF_H_
#define SHARE_GRAPH_APP_Z_SYSTEMCONFIG_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "../std/SerializeDest_I.hpp"

class Z_SystemConfig_Leaf  : public Graph_Leaf<Graph_App_I>{
public:
	Z_SystemConfig_Leaf();
	virtual ~Z_SystemConfig_Leaf();

    virtual void Run(float* val, uint32_t itteration){ };
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest){ };
    virtual void Deserialize(SerializeDest_I* SerDest){ };
    virtual void NullSerCntr(){ };

private:
    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_Z_SYSTEMCONFIG_LEAF_H_ */
