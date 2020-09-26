#include "Helper_Triplet_Item.h"
#include "ui_Helper_Triplet_Item.h"

Helper_Triplet_Item::Helper_Triplet_Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Helper_Triplet_Item)
{
    ui->setupUi(this);
}

Helper_Triplet_Item::~Helper_Triplet_Item()
{
    delete ui;
}

void Helper_Triplet_Item::Set_Pos(QString pos)
{
    ui->label_Colum_1->setText(pos);
}

void Helper_Triplet_Item::Set_C2Par(QString par)
{
    ui->label_Colum_2->setText(par);
}

void Helper_Triplet_Item::Set_C3Par(QString par)
{
    ui->label_Colum_3->setText(par);
}

QString Helper_Triplet_Item::Get_Pos()
{
    return ui->label_Colum_1->text();
}

QString Helper_Triplet_Item::Get_C2Par()
{
    return ui->label_Colum_2->text();
}

QString Helper_Triplet_Item::Get_C3Par()
{
   return  ui->label_Colum_3->text();
}
