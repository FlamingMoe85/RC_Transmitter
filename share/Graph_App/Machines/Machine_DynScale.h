/*
 * Machine_DynScale.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_DYNSCALE_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_DYNSCALE_H_

#include "I_Machine.hpp"

class Machine_DynScale  : public I_Machine{
public:
	Machine_DynScale();
	virtual ~Machine_DynScale();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();
    virtual Graph_App_I* GetInstance(uint16_t* desArr){ };

private:
    char nameArr[10];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_DYNSCALE_H_ */
