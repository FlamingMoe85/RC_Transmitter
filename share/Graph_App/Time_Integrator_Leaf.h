/*
 * Time_Integrator_Leaf.h
 *
 *  Created on: 31.12.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_TIME_INTEGRATOR_LEAF_H_
#define SHARE_GRAPH_APP_TIME_INTEGRATOR_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Time_Integrator_Leaf : public Graph_Leaf<Graph_App_I>{
public:
	Time_Integrator_Leaf();
	virtual ~Time_Integrator_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    void Show();
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void AddSngMax(int16_t v);
    void SetMax(uint16_t maxSet);
    uint16_t GetMax();

    void AddSngMin(int16_t v);
    void SetMin(int16_t minSet);
    int16_t GetMin();

    void AddSngRate(int16_t v);
    void SetRate(uint16_t rateSet);
    uint16_t GetRate();

    void AddSngDef(int16_t v);
    void SetDef(int16_t defSet);
    int16_t GetDef();

    void AddSngResSel(int16_t v);
    void SetResSel(uint16_t resSelSet);
    uint16_t GetResSel();

    void ResetIval();

private:
    UI_Visitor_I *myUiVisitor;
    int16_t max, min, def;
    uint16_t rate, resSel;
    float maxF, minF, rateF, defF;
	float iValue;
	uint32_t resPin;
};

#endif /* SHARE_GRAPH_APP_TIME_INTEGRATOR_LEAF_H_ */
