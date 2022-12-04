#include "widget.h"
#include "ui_widget.h"
#include <QUrl>
#include <QMessageBox>

#include <QtAndroidExtras/QAndroidJniObject>
#include <jni.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QUrl qUrl;

    //gathering all the files with ".mp3" type found in "/sdcard/Music"
    dir = QDir::toNativeSeparators("/sdcard/Music");
    QStringList filters;
    filters << "*.mp3";
    files = dir.entryList(filters, QDir::Files | QDir::NoSymLinks);

    m_playlist = new QMediaPlaylist();

    for(unsigned int i=0; i<files.count(); i++)
    {
        //filling the found files in via URLs in the Playlist
         m_playlist->addMedia(QUrl::fromLocalFile("/sdcard/Music/" + files.at(i).toLatin1()));
    }

    player = new QMediaPlayer;
    currentSong = 14;
    player->setVolume(20);
    m_playlist->setCurrentIndex(currentSong);
    player->setPlaylist(m_playlist);
    player->play();


    connect(ui->pushButton_Play,SIGNAL(clicked()), this, SLOT(Slt_Play()));
    connect(ui->pushButton_Pause,SIGNAL(clicked()), this, SLOT(Slt_Pause()));
    connect(ui->pushButton_Fw,SIGNAL(clicked()), this, SLOT(Slt_Fw()));
    connect(ui->pushButton_Bw,SIGNAL(clicked()), this, SLOT(Slt_Bw()));
    connect(ui->pushButton_Vup,SIGNAL(clicked()), this, SLOT(Slt_Vu()));
    connect(ui->pushButton_Vdown,SIGNAL(clicked()), this, SLOT(Slt_Vd()));

    connect(&btChat, SIGNAL(Sig_RecMessage(QString)), this, SLOT(Slt_RecMessage(QString)));

    //connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(Slt_StatusChanged()));

    volume = 20;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::Slt_Play()
{
    player->play();
}
void Widget::Slt_Pause()
{
    player->pause();
}

void Widget::Slt_StatusChanged(QMediaPlayer::State status)
{
    switch (status) {
    case QMediaPlayer::StoppedState:
        Slt_Fw();
        break;
    }
}

void Widget::Slt_Fw()
{

    /*
    if(currentSong < (files.count()-1)) currentSong++;
    else currentSong = 0;
    player->setMedia(QUrl::fromLocalFile("/sdcard/Music/" + files.at(currentSong).toLatin1()));
    */
    m_playlist->next();
    //player->play();


}

void Widget::Slt_RecMessage(const QString &message)
{
    const char* mes;
    QByteArray ba;

    /*
    QMessageBox mB;
    mB.setText("Chat " + message);
    mB.exec();

    */
    ba = message.toLatin1();
    mes = ba.data();
    if(mes[0] == 'p'){Slt_Play(); }
    if(mes[0] == 's'){Slt_Pause(); }
    if(mes[0] == 'f'){Slt_Fw(); }
    if(mes[0] == 'b'){Slt_Bw(); }
    if(mes[0] == 'V'){Slt_Vu(); }
    if(mes[0] == 'v'){Slt_Vd(); }
}

void Widget::Slt_Bw()
{
   m_playlist->previous();
}
void Widget::Slt_Vu()
{
    if(volume < 100)volume+=2;
    player->setVolume(volume);
}
void Widget::Slt_Vd()
{
    if(volume > 0)volume-=2;
    player->setVolume(volume);
}
