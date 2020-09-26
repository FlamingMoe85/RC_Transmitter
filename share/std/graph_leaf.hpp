#ifndef GRAPH_LEAF_HPP
#define GRAPH_LEAF_HPP

#include "List.hpp"
#include "Graph_Common.hpp"

template <class T>
class Graph_Leaf : public Graph_Common<T>
{
public:
    Graph_Leaf()
    {

    }

    virtual int16_t Enter(T** ittsCurNode, uint16_t destLoc);
    virtual uint16_t AmtOfChilds();
    virtual List<T*>* GetChildList();
    virtual int16_t FindLoop(T* candi);
};


template <class T>
int16_t Graph_Leaf<T>::Enter(T** ittsCurNode, uint16_t destLoc)
{
    return 1;
}

template <class T>
uint16_t Graph_Leaf<T>::AmtOfChilds()
{
    return 0;
}

template <class T>
List<T*>* Graph_Leaf<T>::GetChildList()
{
    return 0;
}

template <class T>
int16_t Graph_Leaf<T>::FindLoop(T* candi)
{
    return 0;
}


#endif // GRAPH_LEAF_HPP
