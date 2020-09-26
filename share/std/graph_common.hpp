#ifndef GRAPH_COMMON_HPP
#define GRAPH_COMMON_HPP

#include <stdint.h>

template <class T>
class Graph_Common : public T
{
public:
	Graph_Common()
    {
        myEntry = NULL;
    }

    virtual void RunKindaConst();
    virtual int16_t Esc(T **ittsCurNode);
    virtual void SetEntry(T* ent);
    virtual T* GetEntry();
    virtual void SetCurrentNodePtrLoc(T** n);
    virtual T** GetCurNodePtrLoc();

private:
        T* myEntry;
        T** curNodePtrLocation;
};

template <class T>
void Graph_Common<T>::RunKindaConst()
{
    myEntry = NULL;
}

template <class T>
int16_t Graph_Common<T>::Esc(T **ittsCurNode)
{
    if(myEntry == NULL)return 1;
    *ittsCurNode = myEntry;
    return 0;
}

template <class T>
void Graph_Common<T>::SetEntry(T* ent)
{
    myEntry = ent;
}

template <class T>
T* Graph_Common<T>::GetEntry()
{
    return myEntry;
}

template <class T>
void Graph_Common<T>::SetCurrentNodePtrLoc(T** n)
{
	curNodePtrLocation = n;
}

template <class T>
T** Graph_Common<T>::GetCurNodePtrLoc()
{
	return curNodePtrLocation;
}

#endif // GRAPH_COMMON_HPP
