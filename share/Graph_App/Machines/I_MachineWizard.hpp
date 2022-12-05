/*
 * I_MachineWizard.hpp
 *
 *  Created on: 27.01.2021
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_MACHINES_I_MACHINEWIZARD_HPP_
#define SHARE_GRAPH_APP_MACHINES_I_MACHINEWIZARD_HPP_

#include "../../std/SerializeDest_I.hpp"
#include "../../globaldefinesshare.h"

class I_Machine_Wizard : public SerializeDest_I{
public:


        virtual void SaveChar(char arg){(void)arg; }
        virtual void SaveName(char* nameArr){(void)nameArr; }
        virtual void SaveUint16(uint16_t arg){(void)arg; }
        virtual void SaveInt16(int16_t arg){(void)arg; }

        virtual char GetChar(){  return 0;}
        virtual void GetName(char* nameArr){(void)nameArr; }
	//virtual uint16_t GetUint16();
	//virtual int16_t GetInt16();

        virtual void NewModel(){ }
        virtual uint32_t CreateLastModAdr(uint32_t firstMod){(void)firstMod; return 0;}
        virtual void InsertModEnd(uint32_t target){(void)target; }
        virtual void DeInsertModAt(uint32_t targAdr){(void)targAdr; }
        virtual uint16_t GetAmtOfModels(){  return 0;}
        virtual void GetNameOfModel(char* namArr, uint16_t modNmbr){(void)namArr; (void)modNmbr; }
        virtual void FinalSaveStrobe(){ }
        virtual uint16_t GetSelctdMod(){  return 0;}
        virtual void DelSelctdMod(uint16_t delMod){(void)delMod; }
        virtual void PrepForOverwrite(uint32_t modNmbr){(void)modNmbr; }
        virtual void SetCurModByNmbr(uint32_t modNmbr){(void)modNmbr; }
        virtual uint32_t GetCurModNmbr(){  return 0;}

        virtual uint16_t GetAmtUsablelocks(){  return 0;}
        virtual uint16_t GetAmtUsedBlock(){  return 0;}

};

#endif /* SHARE_GRAPH_APP_MACHINES_I_MACHINEWIZARD_HPP_ */
