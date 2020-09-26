#include "Scroll_Triplet.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPoint>

Scroll_Triplet::Scroll_Triplet(QWidget *parent, int orient) : ScrollAreaVert(parent, VERTICAL)
{
    SetStretchFactors(3, 1);
}

void Scroll_Triplet::dropEvent(QDropEvent *event)
{
    QPixmap pixmap;
    QPoint offset;
    qint32 typeQ, type;
    if (event->mimeData()->hasFormat("Triplet"))
    {
        int srcChldSel, swapTar;
        QByteArray itemData = event->mimeData()->data("Triplet");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        dataStream  >> offset >> typeQ;

        srcChldSel = (int)typeQ;
        swapTar = (event->pos().ry()+GetScrolPos())/GetHeight();
        if(srcChldSel == swapTar)
        {
            emit Signal_SelectForChange(srcChldSel);
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

void Scroll_Triplet::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("Triplet")){
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

void Scroll_Triplet::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("Triplet")){
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

void Scroll_Triplet::mousePressEvent(QMouseEvent *event)
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
    mimeData->setData("Triplet", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    hotSpot = (event->pos() - child->pos());
    hotSpot.setY(hotSpot.ry()+GetScrolPos());
    drag->setHotSpot(hotSpot);
//! [3]


    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        //child->close();
    } else {
        child->show();
       // child->setPixmap(pixmap);
    }
}
