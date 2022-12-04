#include "Serial_Uart.h"

#include <QDebug>

Serial_Uart::Serial_Uart()
{
    serial.setPortName("COM7");
    serial.setBaudRate(QSerialPort::Baud38400);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    connect(&serial, SIGNAL(readyRead()), this, SLOT(Slot_Read()));
}

void Serial_Uart::Connect()
{
    serial.open(QIODevice::ReadWrite);
}

void Serial_Uart::Slot_Read()
{
    QByteArray data = serial.readAll();
    AssembleInMsg(data);
}

void Serial_Uart::AssembleInMsg(QByteArray inMsg)
{
    char curChar;
    QString modeQ;

    qDebug() << inMsg;

    unsigned int tmpVal;
    for(int c=0; c<inMsg.count(); c++)
    {
        curChar =  inMsg.at(c);
        if((curChar & 2) == 2)
        {
            adcList.clear();
            digList.clear();
            numberNibCntr = 0;
            digNibCntr = 0;
            charCntr = 1;
            valCnt = 0;
        }
        else if((curChar & 8) == 8)
        {
            //adcList.append(tmpAdcVal);
            digList.append(tmpAdcVal);
            Signal_Recieved();
            /*
            for(int m=0; m<adcList.count(); m++)
            {
                qDebug() << "adcVals: " << adcList.at(m);
            }
            if(digList.count() > 0)qDebug() << "digVals: " << digList.at(0);
            */
        }
        else
        {
            if(numberNibCntr == 0)
            {

                if(valCnt > 0)
                {
                    adcList.append(tmpAdcVal);
                }

                tmpVal = curChar & 1;
                tmpVal += ((curChar & 4)>>1);
                tmpVal += ((curChar & 240)>>2);
                tmpAdcVal = tmpVal;

                numberNibCntr++;
            }
            else
            {
                tmpVal = (curChar & 1)<<6;
                tmpVal += ((curChar & 4)<<5);
                tmpVal += ((curChar & 240)<<4);
                tmpAdcVal += tmpVal;
                numberNibCntr =0;
                valCnt++;
            }

        }
    }
}

QList<unsigned int>* Serial_Uart::GetAdcList()
{
    return &adcList;
}

QList<unsigned int>* Serial_Uart::GetDigList()
{
    return &digList;
}

void Serial_Uart::SendNumebrs(QList<float>* sendNumList)
{
    QByteArray byArr;
    byArr.clear();
    float a, b, c;
    uint8_t lower6Bit, upper6Bit;
    IntUint16 valConv;

    byArr.append(3);
    //byArr.append(sendNumList->count() + '0');

    for(int i=0; i<sendNumList->count(); i++)
    {
       // byArr.append('-');
        a = sendNumList->at(i);
        b = a * 0.5;
        c = NEUTRAL + b;

        valConv.uint16Val = c;
        lower6Bit = (((uint8_t)(valConv.uint16Val & 63))<<2);
        lower6Bit |= 1;
        byArr.append(lower6Bit);
        upper6Bit = (uint8_t)((valConv.uint16Val & 4032) >> 4);
        upper6Bit |= 2;
       // qDebug() << "uint16Val " << valConv.uint16Val  << "  lower6Bit: " << lower6Bit << "  upper6Bit: " << upper6Bit;
        byArr.append(upper6Bit);
       // byArr.append('_');
  /*
        d = c * 120;
        tmp32t = (uint32_t)d;
        byArr.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        byArr.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        byArr.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        byArr.append((tmp32t & 15)+'a');

        tmp32t = tmp32t >> 4;
        byArr.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        byArr.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        byArr.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        byArr.append((tmp32t & 15)+'a');*/

    }
    byArr.append('\0');
    //byArr.append((10));
    //byArr.append(0);

   // qDebug() << byArr;
    serial.write(byArr);
}


/*
 *     for(int c=0; c<inMsg.count(); c++)
    {
       curChar =  inMsg.at(c);
       if(curChar == '?')
       {
             mode = '?';
             modeQ.clear();
       }
       if(curChar == '$')
       {
           adcList.clear();
           digList.clear();
           numberNibCntr = 0;
           digNibCntr = 0;
           charCntr = 1;
           mode = '$';
       }
       else if(mode == '$')
       {
           if((curChar == '!') && (charCntr == msgLength))
           {
               Signal_Recieved();
           }
           else if(charCntr == 1)
           {
               numberAmt = curChar - '0';
               charCntr++;
           }
           else if(charCntr == 2)
           {
               digAmt = curChar - '0';
               charCntr++;
               digPos = (numberAmt*4)+3;
               msgLength = (numberAmt*4) + (digAmt*5) + 3;
           }
           else if(charCntr < digPos)
           {
               charCntr++;
               if(curChar == '-')
               {
                   numberNibCntr = 0;
                   tmpAdcVal = 0;
               }
               else
               {
                    if(numberNibCntr < 3)tmpAdcVal += ((curChar-'a')<<(numberNibCntr*4));
                    if(numberNibCntr == 2)
                    {
                       // qDebug() << "adcVal " << adcList.count() << " " << tmpAdcVal;
                        adcList.append(tmpAdcVal);
                    }
                    numberNibCntr++;
               }
           }
           else if(charCntr >= digPos)
           {
               charCntr++;
               if(curChar == '-')
               {
                   digNibCntr = 0;
                   tmpDigVal = 0;
               }
               else
               {
                    if(digNibCntr < 4)tmpDigVal += ((curChar-'a')<<(digNibCntr*4));
                    if(digNibCntr == 3)
                    {
                        digList.append(tmpDigVal);
                        //qDebug() << "adcVal " << digList.count() << " " << tmpDigVal;
                    }
                    digNibCntr++;
               }
           }
        }
       else//mode = '?'
       {
           modeQ.append(curChar);
       }
    }

    if(mode == '?') qDebug() << modeQ;
*/
