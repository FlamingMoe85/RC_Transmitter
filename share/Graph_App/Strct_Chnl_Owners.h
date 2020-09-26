#ifndef STRCT_CHNL_OWNERS_H
#define STRCT_CHNL_OWNERS_H

#include "stdint.h"
#include "../std/List.hpp"

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"

class Strct_Chnl_Owners
{
public:
    Strct_Chnl_Owners();

    void ChnToChldLstFront(Graph_App_I* dest, uint16_t srcLoc);
    void ChnToChldLstEnd(Graph_App_I *dest, uint16_t srcLoc);
    void ChnToChldLstAt(Graph_App_I *dest, uint16_t srcLoc, uint16_t dstLoc);
    Graph_App_I* GetChnLstMem(uint16_t loc);

    void AddToChnLstEnd(Strct_Chnl_Owners* newCompNode);

    uint16_t SizeOfChnlList();
};

#endif // STRCT_CHNL_OWNERS_H
