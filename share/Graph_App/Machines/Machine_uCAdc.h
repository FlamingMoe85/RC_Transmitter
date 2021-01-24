/*
 * Machine_uCAdc.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_UCADC_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_UCADC_H_

#include "I_Machine.hpp"

class Machine_uCAdc : public I_Machine{
public:
	Machine_uCAdc();
	virtual ~Machine_uCAdc();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();

private:
    char nameArr[4];
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_UCADC_H_ */
