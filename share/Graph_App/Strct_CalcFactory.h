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


#include "Machines/I_Machine.hpp"
#include "Machines/Machine_uCAdc.h"
#include "Machines/Machine_ScaleSwitch.h"
#include "Machines/Machine_CstmSw.h"
#include "Machines/Machine_Blinker.h"
#include "Machines/Machine_DeadArea.h"
#include "Machines/Machine_DynScale.h"
#include "Machines/Machine_Expo1.h"
#include "Machines/Machine_Integrator.h"
#include "Machines/Machine_InternTrim.h"
#include "Machines/Machine_Quantizer.h"
#include "Machines/MachineM_inMaxLimit.h"
#include "Machines/MachineRamp.h"

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

    char* GetNameOfMachIndex(uint16_t index);
    uint16_t GetMachTypeByIndex(uint16_t index);
    uint16_t GetAmtOfMachines();
    void AddModuleToEntryByType(uint16_t t);
    Graph_App_I* GetModuleByType(uint16_t t);

private:

    UI_Visitor_I *myUiVisitor;

    List<I_Machine*> machineList;
    Machine_uCAdc adcMachine;
    Machine_ScaleSwitch sclSwMachine;
    Machine_CstmSw cstmSwMachine;
	Machine_Blinker blinkMach;
	Machine_DeadArea deadAreaMach;
	Machine_DynScale dynScaleMach;
	Machine_Expo1 expo1Mach;
	Machine_Integrator integrMach;
	Machine_InternTrim internTrimMach;
	Machine_Quantizer quantMach;
	Machine_MinMaxLimit limiterMach;
	Machine_Ramp rampMach;
};

#endif /* SHARE_GRAPH_APP_STRCT_CALCFACTORY_H_ */
