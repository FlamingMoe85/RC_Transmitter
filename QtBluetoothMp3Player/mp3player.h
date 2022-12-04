#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include <QDir>
#include <QStringList>

class mp3Player
{
public:
    mp3Player();

    void Play();
    void Stop();
    QString NxtSong();
    QString PrvSong();
    void SetSong(QString &song);
    void SetSongInit(QString &song);
    QString GetSong();
    int GetDuration();
    void SeekToMs(int);
    int GetPosition();

private:

    QStringList files;
    QDir dir;
    int currentSong;


};

#endif // MP3PLAYER_H
