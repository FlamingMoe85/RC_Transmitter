#ifndef SCROLL_TRIPLET_H
#define SCROLL_TRIPLET_H

#include <QObject>
#include "ScrollAreaVert.h"

class Scroll_Triplet : public ScrollAreaVert
{
    Q_OBJECT
public:
    Scroll_Triplet(QWidget *parent = 0,int orient = VERTICAL);

signals:
    void Signal_SwapItems(uint srcChldSel, uint swapTar);
    void Signal_SelectForChange(uint srcChldSel);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SCROLL_TRIPLET_H
