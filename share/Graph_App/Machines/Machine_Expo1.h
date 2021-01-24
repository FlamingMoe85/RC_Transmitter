/*
 * Machine_Expo1.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_EXPO1_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_EXPO1_H_

#include "I_Machine.hpp"

class Machine_Expo1  : public I_Machine{
public:
	Machine_Expo1();
	virtual ~Machine_Expo1();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();

private:
    char nameArr[7];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_EXPO1_H_ */
