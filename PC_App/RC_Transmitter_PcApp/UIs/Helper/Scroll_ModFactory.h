#ifndef SCROLL_MODFACTORY_H
#define SCROLL_MODFACTORY_H

#include <QObject>
#include "ScrollAreaVert.h"
#include "Module_Item.h"
#include "../../modfactory_qt.h"
#include "../../../../share/Graph_App/graph_app_i.h"

#include "../../../../share/Graph_App/Calc_Multiplication_Leaf.h"

class Scroll_ModFactory : public ScrollAreaVert
{
public:
    Scroll_ModFactory(QWidget *parent = 0,int orient = HORIZONTAL);

    void AddModule(unsigned int type);


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SCROLL_MODFACTORY_H
