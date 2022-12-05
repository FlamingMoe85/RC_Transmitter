/*
 * Source.h
 *
 *  Created on: 22.11.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_HELPER_SOURCE_H_
#define SHARE_GRAPH_APP_HELPER_SOURCE_H_


#include "../Graph_App_I.h"
#include "../../std/Graph_Leaf.hpp"
#include "../../std/List.hpp"
#include "../../globaldefinesshare.h"
#include "../GraphAppCommons.h"
#include "../../UIs/Ui_Visitor_I.hpp"
#include "../PoolOwnerUtils.h"
//#include "../Strct_Compo_Node.h"

class Strct_Compo_Node;

class Source : public Graph_Leaf<Graph_App_I>, public PoolOwnerUtils{
public:
	Source();
	virtual ~Source();

	virtual void SetVisitor(UI_Visitor_I* v);
    UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr(){ };


	void NewTrigCompo();
	Strct_Compo_Node* GetTrigCompo();
	void SetTrigCompo(Strct_Compo_Node* tc);
    void SetMyType(uint16_t type);
    uint16_t GetType();

private:
	Strct_Compo_Node* myCompoNode;
	uint16_t myType;
    UI_Visitor_I *myUiVisitor;

};

#endif /* SHARE_GRAPH_APP_HELPER_SOURCE_H_ */
