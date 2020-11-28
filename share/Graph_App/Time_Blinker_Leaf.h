/*
 * Time_Blinker_Leaf.h
 *
 *  Created on: 27.12.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_TIME_BLINKER_LEAF_H_
#define SHARE_GRAPH_APP_TIME_BLINKER_LEAF_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../std/List.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "../SystickConsumerBase.h"
#include "PoolOwnerUtils.h"
#include "Strct_Compo_Node.h"

#include "Helper/Source.h"

class Time_Blinker_Leaf  : public SystickConsumerBase, public Source{//, public Graph_Leaf<Graph_App_I>,  public PoolOwnerUtils{
public:

    typedef struct timeSlot{
        uint16_t dur;
        int16_t val;
    }timeSlot;

	Time_Blinker_Leaf();
	virtual ~Time_Blinker_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);

    void AddSlot();
    void DelSlotAt(uint16_t delLoc);
    uint16_t GetAmtOfSlots();
    uint16_t AddSgndToSlotDur(uint16_t loc, int16_t val);
    uint16_t AddSgndToSlotVal(uint16_t loc, int16_t val);
    void SetBlnkDur(uint16_t loc, uint16_t val);
    void SetBlnkVal(uint16_t loc, int16_t val);
    int16_t CalcVal();
    uint16_t GetPos();
    int16_t GetVal();

    virtual void TickNotify();


private :

    List<timeSlot*> mySlots;
    int16_t lastValInt;
    uint16_t noteCntr;
    uint16_t curSlot;

   // Strct_Compo_Node* trigCompo;
    //UI_Visitor_I *myUiVisitor;
};

#endif /* SHARE_GRAPH_APP_TIME_BLINKER_LEAF_H_ */
