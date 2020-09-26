#include "Qt_ControlKnop.h"
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPoint>
#include <QDragEnterEvent>

Qt_ControlKnop::Qt_ControlKnop()
{
    setAcceptDrops(true);

    knopIcon = new QLabel(this);
    knopIcon->setPixmap(QPixmap(":/images/Knop.png"));
    knopIcon->move(10, 10);
    knopIcon->show();
    knopIcon->setAttribute(Qt::WA_DeleteOnClose);
}

void Qt_ControlKnop::SetAreaDims(unsigned int w, unsigned int h)
{
    myH = h;
    myW = w;
}

void Qt_ControlKnop::Neutral()
{

    width = this->geometry().width();
    height = this->geometry().height();

    //qDebug() << "width " << width << "  height " << height;

/*
    knopIcon->move((width/2)+knopIcon->geometry().width()/2,
                    (height/2)+knopIcon->geometry().height()/2);
    */
}

void Qt_ControlKnop::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("Knop")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
            Signal_Posistion((((width/2) - ((float)(event->pos().rx())))*1000)/width
                             ,(((height/2) - ((float)(event->pos().ry())))*1000)/height);
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Qt_ControlKnop::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("Knop")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
            Signal_Posistion((((width/2) - ((float)(event->pos().rx())))*1000)/width
                             ,(((height/2) - ((float)(event->pos().ry())))*1000)/height);
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Qt_ControlKnop::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("Knop")) {
        QByteArray itemData = event->mimeData()->data("Knop");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        //QLabel *child = static_cast<QLabel*>(childAt(event->pos()));

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;
        //child->move(myW - event->pos().rx(), myH - event->pos().ry());

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);


        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

//! [1]
void Qt_ControlKnop::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("Knop", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
//! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}
