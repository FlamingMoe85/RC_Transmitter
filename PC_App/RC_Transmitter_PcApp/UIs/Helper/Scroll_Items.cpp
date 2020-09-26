#include "Scroll_Items.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPoint>


Scroll_Items::Scroll_Items(QWidget *parent, int orient) : ScrollAreaVert(parent, VERTICAL)
{
    SetStretchFactors(2, 1);
}
void Scroll_Items::Slot_DelItem(int delSel)
{
    DeleteElememnt(delSel);
}

void Scroll_Items::dropEvent(QDropEvent *event)
{
    QPixmap pixmap;
    QPoint offset;
    qint32 typeQ, type;
    if (event->mimeData()->hasFormat("Composition"))
    {
        QByteArray itemData = event->mimeData()->data("Composition");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        unsigned int poolPosition;

        dataStream >> poolPosition;
        emit Signal_AddCompoNode(poolPosition);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    }
    else if (event->mimeData()->hasFormat("Module"))
    {
        unsigned int type;
        QByteArray itemData = event->mimeData()->data("Module");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        dataStream >> type >> pixmap;
        emit Signal_AddModule(type, pixmap);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    }
    else if (event->mimeData()->hasFormat("application/x-dnditemdataDrop"))
    {
        int srcChldSel, swapTar;
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdataDrop");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        dataStream  >> offset >> typeQ;

        srcChldSel = (int)typeQ;
        swapTar = (event->pos().ry()+GetScrolPos())/GetHeight();
        if(srcChldSel == swapTar)
        {
            emit Signal_Enter(srcChldSel);
            return;
        }
        else
        {
            SwapItems(srcChldSel, swapTar);
            Resize();
            emit Signal_SwapItems((uint)srcChldSel, (uint)swapTar);
        }

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void Scroll_Items::dragEnterEvent(QDragEnterEvent *event)
{
    if ((event->mimeData()->hasFormat("Composition")) ||
        (event->mimeData()->hasFormat("application/x-dnditemdataDrop")) ||
        (event->mimeData()->hasFormat("Module"))){
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

void Scroll_Items::dragMoveEvent(QDragMoveEvent *event)
{
    if ((event->mimeData()->hasFormat("Composition")) ||
        (event->mimeData()->hasFormat("application/x-dnditemdataDrop")) ||
        (event->mimeData()->hasFormat("Module"))){
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

void Scroll_Items::mousePressEvent(QMouseEvent *event)
{
    QPoint hotSpot;
    int childSel;
    QWidget *child;
    childSel = (event->pos().ry()+GetScrolPos())/GetHeight();
    child = GetWidget(childSel);

    if (!child)
        return;
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << QPoint(event->pos() - child->pos()) << (qint32)(childSel);
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdataDrop", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
//    drag->setPixmap(pixmap);
    hotSpot = (event->pos() - child->pos());
    hotSpot.setY(hotSpot.ry()+GetScrolPos());
    drag->setHotSpot(hotSpot);
//! [3]

    /*
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();
    */

    //child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        //child->close();
    } else {
        child->show();
       // child->setPixmap(pixmap);
    }
}
