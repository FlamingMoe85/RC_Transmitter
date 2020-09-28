#ifndef HELPER_QUADLET_ITEM_H
#define HELPER_QUADLET_ITEM_H

#include <QWidget>

namespace Ui {
class Helper_Quadlet_Item;
}

class Helper_Quadlet_Item : public QWidget
{
    Q_OBJECT

public:
    explicit Helper_Quadlet_Item(QWidget *parent = nullptr);
    ~Helper_Quadlet_Item();

private:
    Ui::Helper_Quadlet_Item *ui;
};

#endif // HELPER_QUADLET_ITEM_H
