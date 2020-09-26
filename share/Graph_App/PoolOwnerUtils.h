#ifndef STRCT_POOLOWNERS_H
#define STRCT_POOLOWNERS_H

#include "stdint.h"
#include "../std/List.hpp"

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"

class Strct_Compo_Node;

class PoolOwnerUtils
{
public:
	PoolOwnerUtils();

    void PoolToChldLstFront(Graph_App_I* dest, uint16_t srcLoc);
    void PoolToChldLstEnd(Graph_App_I *dest, uint16_t srcLoc);
    void PoolToChldLstAt(Graph_App_I *dest, uint16_t srcLoc, uint16_t dstLoc);
    Graph_App_I* GetPoolLstMem(uint16_t loc);
    List<Strct_Compo_Node*>* GetPoolLst();

    void AddToPoolLstEnd(Strct_Compo_Node* newCompNode);
    void AddtoPoolLstFrnt(Strct_Compo_Node* newCompNode);
    void AddToPoolLstAt(Strct_Compo_Node* newCompNode, uint16_t pos);

    uint16_t SizeOfPoolList();
};

#endif // STRCT_POOLOWNERS_H
