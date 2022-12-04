#include "Save_Load_Ui.h"
#include "ui_Save_Load_Ui.h"

#include <QDebug>
#include <QDir>

Save_Load_Ui::Save_Load_Ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Save_Load_Ui)
{
    ui->setupUi(this);
    load.DefinePixMap(ROCKET);
    ui->widget_Load->layout()->addWidget(&load);
    ui->widget_Delete->layout()->addWidget(&remove);
    ui->widget_ModSelArea->layout()->addWidget(&availbleMods);

    connect(ui->pushButton_Save, SIGNAL(clicked()), this, SLOT(Slot_Save()));
    connect(&load, SIGNAL(DelElement(int)), this, SLOT(Slot_Load(int)));
    connect(&remove, SIGNAL(DelElement(int)), this, SLOT(Slot_Delete(int)));
}

Save_Load_Ui::~Save_Load_Ui()
{
    delete ui;
}

void Save_Load_Ui::findModels(QStringList *result)//(const QString &path, const QString &pattern, QStringList *result)
{
    QDir currentDir;
    result->clear();
    foreach (const QString &match, currentDir.entryList(QStringList("*.txt"), QDir::Files | QDir::NoSymLinks))
    {
            QString parName = match.mid(0, match.count()-4);
            result->append(parName);

        }
    /*
    foreach (const QString &dir, currentDir.entryList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot))
        findRecursion(prefix + dir, pattern, result);
    */
    //findRecursion(result);
}

void Save_Load_Ui::RefreshModelList()
{
    int childCnt;// = myCurNode->GetChildList()->Count();
    int childItmCnt;// = Get_ChildItems()->Count();
    int countDiff;// = childCnt - childItmCnt;
    Compo_Pool_Item tmpModItm;

    findModels(&foundModels);
    childCnt = foundModels.count();
    childItmCnt = availbleMods.Count();
    countDiff = childCnt - childItmCnt;

    //for(countDiff; countDiff > 0; countDiff--)
    while(countDiff > 0)
    {
        availbleMods.AddWidget((QWidget*)new Compo_Pool_Item());
        countDiff--;
    }

    //for(countDiff; countDiff < 0; countDiff++)
    while(countDiff < 0)
    {
        availbleMods.DeleteWidget(availbleMods.Count()-1);
         countDiff++;
    }
    availbleMods.Resize();

    for(int i=0; i<foundModels.count(); i++)
    {
        ((Compo_Pool_Item*)(availbleMods.GetWidget(i)))->GetLabel()->setText(foundModels.at(i));
    }
}

void Save_Load_Ui::Slot_Save()
{

    modMngr.OpenModel(ui->plainTextEdit_Name->toPlainText());
     Signal_Save(&modMngr);
     RefreshModelList();
}

void Save_Load_Ui::Slot_Load(int loadSel)
{
    qDebug() << "loadSel " <<loadSel;
     modMngr.OpenModel(foundModels.at(loadSel));
     Signal_Load(&modMngr);
}

void Save_Load_Ui::Slot_Delete(int delSel)
{
    (void)delSel;
}
