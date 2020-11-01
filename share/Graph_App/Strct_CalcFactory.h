/*
 * Strct_CalcFactory.h
 *
 *  Created on: 04.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_STRCT_CALCFACTORY_H_
#define SHARE_GRAPH_APP_STRCT_CALCFACTORY_H_

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

#include "Strct_Dummy_Leaf.h"
#include "Calc_Addition_Leaf.h"
#include "Calc_Multiplication_Leaf.h"
#include "Calc_uCAdc_Leaf.h"
#include "Src_CstmSw_Leaf.h"
#include "Src_InternTrim_Leaf.h"
#include "TimeCalc_Ramp_Leaf.h"
#include "Time_Blinker_Leaf.h"
#include "Calc_ScaleSw_Leaf.h"
#include "Calc_Quantizer_Leaf.h"
#include "Clac_DeadArea_Leaf.hpp"
#include "Calc_MinMaxLimit_Leaf.h"

//#include "Strct_PoolOwners.h"

class Strct_CalcFactory : public Graph_Node<Graph_App_I>{
public:
	Strct_CalcFactory();
	virtual ~Strct_CalcFactory();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void Show();
private:
    Strct_Dummy_Leaf addDummy;
    Strct_Dummy_Leaf mulDummy;
    Strct_Dummy_Leaf adcDummy;
    Strct_Dummy_Leaf cstmSwDummy;
    Strct_Dummy_Leaf intTrimDummy;
    Strct_Dummy_Leaf timeCalcRampDummy;
    Strct_Dummy_Leaf timeBlinkDummy;
    Strct_Dummy_Leaf scaleSwDummy;
    Strct_Dummy_Leaf quantizerDummy;
    Strct_Dummy_Leaf deadSpanDummy;
    Strct_Dummy_Leaf  limiterDummy;
    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_STRCT_CALCFACTORY_H_ */
