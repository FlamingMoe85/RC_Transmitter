/*
 * Machine_DeadArea.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_DEADAREA_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_DEADAREA_H_

#include "I_Machine.hpp"

class Machine_DeadArea : public I_Machine{
public:
	Machine_DeadArea();
	virtual ~Machine_DeadArea();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();
    virtual Graph_App_I* GetInstance(uint16_t* desArr){ };

private:
    char nameArr[10];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_DEADAREA_H_ */
