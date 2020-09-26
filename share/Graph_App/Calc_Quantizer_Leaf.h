/*
 * Calc_Quantizer_Leaf.h
 *
 *  Created on: 30.03.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_CALC_QUANTIZER_LEAF_H_
#define SHARE_GRAPH_APP_CALC_QUANTIZER_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../std/List.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Calc_Quantizer_Leaf : public Graph_Leaf<Graph_App_I>  {
public:

	typedef struct quantPair{
	        int16_t mark;
	        int16_t val;
	    }quantPair;

	Calc_Quantizer_Leaf();
	virtual ~Calc_Quantizer_Leaf();

	virtual void Run(float* val, uint32_t itteration);
	virtual void Show(UI_Visitor_I* UiVisitor);
	virtual UI_Visitor_I* GetVisitor();
	virtual void Serialize(SerializeDest_I* SerDest);
	virtual void Deserialize(SerializeDest_I* SerDest);
	virtual void NullSerCntr(){ };

	void AddMark();
	void DelMark(uint16_t delLoc);

	int16_t AddSgndToLevel(uint16_t levSel, int16_t val);
	int16_t AddSgndToLevelVal(uint16_t levSel, int16_t val);
    void SetLevelAt(uint16_t levSel, int16_t val);
    void SetValAt(uint16_t levSel, int16_t val);
	uint16_t GetAmtOfPairs();
	uint16_t GetPos();
	int16_t GetVal();


private :

    List<quantPair*> myLevelPairs;
    uint16_t nyActPos;
    int16_t lastValInt;
    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_CALC_QUANTIZER_LEAF_H_ */
