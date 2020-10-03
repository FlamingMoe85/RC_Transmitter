QT       +=  core gui \
             widgets serialport\
            bluetooth\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11\
            mobility


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS \
            QT_CREATOR


#INCLUDEPATH +=  C:\Qt\RC_Transmitter_Work\share \
#                C:\Qt\RC_Transmitter_Work\share\Graph_App \
#                C:\Qt\RC_Transmitter_Work\share\std \
#                C:\Qt\RC_Transmitter_Work\PC_App\RC_Transmitter_PcApp\UIs\Helper


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../share/Graph_App/Calc_Addition_Leaf.cpp \
    ../../share/Graph_App/Calc_Multiplication_Leaf.cpp \
    ../../share/Graph_App/Calc_ScaleSw_Leaf.cpp \
    ../../share/Graph_App/Calc_uCAdc_Leaf.cpp \
    ../../share/Graph_App/GraphAppCommons.cpp \
    ../../share/Graph_App/PoolOwnersUtils.cpp \
    ../../share/Graph_App/Src_CstmSw_Leaf.cpp \
    ../../share/Graph_App/Src_InternTrim_Leaf.cpp \
    ../../share/Graph_App/Strct_CalcFactory.cpp \
    ../../share/Graph_App/Strct_ChnlMngr_Node.cpp \
    ../../share/Graph_App/Strct_Chnl_Node.cpp \
    ../../share/Graph_App/Strct_Chnl_Owners.cpp \
    ../../share/Graph_App/Strct_Compo_Node.cpp \
    ../../share/Graph_App/Strct_Dummy_Leaf.cpp \
    ../../share/Graph_App/Strct_Junc_Node.cpp \
    ../../share/Graph_App/Strct_MultSw_Node.cpp \
    ../../share/Graph_App/Strct_PoolOwner_Node.cpp \
    ../../share/Graph_App/Strct_SaveLoad_Node.cpp \
    ../../share/Graph_App/Strct_TopMenue_Node.cpp \
    ../../share/Graph_App/TimeCalc_Ramp_Leaf.cpp \
    ../../share/Graph_App/Time_Blinker_Leaf.cpp \
    ../../share/Notifier_InternTrimm.cpp \
    ../../share/QuadEncConsumerBase.cpp \
    ../../share/QuadEncNofityer.cpp \
    ../../share/SystickConsumerBase.cpp \
    ../../share/SystickNotifier.cpp \
    ../../share/Visitor_InternTrim.cpp \
    ../../share/std/Graph_Itt.cpp \
    Save_Load_Ui.cpp \
    UIs/Base_Quadlet_Ui.cpp \
    UIs/Helper/Helper_Quadlet_Item.cpp \
    Utils_Qt.cpp \
    UIs/Helper/Origin.cpp \
    UIs/Helper/Scroll_Pool.cpp \
    UIs/Helper/ScrollAreaVert.cpp \
    UIs/Base_PoolFac_Ui.cpp \
    main.cpp \
    widget.cpp \
    UIs/Helper/Scroll_ModFactory.cpp \
    UIs/Helper/Scroll_Items.cpp \
    UIs/Helper/TrashBin.cpp \
    UIs/Strct_Compo_Node_UI.cpp \
    UIs/Helper/Compo_Pool_Item.cpp \
    UIs/Helper/Child_Item.cpp \
    ../../share/UIs/Ui_VisitorQt.cpp \
    UIs/Helper/Module_Item.cpp \
    modfactory_qt.cpp \
    UIs/Calc_Multiplication_Leaf_UI.cpp \
    UIs/Strct_Junc_Node_UI.cpp \
    UIs/Strct_Multi_Sw_Node_UI.cpp \
    UIs/Helper/Helper_MultiSw.cpp \
    UIs/Strct_Chnl_Node_UI.cpp \
    UIs/Helper/Helper_ChannelNode.cpp \
    UIs/Strct_ChnlMngr_Node_UI.cpp \
    Serial_Uart.cpp \
    UIs/Calc_uCAdc_Leaf_UI.cpp \
    UIs/Base_Triplet_Ui.cpp \
    UIs/Helper/Scroll_Triplet.cpp \
    UIs/Helper/Helper_Triplet_Item.cpp \
    UIs/Src_CstmSw_Leaf_Ui.cpp \
    UIs/Time_Blinker_Leaf_UI.cpp \
    UIs/Calc_ScaleSw_Leaf_Ui.cpp \
    UIs/Calc_Quantizer_Leaf_UI.cpp \
    ../../share/Graph_App/Calc_Quantizer_Leaf.cpp \
    Modell_Manager_Qt.cpp \
    Bluetooth/chat.cpp \
    Bluetooth/chatclient.cpp \
    Bluetooth/chatserver.cpp \
    Bluetooth/remoteselector.cpp \
    UIs/Qt_ControlCockpit.cpp \
    UIs/Qt_ControlKnop.cpp \
    UIs/Helper/Scroll_Quadlet.cpp

    ../../share/UIs/Ui_Visitor.cpp

HEADERS += \
    ../../share/Graph_App/Calc_Addition_Leaf.h \
    ../../share/Graph_App/Calc_Multiplication_Leaf.h \
    ../../share/Graph_App/Calc_ScaleSw_Leaf.h \
    ../../share/Graph_App/Calc_uCAdc_Leaf.h \
    ../../share/Graph_App/GraphAppCommons.h \
    ../../share/Graph_App/PoolOwnerUtils.h \
    ../../share/Graph_App/Src_CstmSw_Leaf.h \
    ../../share/Graph_App/Src_InternTrim_Leaf.h \
    ../../share/Graph_App/Strct_CalcFactory.h \
    ../../share/Graph_App/Strct_ChnlMngr_Node.h \
    ../../share/Graph_App/Strct_Chnl_Node.h \
    ../../share/Graph_App/Strct_Chnl_Owners.h \
    ../../share/Graph_App/Strct_Compo_Node.h \
    ../../share/Graph_App/Strct_Dummy_Leaf.h \
    ../../share/Graph_App/Strct_Junc_Node.h \
    ../../share/Graph_App/Strct_MultSw_Node.h \
    ../../share/Graph_App/Strct_PoolOwner_Node.h \
    ../../share/Graph_App/Strct_SaveLoad_Node.h \
    ../../share/Graph_App/Strct_TopMenue_Node.h \
    ../../share/Graph_App/TimeCalc_Ramp_Leaf.h \
    ../../share/Graph_App/Time_Blinker_Leaf.h \
    ../../share/Graph_App/graph_app_i.h \
    ../../share/Notifier_InternTrimm.h \
    ../../share/QuadEncConsumerBase.h \
    ../../share/QuadEncNofityer.h \
    ../../share/QuadEnc_I.hpp \
    ../../share/StorageHandler/StorageHandler_I.hpp \
    ../../share/SystickConsumerBase.h \
    ../../share/SystickNotifier.h \
    ../../share/Systick_I.hpp \
    ../../share/UIs/Ui_Visitor_I.hpp \
    ../../share/Visitor_InternTrim.h \
    ../../share/globaldefinesshare.h \
    ../../share/std/Graph_Itt.h \
    ../../share/std/List.hpp \
    ../../share/std/SerializeDest_I.hpp \
    ../../share/std/graph_basic_i.h \
    ../../share/std/graph_common.hpp \
    ../../share/std/graph_leaf.hpp \
    ../../share/std/graph_node.h \
    Save_Load_Ui.h \
    UIs/Base_Quadlet_Ui.h \
    UIs/Helper/Helper_Quadlet_Item.h \
    Utils_Qt.h \
    ../../share/UIs/Ui_Visitor_I.hpp \
    UIs/Helper/Origin.h \
    UIs/Helper/Scroll_Pool.h \
    UIs/Helper/ScrollAreaVert.h \
    UIs/Base_PoolFac_Ui.h \
    widget.h \
    UIs/Helper/Scroll_ModFactory.h \
    UIs/Helper/Scroll_Items.h \
    UIs/Helper/TrashBin.h \
    UIs/Strct_Compo_Node_UI.h \
    UIs/Helper/Compo_Pool_Item.h \
    UIs/Helper/Child_Item.h \
    ../../share/UIs/Ui_VisitorQt.h \
    UIs/Helper/Module_Item.h \
    modfactory_qt.h \
    UIs/Calc_Multiplication_Leaf_UI.h \
    UIs/Strct_Junc_Node_UI.h \
    UIs/Strct_Multi_Sw_Node_UI.h \
    UIs/Helper/Helper_MultiSw.h \
    UIs/Strct_Chnl_Node_UI.h \
    UIs/Helper/Helper_ChannelNode.h \
    UIs/Strct_ChnlMngr_Node_UI.h \
    Serial_Uart.h \
    UIs/Calc_uCAdc_Leaf_UI.h \
    UIs/Base_Triplet_Ui.h \
    UIs/Helper/Scroll_Triplet.h \
    UIs/Helper/Helper_Triplet_Item.h \
    UIs/Src_CstmSw_Leaf_Ui.h \
    UIs/Time_Blinker_Leaf_UI.h \
    UIs/Calc_ScaleSw_Leaf_Ui.h \
    UIs/Calc_Quantizer_Leaf_UI.h \
    ../../share/Graph_App/Calc_Quantizer_Leaf.h \
    Modell_Manager_Qt.h \
    Bluetooth/chat.h \
    Bluetooth/chatclient.h \
    Bluetooth/chatserver.h \
    Bluetooth/remoteselector.h \
    UIs/Qt_ControlCockpit.h \
    UIs/Qt_ControlKnop.h \
    ../../share/UIs/Ui_Visitor.h \
    UIs/Helper/Scroll_Quadlet.h

FORMS += \
    Save_Load_Ui.ui \
    UIs/Base_Quadlet_Ui.ui \
    UIs/Helper/Helper_Quadlet_Item.ui \
    widget.ui \
    UIs/Base_PoolFac_Ui.ui \
    UIs/Helper/ScrollAreaVert.ui \
    UIs/Helper/Origin.ui \
    UIs/Helper/TrashBin.ui \
    UIs/Helper/Compo_Pool_Item.ui \
    UIs/Helper/Child_Item.ui \
    UIs/Helper/Module_Itemm.ui \
    UIs/Calc_Multiplication_Leaf_UI.ui \
    UIs/Helper/Helper_MultiSw.ui \
    UIs/Helper/Helper_ChannelNode.ui \
    UIs/Calc_uCAdc_Leaf_UI.ui \
    UIs/Base_Triplet_Ui.ui \
    UIs/Helper/Helper_Triplet_Item.ui \
    Bluetooth/remoteselector.ui \
    UIs/Qt_ControlCockpit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/A.png \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

RESOURCES += \
    images.qrc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
