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

class Calc_ScaleSw_Leaf : public Graph_Leaf<Graph_App_I> {
public:

    typedef struct digChnlPair{
        uint16_t chnl;
        int16_t valPos;
        int16_t valNeg;
    }digChnlPair;

	Calc_ScaleSw_Leaf();
	virtual ~Calc_ScaleSw_Leaf();

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
    int16_t AddSgndToPairValPos(uint16_t loc, int16_t val);
    int16_t AddSgndToPairValNeg(uint16_t loc, int16_t val);
    void SetIn(uint16_t loc, int16_t val);
    void SetValPos(uint16_t loc, int16_t val);
    void SetValNeg(uint16_t loc, int16_t val);
    int16_t CalcVal();
    uint16_t GetPos();
    int16_t GetValPos();
    int16_t GetValNeg();



private :

    List<digChnlPair*> myDigPairs;
    uint16_t nyActPos;
    int16_t lastValIntPos;
    int16_t lastValIntNeg;
    UI_Visitor_I *myUiVisitor;

};

#endif /* SHARE_GRAPH_APP_Calc_ScaleSw_Leaf_H_ */



