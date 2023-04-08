/*
 * Z_MusicControl.cpp
 *
 *  Created on: 09.02.2022
 *      Author: Justus
 */

#include "Z_MusicControl.h"
#include "inc/hw_memmap.h"
#include "driverlib/uart.h"

extern uint32_t digInArrBits;

Z_MusicControl::Z_MusicControl() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Music" , (uint16_t)5);
	play = 0;
	pause = 0;
	fw = 0;
	bw = 0;
	playOld = 0;
	pauseOld = 0;
	fwOld = 0;
	bwOld = 0;
	playNew = 0;
	pauseNew = 0;
	fwNew = 0;
	bwNew = 0;
}

Z_MusicControl::~Z_MusicControl() {
	// TODO Auto-generated destructor stub
}

void Z_MusicControl::Show(UI_Visitor_I *UiVisitor)
{
    UiVisitor->DispShowCall(this);
}

void Z_MusicControl::Run()
{
	uint16_t actPos, neutChnl, neutPos;
	uint32_t digBitsCopy = digInArrBits;

	if(digBitsCopy & (1 << (play-1))) playNew = 1; else playNew = 0;
	if(digBitsCopy & (1 << (pause-1))) pauseNew = 1; else pauseNew = 0;
	if(digBitsCopy & (1 << (fw-1))) fwNew = 1; else fwNew = 0;
	if(digBitsCopy & (1 << (bw-1))) bwNew = 1; else bwNew = 0;
	if(digBitsCopy & (1 << (vu-1))) vuNew = 1; else vuNew = 0;
	if(digBitsCopy & (1 << (vd-1))) vdNew = 1; else vdNew = 0;

	if((playNew == 1) && (playOld == 0)){UARTCharPut(UART7_BASE, 'p');UARTCharPut(UART7_BASE, 10);}
	else if((pauseNew == 1) && (pauseOld == 0)){UARTCharPut(UART7_BASE, 's'); UARTCharPut(UART7_BASE, 10);}
	else if((fwNew == 1) && (fwOld == 0)){UARTCharPut(UART7_BASE, 'f'); UARTCharPut(UART7_BASE, 10);}
	else if((bwNew == 1) && (bwOld == 0)){ UARTCharPut(UART7_BASE, 'b');UARTCharPut(UART7_BASE, 10);}
	else if((vuNew == 1) && (vuOld == 0)){UARTCharPut(UART7_BASE, 'V'); UARTCharPut(UART7_BASE, 10);}
	else if((vdNew == 1) && (vdOld == 0)){ UARTCharPut(UART7_BASE, 'v');UARTCharPut(UART7_BASE, 10);}

	playOld = playNew;
	pauseOld = pauseNew;
	fwOld = fwNew;
	bwOld = bwNew;
	vuOld = vuNew;
	vdOld = vdNew;
}

void Z_MusicControl::CatchUnderflow(uint16_t* dest, int16_t src, unsigned int mode)
{
	if(mode == SET)
	{
		if(src >= 0)*dest = src;
		else *dest = 0;
	}
	else if(mode == ADD)
	{
		if(src < 0)
		{
			src = src * -1;
			if(*dest >= src) *dest -= src;
			else *dest = 0;
		}
		else
		{
			*dest += src;
		}
	}
}

unsigned Z_MusicControl::AddSgndToVup(int16_t val, unsigned int mode)
{
	CatchUnderflow(&vu, val, mode);
	return vu;

}
unsigned Z_MusicControl::AddSgndToVdown(int16_t val, unsigned int mode)
{
	CatchUnderflow(&vd, val, mode);
	return vd;
}

unsigned int Z_MusicControl::AddSgndToPlay(int16_t val, unsigned int mode)
{
	CatchUnderflow(&play, val, mode);
	return play;
}
unsigned int Z_MusicControl::AddSgndToPause(int16_t val, unsigned int mode)
{
	CatchUnderflow(&pause, val, mode);
	return pause;
}
unsigned int Z_MusicControl::AddSgndToFw(int16_t val, unsigned int mode)
{
	CatchUnderflow(&fw, val, mode);
	return fw;
}
unsigned int Z_MusicControl::AddSgndToBw(int16_t val, unsigned int mode)
{
	CatchUnderflow(&bw, val, mode);
	return bw;
}
