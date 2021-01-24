/*
 * Machine_Integrator.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_INTEGRATOR_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_INTEGRATOR_H_

#include "I_Machine.hpp"

class Machine_Integrator  : public I_Machine{
public:
	Machine_Integrator();
	virtual ~Machine_Integrator();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();

private:
    char nameArr[11];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_INTEGRATOR_H_ */
