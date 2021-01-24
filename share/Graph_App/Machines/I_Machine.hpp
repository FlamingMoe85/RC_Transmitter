/*
 * I_Machine.hpp
 *
 *  Created on: 24.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_I_MACHINE_HPP_
#define SHARE_GRAPH_APP_MACHINES_I_MACHINE_HPP_

#include <stdint.h>
#include "../graph_app_i.h"

class I_Machine //: public Graph_Basic_I
{
public:

    virtual uint16_t GetType() = 0;
    virtual char* GetNameArr() = 0;
    virtual Graph_App_I* GetInstance() = 0;
};



#endif /* SHARE_GRAPH_APP_MACHINES_I_MACHINE_HPP_ */
