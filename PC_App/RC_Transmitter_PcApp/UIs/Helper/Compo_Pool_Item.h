#ifndef COMPO_POOL_ITEM_H
#define COMPO_POOL_ITEM_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Compo_Pool_Item;
}

class Compo_Pool_Item : public QWidget
{
    Q_OBJECT

public:
    explicit Compo_Pool_Item(QWidget *parent = 0);
    ~Compo_Pool_Item();
    QLabel* GetLabel();
    unsigned int GetPoolPos();
    void SetPoolPos(unsigned int p);

private:
    Ui::Compo_Pool_Item *ui;
    unsigned int myPosition;
};

#endif // COMPO_POOL_ITEM_H
