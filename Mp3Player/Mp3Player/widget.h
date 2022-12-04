#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStringList>
#include <QDir>
#include <QVideoProbe>
#include <QVideoWidget>

#include "chat.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QMediaPlayer* player;
    QMediaPlaylist *m_playlist;
    QStringList files;
    QDir dir;
    QVideoProbe* probe;

    QVideoWidget* videoWidget;

    unsigned int currentSong, volume;
    Chat btChat;

private slots:
  void Slt_Play();
  void Slt_Pause();
  void Slt_Fw();
  void Slt_Bw();
  void Slt_Vd();
  void Slt_Vu();

  void Slt_StatusChanged(QMediaPlayer::State status);
  void Slt_RecMessage(const QString &message);
};

#endif // WIDGET_H
