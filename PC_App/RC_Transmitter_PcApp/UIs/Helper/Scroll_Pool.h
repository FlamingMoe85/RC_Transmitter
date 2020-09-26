#ifndef SCROLL_POOL_H
#define SCROLL_POOL_H

#include <QObject>
#include "ScrollAreaVert.h"
#include "Compo_Pool_Item.h"

class Scroll_Pool : public ScrollAreaVert
{

public:
    Scroll_Pool(QWidget *parent = 0,int orient = VERTICAL);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SCROLL_POOL_H
