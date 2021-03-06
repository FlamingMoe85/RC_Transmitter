/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtBluetooth module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "chat.h"
#include "remoteselector.h"
#include "chatserver.h"
#include "chatclient.h"

#include <qbluetoothuuid.h>
#include <qbluetoothserver.h>
#include <qbluetoothservicediscoveryagent.h>
#include <qbluetoothdeviceinfo.h>
#include <qbluetoothlocaldevice.h>

#include <QMessageBox>

#include <QTimer>

#include <QDebug>

static const QLatin1String serviceUuid("e8e10f95-1a70-4b27-9ccf-02010264e9c8");

Chat::Chat(QWidget *parent)
    : QWidget(parent),  currentAdapterIndex(0)
{
    //! [Construct UI]


    //connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(CloseApp()));

    //! [Construct UI]

    localAdapters = QBluetoothLocalDevice::allDevices();
    /*if (localAdapters.count() == 0){

        ui->localAdapterBox->setVisible(false);
        QMessageBox* tmpBx = new QMessageBox;
        tmpBx->setText("No local adapter in sight");
        tmpBx->exec();
        //delete tmpBx;

    }
    else if(localAdapters.count() > 2)
    {

        //delete tmpBx;
    }*/
    if(localAdapters.count() < 2)
    {
        //ui->localAdapterBox->setVisible(false);
        /*QMessageBox* tmpBx0 = new QMessageBox;
        tmpBx0->setText(localAdapters.at(0).address().toString());
        tmpBx0->setStandardButtons(QMessageBox::Ok);
        tmpBx0->exec();
        delete tmpBx0;*/
    }
    else {


        //we ignore more than two adapters
        //ui->localAdapterBox->setVisible(true);
       // ui->firstAdapter->setText(tr("Default (%1)", "%1 = Bluetooth address").
                                  //arg(localAdapters.at(0).address().toString()));
        /*QMessageBox* tmpBx1 = new QMessageBox;
        tmpBx1->setText(localAdapters.at(0).address().toString());
        tmpBx1->setStandardButtons(QMessageBox::Ok);
        tmpBx1->exec();
        delete tmpBx1;*/
        //ui->secondAdapter->setText(localAdapters.at(1).address().toString());
        /*QMessageBox* tmpBx = new QMessageBox;
        tmpBx->setText(localAdapters.at(0).address().toString());
        tmpBx->setStandardButtons(QMessageBox::Ok);
        tmpBx->exec();
        delete tmpBx;*/
        //ui->firstAdapter->setChecked(true);
        //connect(ui->firstAdapter, SIGNAL(clicked()), this, SLOT(newAdapterSelected()));
        //connect(ui->secondAdapter, SIGNAL(clicked()), this, SLOT(newAdapterSelected()));

        QBluetoothLocalDevice adapter(localAdapters.at(0).address());
        adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

    }

    //! [Create Chat Server]
    server = new ChatServer(this);
    connect(server, SIGNAL(clientConnected(QString)), this, SLOT(clientConnected(QString)));
    connect(server, SIGNAL(clientDisconnected(QString)), this, SLOT(clientDisconnected(QString)));

    //connect(this, SIGNAL(sendMessage(QString)), server, SLOT(sendMessage(QString)));
    connect(this, SIGNAL(Signal_SendString(QString)), server, SLOT(sendMessage(QString)));

    connect(server, SIGNAL(messageReceived(QString,QString)),
            this, SLOT(Slot_ReceivedMsg(QString,QString)));
    server->startServer();
    //! [Create Chat Server]

    //! [Get local device name]
    localName = QBluetoothLocalDevice().name();
    //! [Get local device name]
//connectClicked();
}

Chat::~Chat()
{
    qDeleteAll(clients);
    delete server;
}

void Chat::Slot_ReceivedMsg(const QString &sender, const QString &message)
{
    AssembleInMsg(message.toLocal8Bit());
}

//! [clientConnected clientDisconnected]
void Chat::clientConnected(const QString &name)
{
    //ui->chat->insertPlainText(QString::fromLatin1("%1 has joined chat.\n").arg(name));
}

void Chat::clientDisconnected(const QString &name)
{
    //ui->chat->insertPlainText(QString::fromLatin1("%1 has left.\n").arg(name));
}
//! [clientConnected clientDisconnected]

//! [connected]
void Chat::connected(const QString &name)
{
   // ui->chat->insertPlainText(QString::fromLatin1("Joined chat with %1.\n").arg(name));
}

void Chat::newAdapterSelected()
{
    const int newAdapterIndex = adapterFromUserSelection();
    if (currentAdapterIndex != newAdapterIndex) {
        server->stopServer();
        currentAdapterIndex = newAdapterIndex;
        const QBluetoothHostInfo info = localAdapters.at(currentAdapterIndex);
        QBluetoothLocalDevice adapter(info.address());
        adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
        server->startServer(info.address());
        localName = info.name();
    }
}

int Chat::adapterFromUserSelection() const
{
    int result = 0;
    QBluetoothAddress newAdapter = localAdapters.at(0).address();

   /* if (ui->secondAdapter->isChecked()) {
        newAdapter = localAdapters.at(1).address();
        result = 1;
    }*/
    return result;
}
//! [connected]

//! [clientDisconnected]
void Chat::clientDisconnected()
{
    ChatClient *client = qobject_cast<ChatClient *>(sender());
    if (client) {
        clients.removeOne(client);
        client->deleteLater();
    }
}
//! [clientDisconnected]

//! [Connect to remote service]
void Chat::connectClicked()
{
    //ui->connectButton->setEnabled(false);

    // scan for services
    const QBluetoothAddress adapter = localAdapters.isEmpty() ?
                                           QBluetoothAddress() :
                                           localAdapters.at(currentAdapterIndex).address();

    RemoteSelector remoteSelector(adapter);
    remoteSelector.startDiscovery(QBluetoothUuid(serviceUuid));
    if (remoteSelector.exec() == QDialog::Accepted) {
        QBluetoothServiceInfo service = remoteSelector.service();


        // Create client
        ChatClient *client = new ChatClient(this);


connect(client, SIGNAL(messageReceived(QString,QString)),
        this, SLOT(Slot_ReceivedMsg(QString,QString)));
        connect(client, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
        connect(client, SIGNAL(connected(QString)), this, SLOT(connected(QString)));
        //connect(this, SIGNAL(sendMessage(QString)), client, SLOT(sendMessage(QString)));
        connect(this, SIGNAL(Signal_SendMsg(QString*)), client, SLOT(sendMsg(QString*)));
        connect(this, SIGNAL(sendTelegram(char*)), client, SLOT(sendTelegram(char*)));
        client->startClient(service);

        clients.append(client);
    }

    //ui->connectButton->setEnabled(true);
}
//! [Connect to remote service]

//! [sendClicked]
//!
/*
void Chat::sendClicked()
{
    ui->sendButton->setEnabled(false);
    ui->sendText->setEnabled(false);

    showMessage(localName, ui->sendText->text());
    emit sendMessage(ui->sendText->text());

    ui->sendText->clear();

    ui->sendText->setEnabled(true);
    ui->sendButton->setEnabled(true);
}*/

//! [showMessage]
//!


void Chat::send(int val)
{

    //emit sendTelegram(telegramm);
}

void Chat::CloseApp()
{
    emit closeDaApp();
}


void Chat::AssembleInMsg(QByteArray inMsg)
{
    char curChar;
    QString modeQ;
    for(int c=0; c<inMsg.count(); c++)
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
           /*else*/ if((curChar == '!') && (charCntr == msgLength))
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

}

QList<unsigned int>* Chat::GetAdcList()
{
    return &adcList;
}

QList<unsigned int>* Chat::GetDigList()
{
    return &digList;
}

void Chat::SendNumebrs(QList<float>* sendNumList)
{

    sendStrng.clear();
    float a, b, c, d;
    uint32_t tmp32t;

    sendStrng.append('$');
    sendStrng.append('$');
    sendStrng.append(sendNumList->count() + '0');

    for(int i=0; i<sendNumList->count(); i++)
    {
        sendStrng.append('-');
        a = sendNumList->at(i);
        b = a * 0.5;
        c = NEUTRAL + b;
        d = c * 120;
        tmp32t = (uint32_t)d;
        sendStrng.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        sendStrng.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        sendStrng.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        sendStrng.append((tmp32t & 15)+'a');

        tmp32t = tmp32t >> 4;
        sendStrng.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        sendStrng.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        sendStrng.append((tmp32t & 15)+'a');
        tmp32t = tmp32t >> 4;
        sendStrng.append((tmp32t & 15)+'a');
    }
    sendStrng.append('!');

    Signal_SendMsg(&sendStrng);
    //serial.write(sendStrng.toLocal8Bit());
    //Signal_SendString(sendStrng);
}
