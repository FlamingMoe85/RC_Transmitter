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
    virtual uint32_t CreateLastModAdr(uint32_t firstMod){ };
    virtual void InsertModEnd(uint32_t target){ };
    virtual void DeInsertModAt(uint32_t targAdr){ };
    virtual uint16_t GetAmtOfModels(){ };
    virtual void GetNameOfModel(char* namArr, uint16_t modNmbr){ };
    virtual void FinalSaveStrobe(){ };
    virtual uint16_t GetSelctdMod(){ };
    virtual void DelSelctdMod(uint16_t delMod){ };
    virtual void SetCurModByNmbr(uint32_t modNmbr){ };
    virtual uint32_t GetCurModNmbr(){ };

    void Close();

    virtual void PrepForOverwrite(uint32_t modNmbr){ };
    virtual uint16_t GetAmtUsablelocks(){ };
    virtual uint16_t GetAmtUsedBlock(){ };

private:
    QFile file;

    union Conv_Un
    {
        int16_t intVal;
        uint16_t uintVal;
    };
};

#endif // MODELL_MANAGER_QT_H
