#include "Strct_Chnl_Node.h"
#include "Strct_MultSw_Node.h"

Strct_Chnl_Node::Strct_Chnl_Node()
{
    this->FillNameArray(GetNameArr(), "Channel" , (uint16_t)7);
	multSwCnt = 0;
    SetType(CHANNEL_TYP);
}

void Strct_Chnl_Node::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_Chnl_Node::GetVisitor()
{
	return myUiVisitor;
}

void Strct_Chnl_Node::Show()
{
	myUiVisitor->DispShowCall(this);
}

void Strct_Chnl_Node::Run(float* val, uint32_t itteration)
{
	if(GetChildList()->Count() > 1)
	{
		if(multSwCnt >= GetChildList()->Count())
		{
			multSwCnt = 0;
			*val = RESET_MULTI_SW;
		}
		else
		{
			GetChildList()->At(multSwCnt++)->Run(val,itteration);
		}
	}
	else
	{
		if(GetChildList()->Count() > 0)
		{
		        GetChildList()->At(0)->Run(val,itteration);
		        multSwCnt = 0;
		}
	}

}

void Strct_Chnl_Node::AddSltAtEnd()
{
	Graph_App_I* tmpNamingPtr;
	tmpNamingPtr = new Strct_MultSw_Node();
	GetChildList()->AddEnd(tmpNamingPtr);
	FillNameArray(tmpNamingPtr->GetNameArr() , "Slot", 4);
	Show();
}

void Strct_Chnl_Node::NullSerCntr()
{
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->NullSerCntr();
    }
}

void Strct_Chnl_Node::Serialize(SerializeDest_I* SerDest)
{
    SerDest->SaveUint16(GetChildList()->Count());
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->Serialize(SerDest);
    }
}

void Strct_Chnl_Node::Deserialize(SerializeDest_I* SerDest)
{
	uint16_t amtChlds;
	amtChlds = SerDest->GetUint16();
	for(uint16_t i=0; i<amtChlds; i++)
	{
		GetChildList()->AddEnd(new Strct_MultSw_Node());
		GetChildList()->At(GetChildList()->Count()-1)->Deserialize(SerDest);
	}
}
