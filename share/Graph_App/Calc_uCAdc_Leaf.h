/*
 * Calc_uCAdc_Leaf.h
 *
 *  Created on: 15.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_CALC_UCADC_LEAF_H_
#define SHARE_GRAPH_APP_CALC_UCADC_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Calc_uCAdc_Leaf : public Graph_Leaf<Graph_App_I> {
public:
	Calc_uCAdc_Leaf();
	virtual ~Calc_uCAdc_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr(){ };

    void IncChnlVal();
    void DecChnlVal();
    void SetChnlSel(uint16_t sel);
    uint16_t GetChnlVal();
    float GetAdc();

private:
    uint16_t myChnl;
    float value;
    UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_CALC_UCADC_LEAF_H_ */
