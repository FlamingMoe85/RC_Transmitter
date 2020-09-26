#ifndef SERIAL_UART_H
#define SERIAL_UART_H

#include <QObject>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QList>

#include "../../share/globaldefinesshare.h"

class Serial_Uart : public QObject
{
    Q_OBJECT
public:
    Serial_Uart();
    QList<unsigned int>* GetAdcList();
    QList<unsigned int>* GetDigList();
    void SendNumebrs(QList<float>* sendNumList);

    void Connect();

signals:
    void Signal_Recieved();

private:
    QSerialPort serial;

    void AssembleInMsg(QByteArray inMsg);
    unsigned int charCntr, numberNibCntr, numberAmt, tmpAdcVal, digAmt, digPos, digNibCntr, tmpDigVal, msgLength, valCnt;
    QList<unsigned int> adcList;
    QList<unsigned int> digList;
    char mode;

private slots:
    void Slot_Read();
};

#endif // SERIAL_UART_H
