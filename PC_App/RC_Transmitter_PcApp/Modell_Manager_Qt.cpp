#include "Modell_Manager_Qt.h"

#include <QDebug>

Modell_Manager_Qt::Modell_Manager_Qt()
{

}

void Modell_Manager_Qt::NewModel()
{
    file.setFileName("TestModel.txt");
    file.open(QIODevice::ReadWrite);
}

void Modell_Manager_Qt::OpenModel(QString name)
{
    qDebug() << "Open Modell: " << name;
    file.setFileName(name+".txt");
    file.open(QIODevice::ReadWrite);
}

void Modell_Manager_Qt::Close()
{
    file.close();
}

void Modell_Manager_Qt::SaveChar(char arg)
{
    file.write(&arg, 1);
}

void Modell_Manager_Qt::SaveName(char* nameArr)
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

void Modell_Manager_Qt::SaveUint16(uint16_t arg)
{
    /*
    char tmpChar = (arg & 255);
    file.write(&tmpChar, 1);
    tmpChar = (arg & 65280) >> 8;
    file.write(&tmpChar, 1);
    */
    char tmpChar;
    qDebug() << "arg: " << arg;
    tmpChar= (arg & 15) + '0';
    arg = arg >> 4;
    qDebug() << (unsigned int)tmpChar;
    file.write(&tmpChar, 1);

    tmpChar= (arg & 15) + '0';
    arg = arg >> 4;
    qDebug() << (unsigned int)tmpChar;
    file.write(&tmpChar, 1);

    tmpChar= (arg & 15) + '0';
    arg = arg >> 4;
    qDebug() << (unsigned int)tmpChar;
    file.write(&tmpChar, 1);

    tmpChar= (arg & 15) + '0';
    arg = arg >> 4;
    qDebug() << (unsigned int)tmpChar;
    file.write(&tmpChar, 1);
}
void Modell_Manager_Qt::SaveInt16(int16_t arg)
{
    Conv_Un conV;
    conV.intVal = arg;
    SaveUint16(conV.uintVal);
}

char Modell_Manager_Qt::GetChar()
{

}

void Modell_Manager_Qt::GetName(char* nameArr)
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

uint16_t Modell_Manager_Qt::GetUint16()
{
    char readChar;
    uint16_t retVal;
    file.read(&readChar, 1);
    retVal = readChar-'0';
    file.read(&readChar, 1);
    retVal += ((readChar-'0') << 4);
    file.read(&readChar, 1);
    retVal += ((readChar-'0') << 8);
    file.read(&readChar, 1);
    retVal += ((readChar-'0') << 12);

    qDebug() << "retVal " << retVal;

    return retVal;
}

int16_t Modell_Manager_Qt::GetInt16()
{
   Conv_Un conV;

    conV.uintVal = GetUint16();
    return conV.intVal;
}

