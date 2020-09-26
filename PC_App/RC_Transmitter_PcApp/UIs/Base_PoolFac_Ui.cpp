#include "Base_PoolFac_Ui.h"
#include "ui_Base_PoolFac_Ui.h"

#include "../../../share/Graph_App/Strct_Compo_Node.h"
#include "../modfactory_qt.h"
#include <QDebug>

//static PoolOwnerUtils poolUtils;

extern Graph_App_I* currentNode;
extern UI_Visitor_I* uiVisitorExtern;

Base_PoolFac_Ui::Base_PoolFac_Ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Base_PoolFac_Ui)
{
    ui->setupUi(this);
    //scrollPool.show();
    scrollPool.setParent(this);
    ui->widgetPool->layout()->addWidget(&scrollPool);
    scrollModFac.setParent(this);
    ui->widgetRactory->layout()->addWidget(&scrollModFac);
    scrollItems.setParent(this);
    ui->widget_Items->layout()->addWidget(&scrollItems);
    trashBin = new TrashBin();
    trashBin->setParent(ui->widgetTrashBin);
    ui->widgetTrashBin->layout()->addWidget(trashBin);

    QObject::connect(trashBin, SIGNAL(DelElement(int)), &scrollItems, SLOT(DeleteElememnt(int)));
    QObject::connect(trashBin, SIGNAL(DelElement(int)), this, SLOT(DeleteElememnt(int)));
    QObject::connect(Get_ChildItems(),
                     SIGNAL(Signal_AddCompoNode(unsigned int)),
                     this ,
                     SLOT(Slot_AddCompoNodeFromPool(unsigned int)));
    QObject::connect(Get_ChildItems(),
                     SIGNAL(Signal_AddModule(unsigned int, QPixmap)),
                     this ,
                     SLOT(Slot_AddModule(unsigned int, QPixmap)));
    QObject::connect(&scrollItems, SIGNAL(Signal_Enter(uint)), this, SLOT(Slot_Enter(uint)));
    QObject::connect(ui->pushButton_Esc, SIGNAL(clicked()), this, SLOT(Slot_Esc()));
    QObject::connect(ui->pushButtonNewPool, SIGNAL(clicked()), this, SLOT(Slot_NewCompo()));
    QObject::connect(&scrollItems, SIGNAL(Signal_SwapItems(uint, uint)),this, SLOT(Slot_SwapItems(uint, uint)));
}

Base_PoolFac_Ui::~Base_PoolFac_Ui()
{
    delete ui;
}

void Base_PoolFac_Ui::SetSpecificWidget(QWidget* sW)
{
    ui->widget_Concrete->layout()->addWidget(sW);
}

void Base_PoolFac_Ui::SetTypeLabel(QString type)
{
    ui->label_Type->setText(type);
}

Scroll_Pool *Base_PoolFac_Ui::Get_ScrollPool()
{
    return &scrollPool;
}

Scroll_Items* Base_PoolFac_Ui::Get_ChildItems()
{
    return &scrollItems;
}

void Base_PoolFac_Ui::SetCurNode(Graph_App_I* cN)
{
    QString name;
    myCurNode = cN;
    utilsQt.CharrArrToQtring(myCurNode->GetNameArr(), &name);
    ui->label_Title->setText(name);
    RefreshPool();
}

PoolOwnerUtils* Base_PoolFac_Ui::GetPoolUtils()
{
    return &poolUtils;
}


void Base_PoolFac_Ui::Slot_Enter(unsigned int pos)
{
    myCurNode->Enter(&currentNode, pos);
    (*currentNode).Show(uiVisitorExtern);
}

void Base_PoolFac_Ui::Slot_Esc()
{
    myCurNode->Esc(&currentNode);
    (*currentNode).Show(uiVisitorExtern);
}

void Base_PoolFac_Ui::Slot_AddModule(unsigned int type, QPixmap pixmap)
{

    Child_Item* cI = new Child_Item();
    QString name;
    Graph_App_I* tmpGraphItm;

    cI->GetPicLabel()->setPixmap(pixmap);
    Get_ChildItems()->AddWidget((QWidget*)cI);
    Get_ChildItems()->Resize();

    tmpGraphItm = ModFactory_Qt::GetNewModule(type);
    myCurNode->GetChildList()->AddEnd(tmpGraphItm);
    utilsQt.CharrArrToQtring(tmpGraphItm->GetNameArr(), &name);
    cI->GetTextLabel()->setText(name);
}

void Base_PoolFac_Ui::Slot_AddCompoNodeFromPool(unsigned int poolPos)
{//Child_Item
    Child_Item* cI = new Child_Item();
    QString name;

    utilsQt.CharrArrToQtring(((Graph_App_I*)(poolUtils.GetPoolLst()->At(poolPos)))->GetNameArr(), &name);
    cI->GetTextLabel()->setText(name);
    Get_ChildItems()->AddWidget((QWidget*)cI);
    Get_ChildItems()->Resize();

    poolUtils.PoolToChldLstEnd(myCurNode, poolPos);
    RefreshChildArea();
}

void Base_PoolFac_Ui::QStringToCharArr(char* charArr, QString* name)
{
    unsigned int i;
    for(i=0; i<name->count(); i++)
    {
        charArr[i] = name->at(i).toLatin1();
    }
    charArr[i] = '\0';
}

void Base_PoolFac_Ui::RefreshChildArea()
{
    int childCnt = myCurNode->GetChildList()->Count();
    int childItmCnt = Get_ChildItems()->Count();
    int countDiff = childCnt - childItmCnt;
    char* nameArr;
    QString name;

    for(countDiff; countDiff > 0; countDiff--)
    {
        Get_ChildItems()->AddWidget((QWidget*)new Child_Item());
    }

    for(countDiff; countDiff < 0; countDiff++)
    {
        Get_ChildItems()->DeleteWidget(Get_ChildItems()->Count()-1);
    }
    Get_ChildItems()->Resize();

    for(int i=0; i<Get_ChildItems()->Count(); i++)
    {
        QWidget* qW = NULL;
        QLabel* qL = NULL;
        Child_Item* cI = NULL;
       name.clear();
       nameArr = myCurNode->GetChildList()->At(i)->GetNameArr();
       utilsQt.CharrArrToQtring(nameArr, &name);
       qW = Get_ChildItems()->GetWidget(i);
       cI = (Child_Item*)qW;
       qL = cI->GetTextLabel();
       qL->setText(name);
       qL = cI->GetPicLabel();
       qL->setPixmap(QPixmap(ModFactory_Qt::GetTypePicLocation(((unsigned int)myCurNode->GetChildList()->At(i)->GetType()))));
    }
}

void Base_PoolFac_Ui::RefreshPool()
{
    int countDiff = GetPoolUtils()->GetPoolLst()->Count() - Get_ScrollPool()->Count();
    char* nameArr;
    QString name;

    qDebug() << "Utils->GetPoolLst()->Count() " << GetPoolUtils()->GetPoolLst()->Count() << "  Get_ScrollPool()->Count() " << Get_ScrollPool()->Count();
    qDebug() << "Base_PoolFac_Ui::RefreshPool countDiff " <<  countDiff;

    for(countDiff; countDiff > 0; countDiff--)
    {
        Get_ScrollPool()->AddWidget((QWidget*)new Compo_Pool_Item());
    }

    for(countDiff; countDiff < 0; countDiff++)
    {
        Get_ScrollPool()->DeleteWidget(((unsigned int)(-countDiff))-1);//(Get_ScrollPool()->Count()-1);
    }
    Get_ScrollPool()->Resize();

    for(int i=0; i<GetPoolUtils()->GetPoolLst()->Count(); i++)
    {
       name.clear();
       nameArr = ((Graph_App_I*)(GetPoolUtils()->GetPoolLst()->At(i)))->GetNameArr();
       utilsQt.CharrArrToQtring(nameArr, &name);
       ((Compo_Pool_Item*)(Get_ScrollPool()->GetWidget(i)))->GetLabel()->setText(name);
    }
}

void Base_PoolFac_Ui::Slot_NewCompo()
{
    //RefreshPool();
    Compo_Pool_Item* compItm;
    Strct_Compo_Node* compNodePtr;
    QString name = ui->plainTextEdit_NewCompoName->toPlainText();
    compNodePtr = new Strct_Compo_Node();
    QStringToCharArr(compNodePtr->GetNameArr(), &name);
    //compNodePtr->FillNameArray(compNodePtr->GetNameArr(), "Compo 1", 7);
    GetPoolUtils()->AddToPoolLstEnd(compNodePtr);

    compItm = new Compo_Pool_Item();
    compItm->GetLabel()->setText(name);
    Get_ScrollPool()->AddWidget((QWidget*)compItm);
    Get_ScrollPool()->Resize();
}

void Base_PoolFac_Ui::Slot_SwapItems(uint srcChldSel, uint swapTar)
{
    int16_t steps;
    steps = swapTar - srcChldSel;
    myCurNode->GetChildList()->MoveItmAtLoc(srcChldSel, steps);
}

void Base_PoolFac_Ui::DeleteElememnt(int delDest)
{
    myCurNode->GetChildList()->DelAtLoc(delDest);
}
