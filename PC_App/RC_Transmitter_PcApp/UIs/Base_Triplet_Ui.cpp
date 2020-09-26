#include "Base_Triplet_Ui.h"
#include "ui_Base_Triplet_Ui.h"

#include <QDebug>

extern Graph_App_I* currentNode;
extern UI_Visitor_I* uiVisitorExtern;

Base_Triplet_Ui::Base_Triplet_Ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Base_Triplet_Ui)
{
    ui->setupUi(this);
    tripletScrollArea.setParent(this);
    ui->widget_ScrollHook->layout()->addWidget(&tripletScrollArea);

    connect(ui->pushButton_ESC, SIGNAL(clicked()), this, SLOT(Slot_Esc()));
    connect(ui->pushButton_NewItem, SIGNAL(clicked()), this, SLOT(Slot_NewItm()));

    connect(ui->doubleSpinBox_C2, SIGNAL(valueChanged(double)), this, SLOT(Slot_SpinBx2(double)));
    connect(ui->doubleSpinBox_C3, SIGNAL(valueChanged(double)), this, SLOT(Slot_SpinBx3(double)));

    connect(&tripletScrollArea, SIGNAL(Signal_SelectForChange(uint)), this, SLOT(Slot_ItemSel(uint)));

    curItem = NULL;
    myCurSelItem = 0;
}

Base_Triplet_Ui::~Base_Triplet_Ui()
{
    delete ui;
}

void Base_Triplet_Ui::SetCurNode(Graph_App_I* cN)
{
    myCurNode = cN;
}

void Base_Triplet_Ui::Base_Triplet_Ui::Slot_Esc()
{
    myCurNode->Esc(&currentNode);
    (*currentNode).Show(uiVisitorExtern);
}

void Base_Triplet_Ui::Slot_NewItm()
{
    Helper_Triplet_Item* tmpItem = new Helper_Triplet_Item();
    tmpItem->Set_Pos(QString::number(tripletScrollArea.Count()));
    curItem = NULL;
    ui->doubleSpinBox_C2->setValue(0);
    ui->doubleSpinBox_C3->setValue(0);
    /*
    tmpItem->Set_C2Par(QString::number(ui->doubleSpinBox_C2->value()));
    tmpItem->Set_C3Par(QString::number(ui->doubleSpinBox_C3->value()));
    */
    tripletScrollArea.AddWidget(tmpItem);
    tripletScrollArea.Resize();
    Signal_NewItm();
}

void Base_Triplet_Ui::SetLabelText(unsigned int labelSel, QString txt)
{
    switch(labelSel)
    {
        case 0:
            ui->label_C1_Par->setText(txt);
            break;
        case 1:
            ui->label_C2_Par->setText(txt);
            break;
        case 2:
            ui->label_C3_Par->setText(txt);
            break;
        case 3:
            ui->label_Colum_1->setText(txt);
            break;
        case 4:
            ui->label_Colum_2->setText(txt);
            break;
        case 5:
            ui->label_Colum_3->setText(txt);
            break;
    }
}

void Base_Triplet_Ui::SetSpinBoxProps(unsigned int spnBxSel, unsigned int digits, double stepSize, double min, double val)
{
    if(spnBxSel == 0)
    {
        ui->doubleSpinBox_C2->setDecimals(digits);
        ui->doubleSpinBox_C2->setSingleStep(stepSize);
        ui->doubleSpinBox_C2->setMinimum(min);
        ui->doubleSpinBox_C2->setValue(val);
    }
    else if(spnBxSel == 1)
    {
        ui->doubleSpinBox_C3->setDecimals(digits);
        ui->doubleSpinBox_C3->setSingleStep(stepSize);
        ui->doubleSpinBox_C3->setMinimum(min);
        ui->doubleSpinBox_C3->setValue(val);
    }
}

Scroll_Triplet* Base_Triplet_Ui::GetScrollArea()
{
    return &tripletScrollArea;
}



void Base_Triplet_Ui::Slot_SpinBx2(double spnVal)
{
    if(curItem != NULL)
    {
        curItem->Set_C2Par(QString::number(ui->doubleSpinBox_C2->value()));
        Signal_SpinBx2(spnVal, myCurSelItem);
    }

}
void Base_Triplet_Ui::Slot_SpinBx3(double spnVal)
{
    if(curItem != NULL)
    {
        curItem->Set_C3Par(QString::number(ui->doubleSpinBox_C3->value()));
        Signal_SpinBx3(spnVal, myCurSelItem);
    }
}

void Base_Triplet_Ui::Slot_ItemSel(unsigned int itmSel)
{
    bool ok;
    double val;
    myCurSelItem = itmSel;
    curItem = (Helper_Triplet_Item*)tripletScrollArea.GetWidget(itmSel);

    ui->label_Pos_Par->setText(curItem->Get_Pos());

    //disconnect needed, to avoid Signal-Slot-Loop ???
    val = curItem->Get_C2Par().toDouble(&ok);
    if(ok == true)
    {
        ui->doubleSpinBox_C2->setValue(val);
    }

    val = curItem->Get_C3Par().toDouble(&ok);
    if(ok == true)
    {
        ui->doubleSpinBox_C3->setValue(val);
    }
}
