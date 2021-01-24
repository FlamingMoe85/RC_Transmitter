

#include "Strct_Compo_Node.h"
#include "Strct_CalcFactory.h"

static uint16_t serializeCntr = 0;

static UI_Visitor_I* statUiVisPtr;
static Strct_CalcFactory compoNodeCalcFac;

Strct_Compo_Node::Strct_Compo_Node()
{

    this->FillNameArray(GetNameArr(), "Node" , (uint16_t)4);
  //  AddToPoolLstEnd(this);
    serFlag = 0;
    serPos = 0;
    SetType(COMPO_TYP_OPEN);
}

void Strct_Compo_Node::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
    statUiVisPtr = UiVisitor;
}

UI_Visitor_I* Strct_Compo_Node::GetVisitor()
{
	return myUiVisitor;
}

void Strct_Compo_Node::Show()
{

	statUiVisPtr->DispShowCall(this);
}


void Strct_Compo_Node::Run(float* val, uint32_t itteration)
{
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->Run(val,itteration);
    }
}

void Strct_Compo_Node::NullSerCntr()
{
    serFlag = 0;
    serializeCntr = 0;
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->NullSerCntr();
    }
}

void Strct_Compo_Node::AddCompAtEnd()
{
	Graph_App_I* tmpNamingPtr;
	tmpNamingPtr = new Strct_Compo_Node();
	this->AddToPoolLstEnd((Strct_Compo_Node*)tmpNamingPtr);
	GetChildList()->AddEnd(tmpNamingPtr);
	FillNameArray(tmpNamingPtr->GetNameArr() , "Composition", 11);
	Show();
}

void Strct_Compo_Node::ClearSerFlag()
{
	serFlag = 0;
}

void Strct_Compo_Node::Serialize(SerializeDest_I* SerDest)
{
	/*
	 * 	SerDest->SaveUint16(SLOT_TYP);
	SerDest->SaveName(this->GetNameArr());
    SerDest->SaveUint16(GetChildList()->Count());
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        //GetChildList()->At(i)->Serialize(SerDest);
    }
	*/
	//SerDest->SaveUint16(NODE);

    if(serFlag == 0)
    {
        serFlag = 1;
        serPos = serializeCntr;

        SerDest->SaveUint16(COMPO_TYP_OPEN);

        //SerDest->SaveUint16(serializeCntr++);
        serializeCntr++;
        SerDest->SaveName(GetNameArr());
        SerDest->SaveUint16(GetChildList()->Count());
        /**/for(uint16_t i=0; i<GetChildList()->Count(); i++)
        {
            GetChildList()->At(i)->Serialize(SerDest);
        }
    }
    else
    {
    	SerDest->SaveUint16(COMPO_TYP_STORED);
    	SerDest->SaveUint16(serPos);
    }

}

void Strct_Compo_Node::Deserialize(SerializeDest_I* SerDest)
{
    Graph_App_I* tmpModule;

    uint16_t amtChlds;
    uint16_t compoType, poolPos;

    /* Already done on previous level

    type = SerDest->GetUint16();
    serFlag = SerDest->GetUint16();
    serPos = SerDest->GetUint16();
    */
    SerDest->GetName(this->GetNameArr());
    amtChlds = SerDest->GetUint16();

    for(uint16_t i=0; i<amtChlds; i++)
    {
        /*
         * THIS is previous level
         */
    	compoType = SerDest->GetUint16();
        if(compoType == COMPO_TYP_OPEN)
        {
        	GetChildList()->AddEnd(new Strct_Compo_Node());
        	this->AddToPoolLstEnd((Strct_Compo_Node*)GetChildList()->At(GetChildList()->Count()-1));
			GetChildList()->At(GetChildList()->Count()-1)->Deserialize(SerDest);
        }
        else if(compoType == COMPO_TYP_STORED)
        {
        	poolPos = SerDest->GetUint16();
        	GetChildList()->AddEnd(this->GetPoolLst()->At(poolPos));
        }
        else
        {
        	tmpModule = compoNodeCalcFac.GetModuleByType(compoType);
        	tmpModule->Deserialize(SerDest);
        	GetChildList()->AddEnd(tmpModule);
        }
    }
}
