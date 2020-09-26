#include "Module_Item.h"
#include "ui_Module_Itemm.h"

#include "../../modfactory_qt.h"

Module_Item::Module_Item(QWidget *parent, unsigned int type) :
    QWidget(parent),
    ui(new Ui::Module_Item)
{
    ui->setupUi(this);
    myType = type;
    ui->label_ModulePic->setPixmap(QPixmap(ModFactory_Qt::GetTypePicLocation(type)));
    /*
    switch(type)
    {
        case MULT_TYP:
            ui->label_ModulePic->setPixmap(QPixmap(":/images/mult.png"));
            break;

    case ADCuC_TYP:
        ui->label_ModulePic->setPixmap(QPixmap(":/images/channelSel.png"));
        break;

    case CSTMSW_TYP:
        ui->label_ModulePic->setPixmap(QPixmap(":/images/switch.png"));
        break;
    }
    */
}

Module_Item::~Module_Item()
{
    delete ui;
}

unsigned int Module_Item::GetType()
{
    return myType;
}

void Module_Item::SetPic(QPixmap pic)
{
    ui->label_ModulePic->setPixmap(pic);
}

const QPixmap* Module_Item::GetPic()
{
    ui->label_ModulePic->pixmap();
}
