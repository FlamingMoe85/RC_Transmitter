/*
 * Src_InternTrim_Leaf.h
 *
 *  Created on: 07.09.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_SRC_INTERNTRIM_LEAF_H_
#define SHARE_GRAPH_APP_SRC_INTERNTRIM_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../std/List.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"


class Src_InternTrim_Leaf  : public Graph_Leaf<Graph_App_I>{
public:
	Src_InternTrim_Leaf();
	virtual ~Src_InternTrim_Leaf();

	virtual void Run(float* val, uint32_t itteration);
	    virtual void Show(UI_Visitor_I* UiVisitor);
	    virtual UI_Visitor_I* GetVisitor();
	    virtual void Serialize(SerializeDest_I* SerDest);
	    virtual void Deserialize(SerializeDest_I* SerDest);
	    virtual void NullSerCntr(){ };

	    void Notify(uint16_t trimDigs);
	    uint16_t GetTrimVal();
	    void SetTrimVal(uint16_t val);
	    void IncTrim();
	    void DecTrim();
	    uint16_t IncPairSel();
	    uint16_t DecPairSel();
	    void SetPairSel(uint16_t sel);
	uint16_t GetPairSel();

	void SetNotifierPos(uint16_t notePos);
	uint16_t GetNotifierPos();

private:
	uint16_t pairSel;
	uint16_t notifierPos;
	int16_t trimVal;
	float trimValfloat;
	uint16_t myTrimDigs;
    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_SRC_INTERNTRIM_LEAF_H_ */
