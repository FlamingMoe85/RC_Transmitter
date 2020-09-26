/*
 * TimeCalc_Ramp_Leaf.h
 *
 *  Created on: 15.11.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_TIMECALC_RAMP_LEAF_H_
#define SHARE_GRAPH_APP_TIMECALC_RAMP_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "../SystickConsumerBase.h"

class TimeCalc_Ramp_Leaf : public Graph_Leaf<Graph_App_I>, public SystickConsumerBase{
public:
	TimeCalc_Ramp_Leaf();
	virtual ~TimeCalc_Ramp_Leaf();

	virtual void Run(float* val, uint32_t itteration);
	    virtual void Show(UI_Visitor_I* UiVisitor);
	    virtual UI_Visitor_I* GetVisitor();
	    virtual void Serialize(SerializeDest_I* SerDest);
	    virtual void Deserialize(SerializeDest_I* SerDest);
	    virtual void NullSerCntr(){ };

	    virtual void TickNotify();

	    void SetPercPerSec(uint16_t sel, uint16_t val);
	    uint16_t GetPercPerSec(uint16_t sel);
	    void SetNullPoint(int16_t nPoint);
	    int16_t GetNullPoint();

#define ABOVE_RISING	0
#define ABOVE_FALLING	1
#define BELOW_RISING	2
#define BELOW_FALLING	3

private:
	    typedef struct stepPair_t{
	        uint16_t percPerSec;
	        float deltaStep;
	    }stepPair_t;
	    stepPair_t stepPairs[4];
	    int16_t nullPoint;
	    float noteCntr;
	    float lastOut;
	    UI_Visitor_I *myUiVisitor;
	    float diff;
};

#endif /* SHARE_GRAPH_APP_TIMECALC_RAMP_LEAF_H_ */
