#ifndef MODULE_ITEM_H
#define MODULE_ITEM_H

#include <QWidget>
#include "../../../../share/globaldefinesshare.h"

namespace Ui {
class Module_Item;
}

class Module_Item : public QWidget
{
    Q_OBJECT

public:
    explicit Module_Item(QWidget *parent = 0, unsigned int type = 0);
    ~Module_Item();
    void SetPic(QPixmap pic);
    const QPixmap* GetPic();
    unsigned int GetType();

private:
    Ui::Module_Item *ui;
    unsigned int myType;
};

#endif // MODULE_ITEM_H
