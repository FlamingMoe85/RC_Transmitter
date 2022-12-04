#include "mp3player.h"
#include <QtAndroidExtras/QAndroidJniObject>
#include <jni.h>
#include <QMessageBox>

mp3Player::mp3Player()
{
    //dir = QDir::toNativeSeparators("/sdcard/Music/DJKygoISeeFire.mp3");
    dir = QDir::toNativeSeparators("/sdcard/Music");
    QStringList filters;
    filters << "*.mp3";
    files = dir.entryList(filters, QDir::Files | QDir::NoSymLinks);

    currentSong = 0;
if(files.count() > 0)
{
    /**/QAndroidJniObject javaNotification = QAndroidJniObject::fromString("/sdcard/Music/" + files.at(currentSong).toLatin1());

    QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                 ,"SetSource"
                                ,"(Ljava/lang/String;)V",
                                javaNotification.object<jstring>());
}
}


void mp3Player::Play()
{
    QAndroidJniObject::callStaticMethod<jint>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                , "Play" // method name
                                ,"()V" );
}

void mp3Player::Stop()
{
    QAndroidJniObject::callStaticMethod<jint>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                , "Pause" // method name
                                ,"()V" );
}

void mp3Player::SeekToMs(int time)
{
    //QAndroidJniObject javaNotification = QAndroidJniObject::
    jint val;
    val = time;
    QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                 ,"SeekToMs"
                                ,"(I)V",
                                val);
}

int mp3Player::GetPosition()
{
    return QAndroidJniObject::callStaticMethod<int>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                , "GetPosition" // method name
                                ,"()I" );
}

QString mp3Player::NxtSong()
{
    QString song;
    if(currentSong < files.count()) currentSong++;
    else currentSong = 0;
    song =  files.at(currentSong).toLatin1();
    QAndroidJniObject javaNotification = QAndroidJniObject::fromString("/sdcard/Music/" + files.at(currentSong).toLatin1());


    QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                , "Stop" // method name
                                ,"()V" );
    QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                 ,"SetSource"
                                ,"(Ljava/lang/String;)V",
                                javaNotification.object<jstring>());
    //Play();
    return song;
}

QString mp3Player::PrvSong()
{
    QString song;
    if(currentSong > 0 ) currentSong--;
    else currentSong = files.count()-1;
    song =  files.at(currentSong).toLatin1();
    QAndroidJniObject javaNotification = QAndroidJniObject::fromString("/sdcard/Music/" + files.at(currentSong).toLatin1());
    QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                , "Stop" // method name
                                ,"()V" );

    QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                 ,"SetSource"
                                ,"(Ljava/lang/String;)V",
                                javaNotification.object<jstring>());
    //Play();
    return song;
}

void mp3Player::SetSong(QString &song)
{
    QAndroidJniObject javaNotification = QAndroidJniObject::fromString("/sdcard/Music/" + song.toLatin1());
    /*QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                , "Stop" // method name
                                ,"()V" );*/

    QAndroidJniObject::callStaticMethod<void>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                 ,"SetSource"
                                ,"(Ljava/lang/String;)V",
                                javaNotification.object<jstring>());
}

void mp3Player::SetSongInit(QString &song)
{
    QMessageBox notFound;
    notFound.setText("Song not found");

    for(currentSong=0; currentSong<files.count(); currentSong++)
    {
        if(files.at(currentSong).toLatin1() == song)
        {
            SetSong(song);
            return;
        }
    }
    currentSong = 0;
    notFound.exec();

}

QString mp3Player::GetSong()
{
    return files.at(currentSong).toLatin1();
}

int mp3Player::GetDuration()
{

    return QAndroidJniObject::callStaticMethod<int>
                                ("org/qtproject/example/LightControl1/Mp3PlayerJava"// class name
                                , "GetDuration" // method name
                                ,"()I" );

}
