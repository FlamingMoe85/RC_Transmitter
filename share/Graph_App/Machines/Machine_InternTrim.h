/*
 * Machine_InternTrim.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_INTERNTRIM_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_INTERNTRIM_H_

#include "I_Machine.hpp"

class Machine_InternTrim  : public I_Machine{
public:
	Machine_InternTrim();
	virtual ~Machine_InternTrim();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();

private:
    char nameArr[6];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_INTERNTRIM_H_ */
