/*
 * Machine_ScaleSwitch.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_SCALESWITCH_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_SCALESWITCH_H_

#include "I_Machine.hpp"

class Machine_ScaleSwitch : public I_Machine {
public:
	Machine_ScaleSwitch();
	virtual ~Machine_ScaleSwitch();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();

private:
    char nameArr[13];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_SCALESWITCH_H_ */
