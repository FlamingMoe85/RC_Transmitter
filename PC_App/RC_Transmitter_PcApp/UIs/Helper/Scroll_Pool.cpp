#include "Scroll_Pool.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPoint>


Scroll_Pool::Scroll_Pool(QWidget *parent, int orient) : ScrollAreaVert(parent, VERTICAL)
{
    SetStretchFactors(2, 1);
}

void Scroll_Pool::dragEnterEvent(QDragEnterEvent *event)
{

}

void Scroll_Pool::dragMoveEvent(QDragMoveEvent *event)
{

}

//! [1]
void Scroll_Pool::mousePressEvent(QMouseEvent *event)
{
    QPoint hotSpot;
    int childSel;
    Compo_Pool_Item *child;
    childSel = (event->pos().ry()+GetScrolPos())/GetHeight();
    child = ((Compo_Pool_Item*)GetWidget(childSel));

    if (!child)
        return;
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << childSel << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("Composition", itemData);
//! [2]

//! [3]
//!
    QPixmap tempPixmap;
    tempPixmap.load((":/images/C.png"));
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(tempPixmap);
    hotSpot = (event->pos() - child->pos());
    hotSpot.setY(hotSpot.ry()+GetScrolPos());
    drag->setHotSpot(hotSpot);
//! [3]

/**/

    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(tempPixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    //child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
       // child->setPixmap(pixmap);
    }
}
