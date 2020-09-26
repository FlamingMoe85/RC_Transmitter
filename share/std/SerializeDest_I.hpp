#ifndef SERIALIZEDEST_H
#define SERIALIZEDEST_H

#include <stdint.h>

#define IS_SERIALED     1

class SerializeDest_I
{
public:

virtual void SaveChar(char arg) = 0;
virtual void SaveName(char* nameArr) = 0;
virtual void SaveUint16(uint16_t arg) = 0;
virtual void SaveInt16(int16_t arg) = 0;

virtual char GetChar() = 0;
virtual void GetName(char* nameArr) = 0;
virtual uint16_t GetUint16() = 0;
virtual int16_t GetInt16() = 0;


virtual void NewModel() = 0;
virtual uint32_t CreateLastModAdr(uint32_t firstMod) = 0;
virtual void InsertModEnd(uint32_t target) = 0;
virtual void DeInsertModAt(uint32_t targAdr) = 0;
virtual uint16_t GetAmtOfModels() = 0;
virtual void GetNameOfModel(char* namArr, uint16_t modNmbr) = 0;
virtual void FinalSaveStrobe() = 0;
virtual uint16_t GetSelctdMod() = 0;
virtual void DelSelctdMod(uint16_t delMod) = 0;
virtual void PrepForOverwrite(uint32_t modNmbr) = 0;

virtual void SetCurModByNmbr(uint32_t modNmbr) = 0;
virtual uint32_t GetCurModNmbr() = 0;

virtual uint16_t GetAmtUsablelocks() = 0;
virtual uint16_t GetAmtUsedBlock() = 0;

};

#endif // SERIALIZEDEST_H
