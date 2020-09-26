/*
 * StorageHandler_I.hpp
 *
 *  Created on: 30.05.2019
 *      Author: Justus
 */

#ifndef SHARE_STORAGEHANDLER_STORAGEHANDLER_I_HPP_
#define SHARE_STORAGEHANDLER_STORAGEHANDLER_I_HPP_
#include <stdint.h>

#define DONT_BLOCK 0
#define DO_BLOCK 1

#define DONT_UNTIE	0
#define DO_UNTIE	1

class StorageHandler_I //: public Graph_Basic_I
{
public:
virtual uint32_t GetNxtFreeBlockAdr(uint16_t block) = 0;
virtual uint32_t GetAdrFrmNxtConBlk(uint32_t startAdr) = 0;
virtual void WriteU16bAt(uint32_t adr, uint16_t val)=0;
virtual void WriteU16bSeq(uint16_t val)=0;
virtual void WriteU32bAt(uint32_t adr, uint32_t val)=0;
virtual void WriteU32bSeq(uint32_t val)=0;
virtual uint16_t GetU16bAt(uint32_t adr)=0;
virtual uint16_t GetU16bSeq()=0;
virtual uint32_t GetU32bAt(uint32_t adr)=0;
virtual uint32_t GetU32bSeq()=0;
virtual void WriteS16bAt(uint32_t adr, uint16_t val)=0;
virtual void WriteS16bSeq(uint16_t val)=0;
virtual uint16_t GetS16bAt(uint32_t adr)=0;
virtual uint16_t GetS16bSeq()=0;
virtual void FinalSaveStrobe() = 0;
virtual void Format()=0;

virtual void WriteU32bAtStraight(uint32_t adr, uint32_t val) = 0;
virtual uint32_t GetU32bAtStraight(uint32_t adr)=0;

virtual void DelChain(uint32_t startArd) = 0;

virtual uint16_t GetAmtUsablelocks() = 0;
virtual uint16_t GetAmtUsedBlock() = 0;
};

#endif /* SHARE_STORAGEHANDLER_STORAGEHANDLER_I_HPP_ */
