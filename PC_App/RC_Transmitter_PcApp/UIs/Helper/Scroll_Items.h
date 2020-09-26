#ifndef SCROLL_ITEMS_H
#define SCROLL_ITEMS_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include "ScrollAreaVert.h"

class Scroll_Items : public ScrollAreaVert
{
    Q_OBJECT
public:
    Scroll_Items(QWidget *parent = 0,int orient = VERTICAL);

signals:
        void Signal_AddCompoNode(unsigned int poolPos);
        void Signal_AddModule(unsigned int type, QPixmap pixmap);
        void Signal_Enter(unsigned int pos);
        void Signal_SwapItems(uint srcChldSel, uint swapTar);

public slots:
    void Slot_DelItem(int delSel);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // SCROLL_ITEMS_H
