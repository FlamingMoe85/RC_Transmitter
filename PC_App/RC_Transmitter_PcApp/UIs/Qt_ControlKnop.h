#ifndef QT_CONTROLKNOP_H
#define QT_CONTROLKNOP_H

#include <QObject>
#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class Qt_ControlKnop : public QWidget
{
    Q_OBJECT
public:
    Qt_ControlKnop();

    void Neutral();
    void SetAreaDims(unsigned int w, unsigned int h);

signals:
    void Signal_Posistion(float x, float y);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QLabel *knopIcon;
    float width, height;
    unsigned int myW, myH;
};

#endif // QT_CONTROLKNOP_H
