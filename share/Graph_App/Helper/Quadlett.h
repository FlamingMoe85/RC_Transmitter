/*
 * Quadlett.h
 *
 *  Created on: 01.11.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_HELPER_QUADLETT_H_
#define SHARE_GRAPH_APP_HELPER_QUADLETT_H_

#include "I_Quadlet.hpp"
#include "../../std/List.hpp"
#include "../../std/SerializeDest_I.hpp"

class Quadlett : public I_Quadlet{
public:
	Quadlett();
	virtual ~Quadlett();

    typedef struct digChnlPair{
        uint16_t chnl;
        int16_t valPos;
        int16_t valNeg;
    }digChnlPair;


    virtual void AddChnlPair();
    virtual void DelChnlPairAt(uint16_t delLoc);
    virtual uint16_t GetAmtOfPairs();
    virtual uint16_t AddSgndToPairIn(uint16_t loc, int16_t val);
    virtual int16_t AddSgndToPairValPos(uint16_t loc, int16_t val);
    virtual int16_t AddSgndToPairValNeg(uint16_t loc, int16_t val);
    virtual uint16_t GetPos();
    virtual int16_t GetValPos();
    virtual int16_t GetValNeg();

    void SetIn(uint16_t loc, int16_t val);
    void SetValPos(uint16_t loc, int16_t val);
    void SetValNeg(uint16_t loc, int16_t val);
    int16_t CalcVal();

    uint32_t GetDigIn();

    List<digChnlPair*> myDigPairs;
    uint16_t nyActPos;
    int16_t lastValIntPos;
    int16_t lastValIntNeg;

private:

};

#endif /* SHARE_GRAPH_APP_HELPER_QUADLETT_H_ */
