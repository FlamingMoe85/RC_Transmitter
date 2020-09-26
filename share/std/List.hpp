/*
 * List.h
 *
 *  Created on: 29.10.2016
 *      Author: Justus
 */

#ifndef SHAREDUTILS_LIST_H_
#define SHAREDUTILS_LIST_H_

#include <stdint.h>
template <class T>
class List {

public:
    typedef struct item{
        item* prv;
		T dst;
        item* nxt;
    }item;

	//List();
	List() {
		// TODO Auto-generated constructor stub
        delitem = 0;
		objZero = 0;
        itemAmt = 0;

	}

private:

	//bool ChkFrZeroObj(T* addItem);
	bool ChkFrZeroObj(T addItem)
	{
        if(itemAmt==0)
		{
            objZero = new item;
			objZero->prv = objZero;
			objZero->nxt = objZero;
			objZero->dst = addItem;
            objLast = objZero;
            itemAmt = 1;
			return true;
		}
	return false;
	}

	//void InsertFrstOrLst(T* addItem);
    item* InsertFrstOrLst(T addItem)
	{
        item* newitem;
        newitem = new item;
        newitem->dst = addItem;
        //newitem->prv = objZero->prv;
        newitem->nxt = objZero;
        newitem->prv = objLast;
        //objZero->prv->nxt = newitem;
        objZero->prv = newitem;
        objLast->nxt = newitem;
        return newitem;
	}

    //item* CutItem(unsigned int pos);
    item* CutItem(unsigned int pos)
		{
            item* tmpitem = objZero;

            for(unsigned int i=0; i<pos; i++)
			{
                tmpitem = tmpitem->nxt;
			}
            tmpitem->prv->nxt = tmpitem->nxt;
            tmpitem->nxt->prv = tmpitem->prv;
            if(pos == 0)
            {
                objZero = objZero->nxt;
            }
            if((pos+1) == itemAmt)
            {
                objLast = objLast->prv;
            }
            return tmpitem;
		}


    //void InsertitemAtLoc(unsigned int loc, item* itemToIns);
    void InsertitemAtLoc(unsigned int loc, item* itemToIns)
		{
            item* tmpitem = objZero;
			for(unsigned int i=0; i<loc; i++)
			{
                tmpitem = tmpitem->nxt;
			}
            itemToIns->nxt = tmpitem;
            itemToIns->prv = tmpitem->prv;
            tmpitem->prv->nxt = itemToIns;
            tmpitem->prv = itemToIns;
            if(loc == 0)
            {
                objZero = itemToIns;
            }
		}

    item* delitem;
    item* objZero;
    item* objLast;
    uint16_t itemAmt;

public:


	void AddFront(T addItem)
    {
        if(!ChkFrZeroObj(addItem))
        {
            objZero = InsertFrstOrLst(addItem);
            itemAmt++;
        }
	}

	void AddEnd(T addItem)
	{
        if(!ChkFrZeroObj(addItem))
        {
            objLast = InsertFrstOrLst(addItem);
            itemAmt++;
        }
	}



    void AddAtLoc(T addItem, unsigned int pos)
	{

        item* newitem;
		if(!ChkFrZeroObj(addItem))
		{
            if(itemAmt <= pos) AddEnd(addItem);
			else
			{
                newitem = new item;
                newitem->dst = addItem;
                InsertitemAtLoc(pos, newitem);
                itemAmt++;
			}
		}
	}



	T DelAtLoc(unsigned int loc)
	{
        T retObj;
        item* delitem;
        if(itemAmt < (loc+1)) return 0;
        delitem = CutItem(loc);
        itemAmt--;
        retObj = delitem->dst;
         delete delitem;
		return retObj;
	}

    void MoveItmAtLoc(unsigned int pos, int steps)
	{
        T chngCont;
        item* positem;
        item* stepitem;
        /*if(itemAmt < (pos+1)) return;
        if(((signed int)pos+steps) < 0) return;
        if(((signed int)pos+steps+1) > itemAmt) return;*/
        positem = objZero;
        for(uint16_t i=0; i<pos; i++)
        {
          positem = positem->nxt;
        }
        chngCont = positem->dst;
        stepitem = positem;
        if(steps > 0)
        {
            for(int16_t i=0; i<steps; i++)
            {
            	stepitem->dst = stepitem->nxt->dst;
                stepitem = stepitem->nxt;
            }
            stepitem->dst = chngCont;
        }
        else
        {
            for(int16_t i=0; i>steps; i--)
            {
            	stepitem->dst = stepitem->prv->dst;
                stepitem = stepitem->prv;
            }
            stepitem->dst = chngCont;
        }
	}

    const T At(unsigned int pos)
	{
		volatile unsigned int i, pos2;
		pos2 = pos;
        item* tmpitem = objZero;
        if(itemAmt < pos2) return 0;
		for(i=0; i<pos2; i++)
		{
            tmpitem = tmpitem->nxt;
		}
        return tmpitem->dst;
	}

    uint16_t Count()
	{
        return itemAmt;
    }
};

#endif /* SHAREDUTILS_LIST_H_ */
