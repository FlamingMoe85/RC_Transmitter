/*
 * Machine_Blinker.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_BLINKER_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_BLINKER_H_

#include "I_Machine.hpp"
#include "I_MachineWizard.hpp"

class Machine_Blinker  : public I_Machine{
public:
	Machine_Blinker();
	virtual ~Machine_Blinker();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();
    virtual Graph_App_I* GetInstance(uint16_t* desArr){ };

    virtual uint16_t GetUint16(){ };
    virtual int16_t GetInt16(){ };

private:
    char nameArr[8];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_BLINKER_H_ */
