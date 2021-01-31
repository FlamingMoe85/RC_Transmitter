/*
 * Z_Wizard_Node.h
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_Z_WIZARD_NODE_H_
#define SHARE_GRAPH_APP_Z_WIZARD_NODE_H_

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

#include "Wizards/Wizard_InternTrim.h"
#include "Wizards/Wizard_TwoChnlModl_Leaf.h"

class Z_Wizard_Node : public Graph_Node<Graph_App_I> {
public:
	Z_Wizard_Node();
	virtual ~Z_Wizard_Node();

    virtual void Run(float* val, uint32_t itteration){ };
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest){ };
    virtual void Deserialize(SerializeDest_I* SerDest){ };
    virtual void NullSerCntr(){ };

private:
    UI_Visitor_I *myUiVisitor;

    Wizard_InternTrim internTrimWiz;
    Wizard_TwoChnlModl_Leaf twoChnlModlWiz;
};

#endif /* SHARE_GRAPH_APP_Z_WIZARD_NODE_H_ */
