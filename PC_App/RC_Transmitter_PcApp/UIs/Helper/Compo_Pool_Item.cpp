#include "Compo_Pool_Item.h"
#include "ui_Compo_Pool_Item.h"

Compo_Pool_Item::Compo_Pool_Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Compo_Pool_Item)
{
    ui->setupUi(this);
}

Compo_Pool_Item::~Compo_Pool_Item()
{
    delete ui;
}

QLabel* Compo_Pool_Item::GetLabel()
{
    return ui->label;
}

unsigned int Compo_Pool_Item::GetPoolPos()
{
    return myPosition;
}

void Compo_Pool_Item::SetPoolPos(unsigned int p)
{
    myPosition = p;
}
