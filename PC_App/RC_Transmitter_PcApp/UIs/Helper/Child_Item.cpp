#include "Child_Item.h"
#include "ui_Child_Item.h"

Child_Item::Child_Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Child_Item)
{
    ui->setupUi(this);
}

Child_Item::~Child_Item()
{
    delete ui;
}

QLabel* Child_Item::GetTextLabel()
{
    return ui->label_Text;
}

QLabel* Child_Item::GetPicLabel()
{
    return ui->label_Pic;
}
