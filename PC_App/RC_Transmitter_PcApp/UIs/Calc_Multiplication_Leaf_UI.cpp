#include "Calc_Multiplication_Leaf_UI.h"
#include "ui_Calc_Multiplication_Leaf_UI.h"

extern Graph_App_I* currentNode;
extern UI_Visitor_I* uiVisitorExtern;

Calc_Multiplication_Leaf_UI::Calc_Multiplication_Leaf_UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calc_Multiplication_Leaf_UI)
{
    ui->setupUi(this);
    connect(ui->pushButton_Esc, SIGNAL(clicked()), this, SLOT(Slot_Esc()));
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(Slot_SpinValChng(double)));
}

Calc_Multiplication_Leaf_UI::~Calc_Multiplication_Leaf_UI()
{
    delete ui;
}

void Calc_Multiplication_Leaf_UI::SetRef(Calc_Multiplication_Leaf* ref)
{
    myRef = ref;
    ui->doubleSpinBox->setValue(((double)myRef->GetMulVal())/10);
}

void Calc_Multiplication_Leaf_UI::Slot_Esc()
{
    myRef->Esc(&currentNode);
    (*currentNode).Show(uiVisitorExtern);
}

void Calc_Multiplication_Leaf_UI::Slot_SpinValChng(double)
{
    myRef->SetMulVal((int16_t)(ui->doubleSpinBox->value()*10));
}
