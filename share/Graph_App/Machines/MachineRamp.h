/*
 * MachineRamp.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINERAMP_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINERAMP_H_

#include "I_Machine.hpp"

class Machine_Ramp  : public I_Machine{
public:
	Machine_Ramp();
	virtual ~Machine_Ramp();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();

private:
    char nameArr[5];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINERAMP_H_ */
