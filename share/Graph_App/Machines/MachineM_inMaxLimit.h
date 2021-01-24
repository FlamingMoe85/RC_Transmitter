/*
 * MachineM_inMaxLimit.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINEM_INMAXLIMIT_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINEM_INMAXLIMIT_H_

#include "I_Machine.hpp"

class Machine_MinMaxLimit  : public I_Machine{
public:
	Machine_MinMaxLimit();
	virtual ~Machine_MinMaxLimit();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();

private:
    char nameArr[6];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINEM_INMAXLIMIT_H_ */
