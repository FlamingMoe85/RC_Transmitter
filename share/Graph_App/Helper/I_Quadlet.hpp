/*
 * I_Quadlet.hpp
 *
 *  Created on: 31.10.2020
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_HELPER_I_QUADLET_HPP_
#define SHARE_GRAPH_APP_HELPER_I_QUADLET_HPP_

class I_Quadlet //: public Graph_Basic_I
{
public:

    virtual void AddChnlPair() = 0;
    virtual void DelChnlPairAt(uint16_t delLoc) = 0;
    virtual uint16_t GetAmtOfPairs() = 0;
    virtual uint16_t AddSgndToPairIn(uint16_t loc, int16_t val) = 0;
    virtual int16_t AddSgndToPairValPos(uint16_t loc, int16_t val) = 0;
    virtual int16_t AddSgndToPairValNeg(uint16_t loc, int16_t val) = 0;
    virtual void SetIn(uint16_t loc, int16_t val) = 0;
    virtual  void SetValPos(uint16_t loc, int16_t val) = 0;
    virtual void SetValNeg(uint16_t loc, int16_t val) = 0;
    virtual  int16_t CalcVal() = 0;
    virtual uint16_t GetPos() = 0;
    virtual int16_t GetValPos() = 0;
    virtual int16_t GetValNeg() = 0;
};



#endif /* SHARE_GRAPH_APP_HELPER_I_QUADLET_HPP_ */
