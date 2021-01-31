/*
 * I_WizardDeserial.hpp
 *
 *  Created on: 27.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_WIZARDS_I_WIZARDDESERIAL_HPP_
#define SHARE_GRAPH_APP_WIZARDS_I_WIZARDDESERIAL_HPP_

#include "../../std/SerializeDest_I.hpp"
#include "../../globaldefinesshare.h"

class I_WizardDeserial : public SerializeDest_I{
public:


	virtual void SaveChar(char arg){ };
	virtual void SaveName(char* nameArr){ };
	virtual void SaveUint16(uint16_t arg){ };
	virtual void SaveInt16(int16_t arg){ };

	virtual char GetChar(){ };
	//virtual void GetName(char* nameArr);
	//virtual uint16_t GetUint16();
	//virtual int16_t GetInt16();

	virtual void NewModel(){ };
	virtual uint32_t CreateLastModAdr(uint32_t firstMod){ };
	virtual void InsertModEnd(uint32_t target){ };
	virtual void DeInsertModAt(uint32_t targAdr){ };
	virtual uint16_t GetAmtOfModels(){ };
	virtual void GetNameOfModel(char* namArr, uint16_t modNmbr){ };
	virtual void FinalSaveStrobe(){ };
	virtual uint16_t GetSelctdMod(){ };
	virtual void DelSelctdMod(uint16_t delMod){ };
	virtual void PrepForOverwrite(uint32_t modNmbr){ };
	virtual void SetCurModByNmbr(uint32_t modNmbr){ };
	virtual uint32_t GetCurModNmbr(){ };

	virtual uint16_t GetAmtUsablelocks(){ };
	virtual uint16_t GetAmtUsedBlock(){ };

};

#endif /* SHARE_GRAPH_APP_WIZARDS_I_WIZARDDESERIAL_HPP_ */
