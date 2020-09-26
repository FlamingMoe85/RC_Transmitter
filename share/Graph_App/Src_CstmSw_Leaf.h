/*
 * Src_CstmSw_Leaf.h
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_SRC_CSTMSW_LEAF_H_
#define SHARE_GRAPH_APP_SRC_CSTMSW_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../std/List.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Src_CstmSw_Leaf : public Graph_Leaf<Graph_App_I> {
public:

    typedef struct digChnlPair{
        uint16_t chnl;
        int16_t val;
    }digChnlPair;

	Src_CstmSw_Leaf();
	virtual ~Src_CstmSw_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr(){ };

    void AddChnlPair();
    void DelChnlPairAt(uint16_t delLoc);
    uint16_t GetAmtOfPairs();
    uint16_t AddSgndToPairIn(uint16_t loc, int16_t val);
    uint16_t AddSgndToPairVal(uint16_t loc, int16_t val);
    int16_t CalcVal();
    uint16_t GetPos();
    int16_t GetVal();
    void SetPairIn(uint16_t loc, int16_t val);
    void SetPairVal(uint16_t loc, int16_t val);



private :

    List<digChnlPair*> myDigPairs;
    uint16_t nyActPos;
    int16_t lastValInt;
    UI_Visitor_I *myUiVisitor;

};

#endif /* SHARE_GRAPH_APP_SRC_CSTMSW_LEAF_H_ */


