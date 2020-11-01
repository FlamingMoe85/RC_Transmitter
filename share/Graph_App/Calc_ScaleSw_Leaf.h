/*
 * Calc_ScaleSw_Leaf.h
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_Calc_ScaleSw_Leaf_H_
#define SHARE_GRAPH_APP_Calc_ScaleSw_Leaf_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../std/List.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "Helper/I_Quadlet.hpp"
#include "Helper/Quadlett.h"

class Calc_ScaleSw_Leaf : public Quadlett, public Graph_Leaf<Graph_App_I>{
public:


	Calc_ScaleSw_Leaf();
	virtual ~Calc_ScaleSw_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr(){ };




private :

    UI_Visitor_I *myUiVisitor;

};

#endif /* SHARE_GRAPH_APP_Calc_ScaleSw_Leaf_H_ */



