/*
 * Machine_CstmSw.h
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_MACHINE_CSTMSW_H_
#define SHARE_GRAPH_APP_MACHINES_MACHINE_CSTMSW_H_

#include "I_Machine.hpp"

class Machine_CstmSw : public I_Machine{
public:
	Machine_CstmSw();
	virtual ~Machine_CstmSw();

    virtual uint16_t GetType();
    virtual char* GetNameArr();
    virtual Graph_App_I* GetInstance();
    virtual Graph_App_I* GetInstance(uint16_t* desArr);

private:
    char nameArr[14];
    uint16_t dataCntr;
    uint16_t* dataArr;
};

#endif /* SHARE_GRAPH_APP_MACHINES_MACHINE_CSTMSW_H_ */
