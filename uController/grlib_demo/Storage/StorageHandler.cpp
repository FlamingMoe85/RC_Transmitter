/*
 * StorageHandler.cpp
 *
 *  Created on: 30.05.2019
 *      Author: Justus
 */

#include "StorageHandler.h"

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/eeprom.h"

/*
 * Used Memory Table : uint32 [0 to 2]
 * Amount of Models uint32 [3]
 * First Model uint32 [4]
 * Current Model [5]
 */

StorageHandler::StorageHandler() {
	// TODO Auto-generated constructor stub
	currentBlock = 0;
	currentAdr = 0;
	currentWord32 = 0;
	currentWord16Cntr = 0;
}

StorageHandler::~StorageHandler() {
	// TODO Auto-generated destructor stub
}
/*
void StorageHandler::SetCurModAdrs(uint32_t curModAdr)
{
	EEPROMProgram(&curModAdr, 5*4, 4);
}
*/
/*
uint32_t StorageHandler::GetCurModAdrs()
{
		uint32_t t;
		EEPROMRead(&t, 5*4, 4);
		return t;
}
*/
/*
uint32_t StorageHandler::GetAmtOfModels()
{
	uint32_t t;
	EEPROMRead(&t, 3*4, 4);
	return t;
}
*/
/*
void StorageHandler::SetAmtOfModels(uint32_t amt)
{
	EEPROMProgram(&amt, 3*4, 4);
}
*/
/*
uint32_t StorageHandler::GetFirstModelAdrs()
{
	uint32_t t;
	EEPROMRead(&t, 4*4, 4);
	return t;
}
*/
/*
void StorageHandler::SetFirstModAdrs(uint32_t adr)
{
	EEPROMProgram(&adr, 4*4, 4);
}
*/

uint16_t StorageHandler::GetAmtUsablelocks()
{
	return 95;
}

uint16_t StorageHandler::GetAmtUsedBlock()
{
	uint16_t amtUsed =0;
	uint32_t table, bitMask = 1, freeWordSeek;
	for(freeWordSeek=0; freeWordSeek<3;)
	{
		bitMask = 1;
		EEPROMRead(&table, freeWordSeek*4, 4);
		freeWordSeek++;
		for(uint16_t curBit=0; curBit < 32; curBit++)
		{
			if((table & bitMask) == bitMask)amtUsed++;
			bitMask *= 2;
		}
	}
	return amtUsed;
}

uint32_t StorageHandler::GetNxtBlock(uint32_t curBlock, uint16_t untie)
{
	uint32_t t, unt;
	unt = 0;
	EEPROMRead(&t, curBlock+60, 4);
	if(untie == DO_UNTIE)
	{
		EEPROMProgram(&unt, curBlock+60, 4);
	}
	return ((t & 0xFFFF0000) >> 16);
}

void StorageHandler::FreeBlock(uint32_t freeBlock)
{
	uint32_t freeBit = 1, content;
	if(freeBlock > 63)
	{
		freeBlock -= 64;
		for(uint16_t i=0; i<freeBlock; i++)
		{
			freeBit = freeBit << 1;
		}
		freeBit = freeBit ^ 0xFFFFFFFF;
		EEPROMRead(&content, 2*4, 4);
		content = content & freeBit;
		EEPROMProgram(&content, 2*4, 4);
	}
	else if(freeBlock > 31)
	{
		freeBlock -= 32;
		for(uint16_t i=0; i<freeBlock; i++)
		{
			freeBit = freeBit << 1;
		}
		freeBit = freeBit ^ 0xFFFFFFFF;
		EEPROMRead(&content, 1*4, 4);
		content = content & freeBit;
		EEPROMProgram(&content, 1*4, 4);
	}
	else
	{
		for(uint16_t i=0; i<freeBlock; i++)
		{
			freeBit = freeBit << 1;
		}
		freeBit = freeBit ^ 0xFFFFFFFF;
		EEPROMRead(&content, 0, 4);
		content = content & freeBit;
		EEPROMProgram(&content, 0, 4);
	}
}

void StorageHandler::DelChain(uint32_t startArd)
{
	uint32_t nxtBlk = startArd;
	do
	{
		startArd = nxtBlk;
		nxtBlk = GetNxtBlock(startArd, DO_UNTIE);
		FreeBlock(startArd/64);
	}while(nxtBlk != 0);
}

 uint32_t StorageHandler::GetFirstUsedBlock()
 {

 }

uint32_t StorageHandler::GetAdrFrmNxtConBlk(uint32_t startAdr)
 {
	return GetNxtBlock(startAdr, DONT_UNTIE);
 }

 uint32_t StorageHandler::GetNxtFreeBlockAdr(uint16_t block)
 {
	 // [7-6-5-4-3-2-1-0] [15-14-13-12-11-10-9-8]....
	 static uint32_t freeVal = 0;
	 static uint16_t freeWordSeek;
	 static uint32_t freeBitSeek = 1;
	static uint16_t bitCnt = 0;

	freeVal = 0;
	freeWordSeek = 0;
	freeBitSeek = 1;
	bitCnt = 0;

	 for(freeWordSeek=0; freeWordSeek<3;)
	 {
		 EEPROMRead(&freeVal, freeWordSeek*4, 4);
		 if(freeVal != 0xFFFFFFFF) break;
		 freeWordSeek++;
	 }
	 for(bitCnt=0; bitCnt<32; bitCnt++)
	 {
		 /*
		  * freeVal ist das Bitmuster der Blocktabelle
		  * freeBitSeek ist ein Wert mit EINEM Bit log. 1 und lokalisiert den nächsten freien Block
		  *
		  * Wenn folgende Bedingung FALSE ist, ist der NÄCHSTE freie Block in der Blocktabelle gefunden worden
		  */
		 if((freeBitSeek & freeVal) != freeBitSeek)//es gibt free_BIT_seek und free_WORD_seek!!!
		 {
			 if(block == DO_BLOCK)
			 {
				 freeVal |= freeBitSeek;
				 EEPROMProgram(&freeVal, freeWordSeek*4, 4);
				 startFlag = 1;
			 }
			 break;
		 }
		 freeBitSeek = freeBitSeek << 1;
	 }
	 /*
	  * Der Speicher ist byteweise angelegt, kann aber nur 32 bitweise adressiert werden. Das heißt, Adressen werden in 4´er Schritten
	  * inkrementiert [0, 4, 8, 12 etc]. Das Speicherkonzept sieht vor, immer 16 dieser Adresseinheiten als Block zu betrachten - also
	  * 16 mal 4 Byte große Speichereinheiten.
	  * Daher repräsemtiert jedes Bit in der Blocktabelle ein Adressinkrement von 64
	  *
	  * => 16*4 = 64
	  */
	 currentBlock = (freeWordSeek*32)*64 + bitCnt*64; // 32->
	 return (currentBlock);
 }

 void StorageHandler::FinalSaveStrobe()
 {
	 if((currentWord16Cntr & 1)==1)
	 {
		 EEPROMProgram(&currentWord32, currentAdr, 4);
	 }
 }

 void StorageHandler::NewAccessStrobe()
 {
	 startFlag = 0;
 }

 void StorageHandler::SetReadStartAdr(uint32_t startAdr)
 {
	 currentAdr = startAdr;
	 NewAccessStrobe();
 }

 void StorageHandler::WriteU16bAt(uint32_t adr, uint16_t val)
 {
	 currentAdr = adr;
	 currentWord16Cntr = 1;
	 currentWord32 = val;
 }

 void StorageHandler::WriteU16bSeq(uint16_t val)
 {
	 uint32_t tmpCurBlk;

	 if(startFlag == 0)
	 {
		 WriteU16bAt(GetNxtFreeBlockAdr(DO_BLOCK), val);
		 startFlag = 1;
	 }
	 else
	 {

		 if(currentWord16Cntr & 1)
		 {
			 if(currentWord16Cntr < 31)
			 {
				 currentWord32 |= (val<<16);
				 EEPROMProgram(&currentWord32, currentAdr, 4);
				 currentAdr += 4;
				 currentWord16Cntr++;
			 }
			 else
			 {
				 tmpCurBlk = GetNxtFreeBlockAdr(DO_BLOCK);
				 currentWord32 |= ( ((uint16_t)tmpCurBlk) <<16);
				 EEPROMProgram(&currentWord32, currentAdr, 4);
				 WriteU16bAt(tmpCurBlk, val);

			 }
		 }
		 else
		 {
			 currentWord32 = val;
			 currentWord16Cntr++;
		 }
	 }
 }

uint32_t StorageHandler::GetU32bAtStraight(uint32_t adr)
 {
	uint32_t retVal;
	EEPROMRead(&retVal, adr, 4);
	return retVal;
 }

void StorageHandler::WriteU32bAtStraight(uint32_t adr, uint32_t val)
{
	EEPROMProgram(&val, adr, 4);
}

void StorageHandler::WriteU32bAt(uint32_t adr, uint32_t val)
{
	uint16_t highVal, lowVal;
	lowVal = val & 0xFFFF;
	highVal = ((val >> 16) & 0xFFFF);
	WriteU16bAt(adr, lowVal);
	WriteU16bSeq(highVal);
}


void StorageHandler::WriteU32bSeq(uint32_t val)
{
	uint16_t highVal, lowVal;
	lowVal = val & 0xFFFF;
	highVal = ((val >> 16)& 0xFFFF);
	WriteU16bSeq(lowVal);
	WriteU16bSeq(highVal);
}

 uint16_t StorageHandler::GetU16bAt(uint32_t adr)
 {
	 currentAdr = adr;
	 currentWord16Cntr = 1;
	 startFlag = 1;
	 EEPROMRead(&currentWord32, currentAdr, 4);
	 return (uint16_t)(currentWord32 & 0xFFFF);
 }

 uint16_t StorageHandler::GetU16bSeq()
 {
	 uint16_t retVal = 0;

	 if(startFlag == 0)
	 {
		 startFlag = 1;
		 return  GetU16bAt(currentAdr);
	 }
	 else
	 {

		 if((currentWord16Cntr & 1) == 1)
		 {

			 if(currentWord16Cntr == 31)
			 {
				 currentWord16Cntr = 0;
				 retVal = GetU16bAt((currentWord32 & 0xFFFF0000)>>16);
			 }
			 else
			 {
				 retVal = ((currentWord32 & 0xFFFF0000)>>16);
				 currentWord16Cntr++;
			 }
		 }
		 else
		 {
			 currentAdr += 4;
			 EEPROMRead(&currentWord32, currentAdr, 4);
			 retVal = (uint16_t)(currentWord32 & 0xFFFF);
			 currentWord16Cntr++;
		 }

		 return retVal;
	 }
 }

uint32_t StorageHandler::GetU32bAt(uint32_t adr)
{
	uint16_t highVal, lowVal;
	uint32_t retVal;

	lowVal = GetU16bAt(adr);
	highVal = GetU16bSeq();

	retVal = (highVal << 16) + lowVal;
	return retVal;
}

uint32_t StorageHandler::GetU32bSeq()
{
	uint16_t highVal, lowVal;
	uint32_t retVal;

	lowVal = GetU16bSeq();
	highVal = GetU16bSeq();

	retVal = (highVal << 16) + lowVal;
	return retVal;
}

 void StorageHandler::WriteS16bAt(uint32_t adr, uint16_t val)
 {
	 uint16_t tmpVal = 0;
	 tmpVal |= val;
	 WriteU16bAt(adr, tmpVal);
 }

 void StorageHandler::WriteS16bSeq(uint16_t val)
 {
	 uint16_t tmpVal = 0;
	 tmpVal |= val;
	 WriteU16bSeq(tmpVal);
 }

 uint16_t StorageHandler::GetS16bAt(uint32_t adr)
 {
	int16_t tmpVal = 0;
	tmpVal |= GetU16bAt(adr);
	return tmpVal;
 }

 uint16_t StorageHandler::GetS16bSeq()
 {
		int16_t tmpVal = 0;
		tmpVal |= GetU16bSeq();
		return tmpVal;
 }

 void StorageHandler::Format()
 {
	 currentWord32 = 1;
	 EEPROMProgram(&currentWord32, 0, 4);
	 currentWord32 = 0;
	 for(uint16_t i=1; i<1535; i++)
	 {
		 EEPROMProgram(&currentWord32, i*4, 4);
	 }
 }
