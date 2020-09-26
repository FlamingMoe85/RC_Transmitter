/*
 * StorageHandler.h
 *
 *  Created on: 30.05.2019
 *      Author: Justus
 */

#ifndef STORAGE_STORAGEHANDLER_H_
#define STORAGE_STORAGEHANDLER_H_

#include "C:\RC_Transmitter\share\StorageHandler\StorageHandler_I.hpp"

#define AMT_OF_BLOCKS	96
#define W16_PER_BLOCK	32
#define BYTES_PER_BLOCK 62

class StorageHandler : public StorageHandler_I{
public:
	StorageHandler();
	virtual ~StorageHandler();

	virtual void WriteU16bAt(uint32_t adr, uint16_t val);
	virtual void WriteU16bSeq(uint16_t val);
	virtual void WriteU32bAt(uint32_t adr, uint32_t val);
	virtual void WriteU32bSeq(uint32_t val);
	virtual uint16_t GetU16bAt(uint32_t adr);
	virtual uint16_t GetU16bSeq();
	virtual uint32_t GetU32bAt(uint32_t adr);
	virtual uint32_t GetU32bSeq();
	virtual void WriteS16bAt(uint32_t adr, uint16_t val);
	virtual void WriteS16bSeq(uint16_t val);
	virtual uint16_t GetS16bAt(uint32_t adr);
	virtual uint16_t GetS16bSeq();
	virtual void Format();
	virtual void DelChain(uint32_t startArd);

	virtual void WriteU32bAtStraight(uint32_t adr, uint32_t val);
	virtual uint32_t GetU32bAtStraight(uint32_t adr);

	virtual uint32_t GetNxtFreeBlockAdr(uint16_t block);
	virtual uint32_t GetAdrFrmNxtConBlk(uint32_t startAdr);

	void FinalSaveStrobe();
	void NewAccessStrobe();

	virtual uint16_t GetAmtUsablelocks();
	virtual uint16_t GetAmtUsedBlock();

private:

	/*virtual*/ void SetReadStartAdr(uint32_t startAdr);
	/*virtual*/ uint32_t GetFirstUsedBlock();
	/*virtual*/ void FreeBlock(uint32_t freeBlock);
	/*virtual*/ uint32_t GetNxtBlock(uint32_t curBlock, uint16_t untie);

	uint16_t startFlag;
	uint32_t currentBlock;
	uint32_t currentAdr;
	uint32_t currentWord32;
	uint16_t currentWord16Cntr;
};

#endif /* STORAGE_STORAGEHANDLER_H_ */
