#include "Scroll_ModFactory.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPoint>

Scroll_ModFactory::Scroll_ModFactory(QWidget *parent, int orient) : ScrollAreaVert(parent, HORIZONTAL)
{
    AddModule(ADCuC_TYP);
    AddModule(MULT_TYP);
    AddModule(CSTMSW_TYP);
    AddModule(BLINK_TYP);
    AddModule(SCALE_SWITCH_TYP);
    AddModule(QUANTIZER_TYP);
    Resize();

}

void Scroll_ModFactory::AddModule(unsigned int type)
{
    AddWidget(new Module_Item(this, type));
}


void Scroll_ModFactory::dragEnterEvent(QDragEnterEvent *event)
{

}

void Scroll_ModFactory::dragMoveEvent(QDragMoveEvent *event)
{

}

//! [1]
void Scroll_ModFactory::mousePressEvent(QMouseEvent *event)
{
    QPoint hotSpot;
    int childSel;
    Module_Item *child;

    childSel = (event->pos().rx()+GetScrolPos())/GetHeight();
    child = ((Module_Item*)GetWidget(childSel));

    if (!child)
        return;
    QPixmap pixmap = QPixmap(ModFactory_Qt::GetTypePicLocation(child->GetType()));//*child->GetPic();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->GetType() << pixmap << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("Module", itemData);
//! [2]

//! [3]
//!
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    hotSpot = (event->pos() - child->pos());
    hotSpot.setX(hotSpot.rx()+GetScrolPos());
    drag->setHotSpot(hotSpot);
//! [3]

/**/

    QPainter painter;
    QPixmap tempPixmap = pixmap;
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
