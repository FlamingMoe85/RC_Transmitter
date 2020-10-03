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
    void Set_Pos(QString pos);
    void Set_C2Par(QString par);
    void Set_C3Par(QString par);
    void Set_C4Par(QString par);
    QString Get_Pos();
    QString Get_C2Par();
    QString Get_C3Par();
    QString Get_C4Par();
private:
    Ui::Helper_Quadlet_Item *ui;
};

#endif // HELPER_QUADLET_ITEM_H
