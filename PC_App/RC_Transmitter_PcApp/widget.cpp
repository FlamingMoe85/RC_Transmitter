#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

#define UART
//#define BT

Visitor_InternTrim VisitorInternTrim;
Notifier_InternTrimm NotifyerInternTrim;
SystickNotifier sysTickNoty;
QuadEncNofityer quadNoty;

float fourAdcs[4];
uint32_t digInArrBits;

UI_Visitor_I* uiVisitorExtern;
Graph_App_I* currentNode;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    uiVisitor.SetUiArea(ui->stackedWidget);

    uiVisitor.SetCompNodeUiRef(&cmpoNodUi);
    ui->stackedWidget->addWidget(&cmpoNodUi);

    uiVisitor.SetCalcMult_UiRef(&multUi);
    ui->stackedWidget->addWidget(&multUi);

    uiVisitor.SetJunc_UiRef(&juncUi);
    ui->stackedWidget->addWidget(&juncUi);

    uiVisitor.SetMultSw_UiRef(&multSwiUi);
    ui->stackedWidget->addWidget(&multSwiUi);

    uiVisitor.SetChnl_UiRef(&channelUi);
    ui->stackedWidget->addWidget(&channelUi);

    uiVisitor.SetChnlMngr_UiRef(&chnlMngrUi);
    ui->stackedWidget->addWidget(&chnlMngrUi);

    uiVisitor.SetuCAdc_UiRef(&adcChnlSelUi);
    ui->stackedWidget->addWidget(&adcChnlSelUi);

    uiVisitor.SetCstmSw_UiRef(&cstmSwUi);
    ui->stackedWidget->addWidget(&cstmSwUi);

    uiVisitor.SetBlinker_UiRef(&blinkUi);
    ui->stackedWidget->addWidget(&blinkUi);

    uiVisitor.SetScaleSwitch_UiRef(&scaleSwitch);
    ui->stackedWidget->addWidget(&scaleSwitch);

    uiVisitor.SetQuanti_UiRef(&quantizerUi);
    ui->stackedWidget->addWidget(&quantizerUi);

    ui->stackedWidget->addWidget(&cockPitUi);

    uiVisitorExtern = &uiVisitor;

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Slot_ShowIt()));
#ifdef UART
    QObject::connect(&serialUart, SIGNAL(Signal_Recieved()), this, SLOT(Slot_Received()));
#endif
#ifdef BT
    QObject::connect(&btChat, SIGNAL(Signal_Recieved()), this, SLOT(Slot_Received()));
#endif
    connect(ui->pushButton_Connect, SIGNAL(clicked()), this, SLOT(Slot_Connect()));
    connect(&tickTimer, SIGNAL(timeout()), this, SLOT(Slot_TickTimerElapsed()));
    //connect(ui->pushButton_Load, SIGNAL(clicked()), this, SLOT(Slot_Load()));
    connect(&chnlMngrUi, SIGNAL(Signal_Save(Modell_Manager_Qt*)), this, SLOT(Slot_Save(Modell_Manager_Qt*)));
    connect(&chnlMngrUi, SIGNAL(Signal_Load(Modell_Manager_Qt*)), this, SLOT(Slot_Load(Modell_Manager_Qt*)));
    connect(ui->pushButton_Switch, SIGNAL(clicked()), this, SLOT(Slot_Switch()));
    connect(ui->pushButton_Clear, SIGNAL(clicked()), this, SLOT(Slot_Clear()));
    connect(ui->pushButton_ClkSrc, SIGNAL(clicked()), this, SLOT(Slot_ClkSel()));
    connect(ui->pushButton_DataSrc, SIGNAL(clicked()), this, SLOT(Slot_DataSel()));

    //cmpoNodUi.setParent(this);
    //ui->stackedWidget->insertWidget(0, &cmpoNodUi);

    //ui->stackedWidget->children().

    //compoNode.FillNameArray(compoNode.GetNameArr(), "Start Node", 10);
    root.FillNameArray(root.GetNameArr(), "Channel Manager", 15);
    currentNode = &root;
    root.RunKindaConst();

    root.GetChildList()->AddEnd(new Strct_Chnl_Node);
    root.GetChildList()->At(root.GetChildList()->Count()-1)->FillNameArray(root.GetChildList()->At(root.GetChildList()->Count()-1)->GetNameArr(), "Channel 1", 9);

    root.GetChildList()->AddEnd(new Strct_Chnl_Node);
    root.GetChildList()->At(root.GetChildList()->Count()-1)->FillNameArray(root.GetChildList()->At(root.GetChildList()->Count()-1)->GetNameArr(), "Channel 2", 9);

    root.GetChildList()->AddEnd(new Strct_Chnl_Node);
    root.GetChildList()->At(root.GetChildList()->Count()-1)->FillNameArray(root.GetChildList()->At(root.GetChildList()->Count()-1)->GetNameArr(), "Channel 3", 9);

    root.GetChildList()->AddEnd(new Strct_Chnl_Node);
    root.GetChildList()->At(root.GetChildList()->Count()-1)->FillNameArray(root.GetChildList()->At(root.GetChildList()->Count()-1)->GetNameArr(), "Channel 4", 9);

    root.GetChildList()->AddEnd(new Strct_Chnl_Node);
    root.GetChildList()->At(root.GetChildList()->Count()-1)->FillNameArray(root.GetChildList()->At(root.GetChildList()->Count()-1)->GetNameArr(), "Channel 5", 9);

    root.GetChildList()->AddEnd(new Strct_Chnl_Node);
    root.GetChildList()->At(root.GetChildList()->Count()-1)->FillNameArray(root.GetChildList()->At(root.GetChildList()->Count()-1)->GetNameArr(), "Channel 6", 9);

    root.GetChildList()->AddEnd(new Strct_Chnl_Node);
    root.GetChildList()->At(root.GetChildList()->Count()-1)->FillNameArray(root.GetChildList()->At(root.GetChildList()->Count()-1)->GetNameArr(), "Channel 7", 9);

    sendValsList.append(1);
    sendValsList.append(2);
    sendValsList.append(3);
    sendValsList.append(4);
    sendValsList.append(5);
    sendValsList.append(6);
    sendValsList.append(7);

    offsetMerker = 0;

    pBtnLst.append(ui->lcdNumber_CH_1);
    pBtnLst.append(ui->lcdNumber_CH_2);
    pBtnLst.append(ui->lcdNumber_CH_3);
    pBtnLst.append(ui->lcdNumber_CH_4);
    pBtnLst.append(ui->lcdNumber_CH_5);
    pBtnLst.append(ui->lcdNumber_CH_6);
    pBtnLst.append(ui->lcdNumber_CH_7);

    tickTimer.setInterval(20);
    tickTimer.start();

    standAloneTick.setInterval(20);
    standAloneTick.start();


    mode = 0;
    curDataSrc = EXTERN_DATA;
    curClkSrc = EXTERN_CLK;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Slot_ShowIt()
{
    //compoNode.Show();
    currentNode->Show(&uiVisitor);
}

void Widget::Slot_Received()
{
    qDebug() << "Slot_Received";
    FillInputMembers();
    FillInputMeters();
    ProcessInBuffer();
    root.Run();
    ShowOutput();
    SentDatas();
}


void Widget::SentDatas()
{

    sendValsList.clear();
    for(int i=0; i<7; i++)
    {
        sendValsList.append((float)root.GetChnlVal(i));
    }
#ifdef BT
    btChat.SendNumebrs(&sendValsList);
#endif
#ifdef UART
    serialUart.SendNumebrs(&sendValsList);
#endif
}

void Widget::ShowOutput()
{
    for(int i=0; i<sendValsList.count(); i++)
    {
        pBtnLst.at(i)->display((int)sendValsList.at(i));
    }
    qDebug() << (int)sendValsList.at(6);
}

void Widget::ProcessInBuffer()
{
    if(offsetMerker < 5)
    {
        offsetMerker++;
    }
    else if(offsetMerker == 5)
    {
        offset[0] = inputAnaBuffer[0];
        offset[1] = inputAnaBuffer[1];
        offset[2] = inputAnaBuffer[2];
        offset[3] = inputAnaBuffer[3];
        offsetMerker++;
    }
    else
    {

        if(curDataSrc == EXTERN_DATA)
        {
            fourAdcs[0] = (inputAnaBuffer[0]-offset[0])*0.48828125;
            fourAdcs[1] = (inputAnaBuffer[1]-offset[1])*0.48828125;
            fourAdcs[2] = (inputAnaBuffer[2]-offset[2])*0.48828125;
            fourAdcs[3] = (inputAnaBuffer[3]-offset[3])*0.48828125;
        }
        else
        {
            fourAdcs[0] = (inputAnaBuffer[0]-offset[0]);
            fourAdcs[1] = (inputAnaBuffer[1]-offset[1]);
            fourAdcs[2] = (inputAnaBuffer[2]-offset[2]);
            fourAdcs[3] = (inputAnaBuffer[3]-offset[3]);
        }
        digInArrBits = inputDigBuffer;
    }

}

void Widget::Slot_Save(Modell_Manager_Qt* modMngrRef)
{
    root.Serialize(modMngrRef);
    modMngrRef->Close();
}

void Widget::Slot_Load(Modell_Manager_Qt* modMngrRef)
{
    qDebug() << "Load";
    root.Deserialize(modMngrRef);
    modMngrRef->Close();
    chnlMngrUi.RefreshPool();
}

void Widget::Slot_Connect()
{
    btChat.connectClicked();
}

void Widget::Slot_Clear()
{

    //chnlMngrUi.ClearPoolList();
    for(int i=0; i<7; i++)
    {
      //  root.GetChildList()->At(i)->Clear();
    }
}

void Widget::Slot_TickTimerElapsed()
{
    sysTickNoty.Notify();
}

void Widget::Slot_Switch()
{
    if(mode == 0)
    {
        currentIndex = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentWidget(&cockPitUi);
        mode = 1;
    }
    else
    {
        mode = 0;
        ui->stackedWidget->setCurrentIndex(currentIndex);
    }
}

void Widget::FillInputMeters()
{
    ui->lcdNumber_1->display((int)(inputAnaBuffer[0] - offset[0]));
    ui->lcdNumber_2->display((int)inputAnaBuffer[1] - offset[1]);
    ui->lcdNumber_3->display((int)inputAnaBuffer[2] - offset[2]);
    ui->lcdNumber_4->display((int)inputAnaBuffer[3] - offset[3]);

    ui->lcdNumber_5->display((int)inputDigBuffer);
}

void Widget::FillInputMembers()
{
    if(curDataSrc == EXTERN_DATA)
    {
#ifdef BT
        for(int i=0; i<btChat.GetAdcList()->count(); i++)
        {
            inputAnaBuffer[i] = (float)btChat.GetAdcList()->at(i);
        }
        if(btChat.GetDigList()->count() > 0)
        {
            inputDigBuffer = btChat.GetDigList()->at(0);
        }
#endif
#ifdef UART
        for(int i=0; i<serialUart.GetAdcList()->count(); i++)
        {
            inputAnaBuffer[i] = (float)serialUart.GetAdcList()->at(i);
        }
        if(serialUart.GetDigList()->count() > 0)
        {
            inputDigBuffer = serialUart.GetDigList()->at(0);
        }
#endif
    }
    else
    {
        inputAnaBuffer[3] = cockPitUi.GetRight_X();
        inputAnaBuffer[2] = cockPitUi.GetRight_Y();
        inputDigBuffer = cockPitUi.GetDigitals();
    }
}

void Widget::Slot_DataSel()
{
    if(curDataSrc == EXTERN_DATA)
    {
        ui->pushButton_DataSrc->setText("Intern Data");
        curDataSrc = INTERN_DATA;
        offsetMerker = 0;
        offset[0] = 0;
        offset[1] = 0;
        offset[2] = 0;
        offset[3] = 0;
    }
    else
    {
        ui->pushButton_DataSrc->setText("Extern Data");
        curDataSrc = EXTERN_DATA;
    }
}

void Widget::Slot_ClkSel()
{
    if(curClkSrc == EXTERN_CLK)
    {
        curClkSrc = INTERN_CLK;
        ui->pushButton_ClkSrc->setText( "Intern Clock");

        #ifdef UART
        QObject::disconnect(&serialUart, SIGNAL(Signal_Recieved()), this, SLOT(Slot_Received()));
        #endif
        #ifdef BT
        QObject::disconnect(&btChat, SIGNAL(Signal_Recieved()), this, SLOT(Slot_Received()));
        #endif

        connect(&standAloneTick, SIGNAL(timeout()), this, SLOT(Slot_Received()));
    }
    else
    {
        curClkSrc = EXTERN_CLK;
        offsetMerker = 0;
        ui->pushButton_ClkSrc->setText( "Extern Clock");
        disconnect(&standAloneTick, SIGNAL(timeout()), this, SLOT(Slot_Received()));
        #ifdef UART
        QObject::connect(&serialUart, SIGNAL(Signal_Recieved()), this, SLOT(Slot_Received()));
        #endif
        #ifdef BT
        QObject::connect(&btChat, SIGNAL(Signal_Recieved()), this, SLOT(Slot_Received()));
        #endif
    }
}
