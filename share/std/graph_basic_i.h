#ifndef GRAPH_BASIC_I_H
#define GRAPH_BASIC_I_H

#include <stdint.h>
#include "List.hpp"

class Graph_Basic_I
{
public:

virtual int16_t Enter(Graph_Basic_I** ittsCurNode, uint16_t destLoc) = 0;
virtual int16_t Esc(Graph_Basic_I **ittsCurNode) = 0;
virtual void SetEntry(Graph_Basic_I* ent) = 0;
virtual Graph_Basic_I* GetEntry() = 0;
virtual uint16_t AmtOfChilds() = 0;
virtual List<Graph_Basic_I*>* GetChildList() = 0;
virtual int16_t FindLoop(Graph_Basic_I* candi) = 0;


};
#endif // GRAPH_BASIC_I_H
