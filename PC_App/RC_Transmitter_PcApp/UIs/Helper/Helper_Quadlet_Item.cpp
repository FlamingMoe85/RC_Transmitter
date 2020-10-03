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

void Helper_Quadlet_Item::Set_Pos(QString pos)
{
    ui->label_Colum_1->setText(pos);
}

void Helper_Quadlet_Item::Set_C2Par(QString par)
{
    ui->label_Colum_2->setText(par);
}

void Helper_Quadlet_Item::Set_C3Par(QString par)
{
    ui->label_Colum_3->setText(par);
}

void Helper_Quadlet_Item::Set_C4Par(QString par)
{
    ui->label_Colum_4->setText(par);
}

QString Helper_Quadlet_Item::Get_Pos()
{
    return ui->label_Colum_1->text();
}

QString Helper_Quadlet_Item::Get_C2Par()
{
    return ui->label_Colum_2->text();
}

QString Helper_Quadlet_Item::Get_C3Par()
{
   return  ui->label_Colum_3->text();
}

QString Helper_Quadlet_Item::Get_C4Par()
{
   return  ui->label_Colum_4->text();
}
