/*
 * Wizard_InternTrim.h
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_WIZARDS_WIZARD_INTERNTRIM_H_
#define SHARE_GRAPH_APP_WIZARDS_WIZARD_INTERNTRIM_H_

#include "../Graph_App_I.h"
#include "../../std/Graph_Node.h"
#include "../../globaldefinesshare.h"
#include "../GraphAppCommons.h"
#include "../../UIs/Ui_Visitor_I.hpp"

#include "../PoolOwnerUtils.h"

#include "I_WizardDeserial.hpp"

class Wizard_InternTrim  : public Graph_Node<Graph_App_I>, public PoolOwnerUtils, public I_WizardDeserial{
public:
	Wizard_InternTrim();
	virtual ~Wizard_InternTrim();

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

private:

    UI_Visitor_I *myUiVisitor;
    //char name[] = "Intern Trim";
    uint16_t dataCntr;

};

#endif /* SHARE_GRAPH_APP_WIZARDS_WIZARD_INTERNTRIM_H_ */
