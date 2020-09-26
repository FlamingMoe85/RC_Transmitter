#include "PoolOwnerUtils.h"
static List<Strct_Compo_Node*> poolList;

PoolOwnerUtils::PoolOwnerUtils()
{

}

void PoolOwnerUtils::PoolToChldLstFront(Graph_App_I *dest, uint16_t srcLoc)
{
    if(((Graph_App_I*)poolList.At(srcLoc))->FindLoop(dest) == 0)
    {
        dest->GetChildList()->AddFront((Graph_App_I*)poolList.At(srcLoc));
    }
    else
    {
    }
}

void PoolOwnerUtils::PoolToChldLstEnd(Graph_App_I *dest, uint16_t srcLoc)
{
    if(((Graph_App_I*)poolList.At(srcLoc))->FindLoop(dest) == 0)
    {
        dest->GetChildList()->AddEnd((Graph_App_I*)poolList.At(srcLoc));
    }
    else
    {
    }
}

void PoolOwnerUtils::PoolToChldLstAt(Graph_App_I *dest, uint16_t srcLoc, uint16_t dstLoc)
{
    if(((Graph_App_I*)poolList.At(srcLoc))->FindLoop(dest) == 0)
    {
        dest->GetChildList()->AddAtLoc((Graph_App_I*)poolList.At(srcLoc), dstLoc);
    }
    else
    {
    }
}

uint16_t PoolOwnerUtils::SizeOfPoolList()
{
    return poolList.Count();
}

Graph_App_I* PoolOwnerUtils::GetPoolLstMem(uint16_t loc)
{
    return (Graph_App_I*)(poolList.At(loc));
}


void PoolOwnerUtils::AddToPoolLstEnd(Strct_Compo_Node* newCompNode)
{
    poolList.AddEnd(newCompNode);
}

void PoolOwnerUtils::AddtoPoolLstFrnt(Strct_Compo_Node* newCompNode)
{
    poolList.AddEnd(newCompNode);
}
void PoolOwnerUtils::AddToPoolLstAt(Strct_Compo_Node* newCompNode, uint16_t pos)
{
    poolList.AddAtLoc(newCompNode,pos);
}

List<Strct_Compo_Node*>* PoolOwnerUtils::GetPoolLst()
{
	return &poolList;
}
