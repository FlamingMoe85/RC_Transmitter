/*
 * Wizard_TwoChnlModl.h
 *
 *  Created on: 28.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_WIZARDS_WIZARD_TWOCHNLMODL_LEAF_H_
#define SHARE_GRAPH_APP_WIZARDS_WIZARD_TWOCHNLMODL_LEAF_H_

#include "../Graph_App_I.h"
#include "../../std/Graph_Node.h"
#include "../../globaldefinesshare.h"
#include "../GraphAppCommons.h"
#include "../../UIs/Ui_Visitor_I.hpp"

#include "../PoolOwnerUtils.h"

#include "I_WizardDeserial.hpp"

#define GAS			0
#define GAS_SCL		1
#define STEER		2
#define STEER_SCL	3

class Wizard_TwoChnlModl_Leaf : public Graph_Node<Graph_App_I>, public PoolOwnerUtils, public I_WizardDeserial{
public:
	Wizard_TwoChnlModl_Leaf();
	virtual ~Wizard_TwoChnlModl_Leaf();

    virtual void Run(float* val, uint32_t itteration){ };
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest){ };
    virtual void Deserialize(SerializeDest_I* SerDest){ };
    virtual void NullSerCntr(){ };

    virtual void GetName(char* nameArr);
    virtual uint16_t GetUint16();
    virtual int16_t GetInt16();


    void Generate();
    int16_t AddValtoSel(uint16_t sel, int16_t val);
    uint16_t GetSel(uint16_t sel);


private:

    int16_t AddValToSel(uint16_t sel, int16_t val);
    int16_t SubValFromSel(uint16_t sel, uint16_t val);
    UI_Visitor_I *myUiVisitor;
    //char name[] = "Intern Trim";
    uint16_t dataCntr;
    uint16_t* dataArrRef;
    char* nameRef;
    int16_t selADC[4];
};

#endif /* SHARE_GRAPH_APP_WIZARDS_WIZARD_TWOCHNLMODL_LEAF_H_ */
