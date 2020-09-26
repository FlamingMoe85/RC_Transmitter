#include "Strct_ChnlMngr_Node.h"

Strct_ChnlMngr_Node::Strct_ChnlMngr_Node()
{
    this->FillNameArray(GetNameArr(), "Chanell Manager" , (uint16_t)15);
    SetType(CHNMNGR_TYP);
}

void Strct_ChnlMngr_Node::Run(float* val, uint32_t itteration)
{
	for(uint16_t i=0; i<7; i++)
	{
		val[i] = 0,0;
	}

    for(uint16_t i=0; i<7; i++)
    {
        GetChildList()->At(i)->Run(&(val[i]),itteration);
    }
}

void Strct_ChnlMngr_Node::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_ChnlMngr_Node::GetVisitor()
{
	return myUiVisitor;
}

void Strct_ChnlMngr_Node::Run()
{
	Run(&(resultArr[0]), itteration);
    itteration++;
}

int32_t Strct_ChnlMngr_Node::GetChnlVal(uint16_t chnl)
{
    if(chnl >= 7) return 0;
    return resultArr[chnl];
}

void Strct_ChnlMngr_Node::NullSerCntr()
{
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->NullSerCntr();
    }
}

void Strct_ChnlMngr_Node::Serialize(SerializeDest_I* SerDest)
{
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->Serialize(SerDest);
    }
}

void Strct_ChnlMngr_Node::Deserialize(SerializeDest_I* SerDest)
{
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->Deserialize(SerDest);
    }
}
