#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include "List.hpp"
#include "Graph_Common.hpp"


template <class T>
class Graph_Node : public Graph_Common<T>
{
public:
    Graph_Node()
    {

    }

    virtual int16_t Enter(T** ittsCurNode, uint16_t destLoc);
    virtual uint16_t AmtOfChilds();
    virtual List<T*>* GetChildList();
    virtual int16_t FindLoop(T* candi);


private:
    List<T*> myChilds;
};


template <class T>
int16_t Graph_Node<T>::Enter(T **ittsCurNode, uint16_t destLoc)
{
    if(myChilds.Count() < (destLoc+1)) return 1;
    myChilds.At(destLoc)->SetEntry(*ittsCurNode);
    (*ittsCurNode) = myChilds.At(destLoc);
    myChilds.At(destLoc)->SetCurrentNodePtrLoc(ittsCurNode);
    return 0;
}

template <class T>
uint16_t Graph_Node<T>::AmtOfChilds()
{
    return myChilds.Count();
}

template <class T>
int16_t Graph_Node<T>::FindLoop(T* candi)

{
    if(candi == (T*)this)
    {
        return 1;
    }
    if(candi == 0) candi = (T*)this;
    for(uint16_t i=0; i<myChilds.Count(); i++)
    {
        if(myChilds.At(i)->FindLoop(candi) == 1)
        {
            return 1;

        }
    }
    return 0;
}

template <class T>
List<T*>* Graph_Node<T>::GetChildList()
{
    return &myChilds;
}

#endif // GRAPH_NODE_H
