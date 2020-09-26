#ifndef CHILD_ITEM_H
#define CHILD_ITEM_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Child_Item;
}

class Child_Item : public QWidget
{
    Q_OBJECT

public:
    explicit Child_Item(QWidget *parent = 0);
    ~Child_Item();

    QLabel* GetTextLabel();
    QLabel* GetPicLabel();

private:
    Ui::Child_Item *ui;
};

#endif // CHILD_ITEM_H
