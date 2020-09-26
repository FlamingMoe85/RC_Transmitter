/*
 * ModelManager.cpp
 *
 *  Created on: 30.05.2019
 *      Author: Justus
 */

#include "ModelManager.h"
#include "driverlib/eeprom.h"
/* # Head
 * Prv Mod uint32 	[0]
 * this Mod uint32	[1]
 * Nxt Mod uint32 	[2]
 * Name uint
 */

ModelManager::ModelManager() {
	// TODO Auto-generated constructor stub

}

ModelManager::~ModelManager() {
	// TODO Auto-generated destructor stub
}


void ModelManager::PrepForOverwrite(uint32_t modNmbr)
{
	char keepName[NAME_LENGTH];
	uint32_t modAdr, nxtConBlk, d1, d2, d3;
	modAdr = CreateModAdr(modAdr);
    GetNameOfModel(&keepName[0], modNmbr);
    nxtConBlk = myMemHandler->GetAdrFrmNxtConBlk(modAdr);

    d1 = myMemHandler->GetU32bAt(modAdr);
    d2 = myMemHandler->GetU32bSeq();
    d3 = myMemHandler->GetU32bSeq();

    myMemHandler->DelChain(nxtConBlk);
    //dummy1 = myMemHandler->GetU32bAt(modAdr+8);
    //myMemHandler->WriteU32bAt(modAdr+8, dummy1);

    myMemHandler->WriteU32bAt(modAdr, d1);
    myMemHandler->WriteU32bSeq(d2);
    myMemHandler->WriteU32bSeq(d3);

    SaveName(&keepName[0]);
    //after here the serialising can start
}

uint16_t ModelManager::GetAmtUsablelocks()
{
	return myMemHandler->GetAmtUsablelocks();
}

uint16_t ModelManager::GetAmtUsedBlock()
{
	return myMemHandler->GetAmtUsedBlock();
}

void ModelManager::SetCurModByNmbr(uint32_t modNmbr)
{
	if(GetCurModNmbr() != modNmbr)
	{
		myMemHandler->WriteU32bAtStraight(20,CreateModAdr(modNmbr));//SetCurModAdrs
	}
}

uint32_t ModelManager::GetCurModNmbr()
{
	return CreateModNmbr(myMemHandler->GetU32bAtStraight(5*4));
}

uint16_t ModelManager::GetAmtOfModels()
{
	return myMemHandler->GetU32bAtStraight(3*4);
}

void ModelManager::FinalSaveStrobe()
{
	myMemHandler->FinalSaveStrobe();
}

void ModelManager::DelSelctdMod(uint16_t delMod)
{//CreateModAdr
	uint32_t frstMd, delModAdr, modAmnt;
	frstMd = myMemHandler->GetU32bAtStraight(4*4);
	modAmnt = myMemHandler->GetU32bAtStraight(3*4);
	delModAdr = CreateModAdr(delMod);
	if(modAmnt == 1)
	{
		myMemHandler->WriteU32bAtStraight(16, 0);
	}
	else
	{
		if(frstMd == delModAdr)
		{
			myMemHandler->WriteU32bAtStraight(16, CreateNxtModAdr(delModAdr));
		}
		else
		{

		}
		DeInsertModAt(delModAdr);
	}
	//myMemHandler->WriteU32bAtStraight(12, modAmnt-1);//SetAmtOfModels
	myMemHandler->WriteU32bAtStraight(12,modAmnt-1);//SetAmtOfModels
	myMemHandler->DelChain(delModAdr);
}

void ModelManager::GetNameOfModel(char* namArr, uint16_t modNmbr)
{
	uint32_t targedModAdr, dummy;
	targedModAdr = CreateModAdr(modNmbr);

	dummy = myMemHandler->GetU32bAt(targedModAdr);//prv
	dummy = myMemHandler->GetU32bSeq();//this
	dummy =  myMemHandler->GetU32bSeq();//nxt

	GetName(namArr);
}

void ModelManager::NewModel()
{
	uint32_t nxtFreeBlock, amtOfModels;;
	nxtFreeBlock = myMemHandler->GetNxtFreeBlockAdr(DO_BLOCK);
	myMemHandler->WriteU32bAtStraight(20,nxtFreeBlock);
	amtOfModels = myMemHandler->GetU32bAtStraight(3*4);
	//myMemHandler->WriteU32bAtStraight(12,++amtOfModels);//SetAmtOfModels
	if(amtOfModels > 0)
	{
		InsertModEnd(nxtFreeBlock);
	}
	else
	{
		myMemHandler->WriteU32bAtStraight(16, nxtFreeBlock);

		myMemHandler->WriteU32bAt(nxtFreeBlock,nxtFreeBlock);///prv
		myMemHandler->WriteU32bSeq(nxtFreeBlock);//this
		myMemHandler->WriteU32bSeq(nxtFreeBlock);//nxt
		/*
		EEPROMProgram(&nxtFreeBlock, nxtFreeBlock, 4);
		EEPROMProgram(&nxtFreeBlock, nxtFreeBlock+4, 4);
		EEPROMProgram(&nxtFreeBlock, nxtFreeBlock+8, 4);*/
	}
	myMemHandler->WriteU32bAtStraight(12, ++amtOfModels);//SetAmtOfModels
}

uint32_t ModelManager::CreateLastModAdr(uint32_t firstMod)
{
	return myMemHandler->GetU32bAt(firstMod);
}

uint32_t ModelManager::CreateModAdr(uint32_t modNmbr)
{
	uint32_t dummyAdr;
	dummyAdr = myMemHandler->GetU32bAtStraight(4*4);
	for(uint32_t i=0; i<modNmbr; i++)
	{
		dummyAdr = CreateNxtModAdr(dummyAdr);
	}
	return dummyAdr;
}

uint32_t ModelManager::CreateModNmbr(uint32_t modAdr)
{
	uint32_t dummyAdr;
	uint32_t i, modNmbr;
	modNmbr = myMemHandler->GetU32bAtStraight(3*4);
	dummyAdr = myMemHandler->GetU32bAtStraight(4*4);
	for(i=0; i<modNmbr; i++)
	{
		if(dummyAdr == modAdr) break;
		dummyAdr = CreateNxtModAdr(dummyAdr);
	}
	return i;
}

uint16_t ModelManager::GetSelctdMod()
{
	return 0;

}

uint32_t ModelManager::CreateNxtModAdr(uint32_t curModAdr)
{
	static uint32_t dummy;
	dummy = myMemHandler->GetU32bAt(curModAdr);//prv
	dummy = myMemHandler->GetU32bSeq();//this
	return myMemHandler->GetU32bSeq();//nxt
}

uint32_t ModelManager::CreatePrvModAdr(uint32_t curModAdr)
{
	return myMemHandler->GetU32bAt(curModAdr);
}


void ModelManager::InsertModEnd(uint32_t target)
{
	uint32_t firstModelAdr, frstModPrvPtr , frstModNxtPtr, lastModelAdr, lstModNxtPtr, lstModPrvPtr;
	firstModelAdr = myMemHandler->GetU32bAtStraight(4*4);
	lastModelAdr = CreateLastModAdr(firstModelAdr);

	frstModPrvPtr = myMemHandler->GetU32bAt(firstModelAdr);
	frstModNxtPtr = myMemHandler->GetU32bSeq();//dummy this
	frstModNxtPtr = myMemHandler->GetU32bSeq();

	lstModPrvPtr = myMemHandler->GetU32bAt(lastModelAdr);//dummy Read
	lstModNxtPtr = myMemHandler->GetU32bSeq();
	lstModNxtPtr = myMemHandler->GetU32bSeq();



	myMemHandler->WriteU32bAt(lastModelAdr,lstModPrvPtr);
	myMemHandler->WriteU32bSeq(lastModelAdr);
	myMemHandler->WriteU32bSeq(target);

	myMemHandler->WriteU32bAt(firstModelAdr,target);

	myMemHandler->WriteU32bAt(target,lastModelAdr);
	myMemHandler->WriteU32bSeq(target);
	myMemHandler->WriteU32bSeq(firstModelAdr);
}

void ModelManager::DeInsertModAt(uint32_t targAdr)
{
	uint32_t tarPrv, tarNxt, tarPrvPrv, tarPrvThis;

	tarPrv = myMemHandler->GetU32bAt(targAdr);
	tarNxt = myMemHandler->GetU32bSeq();
	tarNxt = myMemHandler->GetU32bSeq();

	tarPrvPrv = myMemHandler->GetU32bAt(tarPrv);
	tarPrvThis = myMemHandler->GetU32bSeq();

	myMemHandler->WriteU32bAt(tarPrv,tarPrvPrv);
	myMemHandler->WriteU32bSeq(tarPrvThis);
	myMemHandler->WriteU32bSeq(tarNxt);

	myMemHandler->WriteU32bAt(tarNxt,tarPrv);
}

void ModelManager::SetMemHandler(StorageHandler_I* memHandler)
{
	myMemHandler = memHandler;
}

 void ModelManager::SaveChar(char arg)
 {

 }

 void ModelManager::SaveName(char* nameArr)
 {
	 uint16_t charCnt = 0;
	 uint16_t charWord;

	 while((nameArr[charCnt] != '\0') && (charCnt < NAME_LENGTH))
	 {
		 charCnt++;
	 }
	 SaveUint16(charCnt);
	 charCnt = 0;
	 while((nameArr[charCnt] != '\0') && (charCnt < NAME_LENGTH))
	 {
		 if((charCnt & 1) == 0)
		 {
			 charWord = 0;
			 charWord = nameArr[charCnt];
		 }
		 else
		 {
			 charWord |= (nameArr[charCnt] << 8);
			 SaveUint16(charWord);
		 }
		 charCnt++;
	 }
	 if((charCnt & 1) == 1)
	 {
		 SaveUint16(charWord);
	 }
 }

 void ModelManager::GetName(char* nameArr)
 {
	 uint16_t nameLength;
	 nameLength = GetUint16();
	 uint16_t charWord;
	 uint32_t i;
	 for(i=0; i<(nameLength-1);)
	 {
		 charWord = GetUint16();
		 nameArr[i] = (charWord & 0xFF);
		 nameArr[i+1] = char((charWord & 0xFF00)>>8);
		 i += 2;
	 }
	 if(nameLength > i)
	 {
		 charWord = GetUint16();
		 nameArr[i] = (charWord & 0xFF);
	 }

	 nameArr[nameLength] = '\0';
 }

 void ModelManager::SaveUint16(uint16_t arg)
 {
	 myMemHandler->WriteU16bSeq(arg);
 }

 void ModelManager::SaveInt16(int16_t arg)
 {
	 myMemHandler->WriteS16bSeq(arg);
 }


 char ModelManager::GetChar()
 {

 }

 uint16_t ModelManager::GetUint16()
 {
	 return myMemHandler->GetU16bSeq();
 }

 int16_t ModelManager::GetInt16()
 {
	 myMemHandler->GetS16bSeq();
 }
