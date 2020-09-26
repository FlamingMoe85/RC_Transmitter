#ifndef GRAPHAPPCOMMONS_H
#define GRAPHAPPCOMMONS_H

#include "Graph_App_I.h"
#include "../globaldefinesshare.h"

class GraphAppCommons
{
public:
    GraphAppCommons();

    virtual char* GetNameArr();

private:

    char nameArr[NAME_LENGTH];
};

#endif // GRAPHAPPCOMMONS_H
