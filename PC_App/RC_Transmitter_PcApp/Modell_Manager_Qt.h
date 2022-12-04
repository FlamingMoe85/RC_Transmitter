#ifndef MODELL_MANAGER_QT_H
#define MODELL_MANAGER_QT_H

#include <QObject>
#include <QFile>
#include <QString>

#include "../../share/std/SerializeDest_I.hpp"
#include "../../share/globaldefinesshare.h"

class Modell_Manager_Qt : public SerializeDest_I
{
public:
    Modell_Manager_Qt();

    virtual void SaveChar(char arg);
    virtual void SaveName(char* nameArr);
    virtual void SaveUint16(uint16_t arg);
    virtual void SaveInt16(int16_t arg);

    virtual char GetChar();
    virtual void GetName(char* nameArr);
    virtual uint16_t GetUint16();
    virtual int16_t GetInt16();

    virtual void NewModel();
    void OpenModel(QString name);
    virtual uint32_t CreateLastModAdr(uint32_t firstMod){(void)firstMod; return 0;};
    virtual void InsertModEnd(uint32_t target){(void)target; };
    virtual void DeInsertModAt(uint32_t targAdr){(void)targAdr; };
    virtual uint16_t GetAmtOfModels(){ return 0;};
    virtual void GetNameOfModel(char* namArr, uint16_t modNmbr){(void)namArr; (void)modNmbr; };
    virtual void FinalSaveStrobe(){ };
    virtual uint16_t GetSelctdMod(){ return 0;};
    virtual void DelSelctdMod(uint16_t delMod){(void)delMod; };
    virtual void SetCurModByNmbr(uint32_t modNmbr){(void)modNmbr; };
    virtual uint32_t GetCurModNmbr(){ return 0;};

    void Close();

    virtual void PrepForOverwrite(uint32_t modNmbr){(void)modNmbr; };
    virtual uint16_t GetAmtUsablelocks(){return 0; };
    virtual uint16_t GetAmtUsedBlock(){ return 0;};

private:
    QFile file;

    union Conv_Un
    {
        int16_t intVal;
        uint16_t uintVal;
    };
};

#endif // MODELL_MANAGER_QT_H
