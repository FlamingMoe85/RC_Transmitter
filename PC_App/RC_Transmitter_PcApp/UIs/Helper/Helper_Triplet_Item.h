#ifndef HELPER_TRIPLET_ITEM_H
#define HELPER_TRIPLET_ITEM_H

#include <QWidget>
#include <QString>

namespace Ui {
class Helper_Triplet_Item;
}

class Helper_Triplet_Item : public QWidget
{
    Q_OBJECT

public:
    explicit Helper_Triplet_Item(QWidget *parent = 0);
    ~Helper_Triplet_Item();
    void Set_Pos(QString pos);
    void Set_C2Par(QString par);
    void Set_C3Par(QString par);
    QString Get_Pos();
    QString Get_C2Par();
    QString Get_C3Par();

private:
    Ui::Helper_Triplet_Item *ui;
};

#endif // HELPER_TRIPLET_ITEM_H
