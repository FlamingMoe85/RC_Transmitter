#include "Helper_Quadlet_Item.h"
#include "ui_Helper_Quadlet_Item.h"

Helper_Quadlet_Item::Helper_Quadlet_Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Helper_Quadlet_Item)
{
    ui->setupUi(this);
}

Helper_Quadlet_Item::~Helper_Quadlet_Item()
{
    delete ui;
}
