#include "Calc_uCAdc_Leaf_UI.h"
#include "ui_Calc_uCAdc_Leaf_UI.h"

extern Graph_App_I* currentNode;
extern UI_Visitor_I* uiVisitorExtern;

Calc_uCAdc_Leaf_UI::Calc_uCAdc_Leaf_UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calc_uCAdc_Leaf_UI)
{
    ui->setupUi(this);
    connect(ui->pushButton_ESC, SIGNAL(clicked()), this, SLOT(Slot_Esc()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(Slot_SpinValChng(int)));
}

Calc_uCAdc_Leaf_UI::~Calc_uCAdc_Leaf_UI()
{
    delete ui;
}

void Calc_uCAdc_Leaf_UI::SetRef(Calc_uCAdc_Leaf* ref)
{
    myRef = ref;
    ui->spinBox->setValue(myRef->GetChnlVal());
}

void Calc_uCAdc_Leaf_UI::Slot_Esc()
{
    myRef->Esc(&currentNode);
    (*currentNode).Show(uiVisitorExtern);
}

void Calc_uCAdc_Leaf_UI::Slot_SpinValChng(int)
{
    myRef->SetChnlSel((uint16_t)(ui->spinBox->value()));
}
