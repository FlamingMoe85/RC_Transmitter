/*
 * ModelManager.h
 *
 *  Created on: 30.05.2019
 *      Author: Justus
 */

#ifndef STORAGE_MODELMANAGER_H_
#define STORAGE_MODELMANAGER_H_

#include "../../../share/std/SerializeDest_I.hpp"
#include "../../../share/globaldefinesshare.h"
#include "../../../share/StorageHandler/StorageHandler_I.hpp"

class ModelManager : public SerializeDest_I{
public:
	ModelManager();
	virtual ~ModelManager();

	void SetMemHandler(StorageHandler_I* memHandler);

	virtual void SaveChar(char arg);
	virtual void SaveName(char* nameArr);
	virtual void SaveUint16(uint16_t arg);
	virtual void SaveInt16(int16_t arg);

	virtual char GetChar();
	virtual void GetName(char* nameArr);
	virtual uint16_t GetUint16();
	virtual int16_t GetInt16();

	virtual void NewModel();
	virtual uint32_t CreateLastModAdr(uint32_t firstMod);
	virtual void InsertModEnd(uint32_t target);
	virtual void DeInsertModAt(uint32_t targAdr);
	virtual uint16_t GetAmtOfModels();
	virtual void GetNameOfModel(char* namArr, uint16_t modNmbr);
	virtual void FinalSaveStrobe();
	virtual uint16_t GetSelctdMod();
	virtual void DelSelctdMod(uint16_t delMod);
	virtual void PrepForOverwrite(uint32_t modNmbr);
	virtual void SetCurModByNmbr(uint32_t modNmbr);
	virtual uint32_t GetCurModNmbr();

	virtual uint16_t GetAmtUsablelocks();
	virtual uint16_t GetAmtUsedBlock();

private:
	StorageHandler_I* myMemHandler;

	uint32_t CreateModAdr(uint32_t modNmbr);
	uint32_t CreateModNmbr(uint32_t modAdr);
	uint32_t CreateNxtModAdr(uint32_t curModAdr);
	uint32_t CreatePrvModAdr(uint32_t curModAdr);
};

#endif /* STORAGE_MODELMANAGER_H_ */
