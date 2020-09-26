#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLCDNumber>

#include"Modell_Manager_Qt.h"
#include "Bluetooth/chat.h"

#include "../../share/Visitor_InternTrim.h"
#include "../../share/Notifier_InternTrimm.h"
#include "../../share/SystickNotifier.h"
#include "../../share/QuadEncNofityer.h"

#include "../../share/Graph_App/Strct_ChnlMngr_Node.h"
#include "../../share/Graph_App/Strct_Chnl_Node.h"
#include "../../share/Graph_App/Strct_MultSw_Node.h"
#include "../../share/Graph_App/Strct_Chnl_Node.h"
#include "../../share/Graph_App/Strct_ChnlMngr_Node.h"

#include "../../share/UIs/Ui_VisitorQt.h"

#include "UIs/Base_PoolFac_Ui.h"
#include "UIs/Strct_Compo_Node_UI.h"
#include "UIs/Calc_Multiplication_Leaf_UI.h"
#include "UIs/Strct_Junc_Node_UI.h"
#include "UIs/Strct_Multi_Sw_Node_UI.h"
#include "UIs/Strct_Chnl_Node_UI.h"
#include "UIs/Strct_ChnlMngr_Node_UI.h"
#include "UIs/Calc_uCAdc_Leaf_UI.h"
#include "UIs/Src_CstmSw_Leaf_Ui.h"
#include "UIs/Time_Blinker_Leaf_UI.h"
#include "UIs/Calc_ScaleSw_Leaf_Ui.h"
#include "UIs/Calc_Quantizer_Leaf_UI.h"

#include "UIs/Qt_ControlCockpit.h"

#include "Serial_Uart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    Ui_VisitorQt uiVisitor;

    Strct_Compo_Node_UI cmpoNodUi;
    Calc_Multiplication_Leaf_UI multUi;
    Strct_Junc_Node_UI juncUi;
    Strct_Multi_Sw_Node_UI multSwiUi;
    Strct_Chnl_Node_UI channelUi;
    Strct_ChnlMngr_Node_UI chnlMngrUi;
    Calc_uCAdc_Leaf_UI adcChnlSelUi;
    Src_CstmSw_Leaf_Ui cstmSwUi;
    Time_Blinker_Leaf_UI blinkUi;
    Calc_ScaleSw_Leaf_Ui scaleSwitch;
    Calc_Quantizer_Leaf_UI quantizerUi;

    Qt_ControlCockpit cockPitUi;

    //Strct_Compo_Node compoNode;
    //Strct_Junc_Node juncNode;
    //Strct_MultSw_Node multNode;
    Strct_ChnlMngr_Node root;

    Serial_Uart serialUart;

    QList<float> sendValsList;
    float offset[4];
    int offsetMerker;
    float inputAnaBuffer[4];
    unsigned int inputDigBuffer;

    QTimer tickTimer;
    QTimer standAloneTick;

    Modell_Manager_Qt saveLoadDest;

    Chat btChat;

    QList<QLCDNumber*> pBtnLst;

    int mode;
    unsigned int currentIndex;

    #define EXTERN_DATA 0
    #define INTERN_DATA 1
    unsigned int curDataSrc;
    #define EXTERN_CLK   0
    #define INTERN_CLK   1
    unsigned int curClkSrc;

    void FillInputMembers();
    void FillInputMeters();
    void SentDatas();
    void ShowOutput();
    void ProcessInBuffer();

private slots:
    void Slot_ShowIt();
    void Slot_Received();
    void Slot_Connect();
    void Slot_TickTimerElapsed();
    void Slot_Save(Modell_Manager_Qt* modMngrRef);
    void Slot_Load(Modell_Manager_Qt* modMngrRef);
    void Slot_Switch();
    void Slot_Clear();
    void Slot_DataSel();
    void Slot_ClkSel();
};
#endif // WIDGET_H
