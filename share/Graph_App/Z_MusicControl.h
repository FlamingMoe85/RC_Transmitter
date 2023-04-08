/*
 * Z_MusicControl.h
 *
 *  Created on: 09.02.2022
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_Z_MUSICCONTROL_H_
#define SHARE_GRAPH_APP_Z_MUSICCONTROL_H_

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

#define SET	0
#define ADD	1

class Z_MusicControl : public Graph_Leaf<Graph_App_I> {
public:
	Z_MusicControl();
	virtual ~Z_MusicControl();

		virtual void Run(float* val, uint32_t itteration){ };
		void Run();
	    virtual void Show(UI_Visitor_I* UiVisitor);
	    virtual UI_Visitor_I* GetVisitor(){ };
	    virtual void Serialize(SerializeDest_I* SerDest){ };
	    virtual void Deserialize(SerializeDest_I* SerDest){ };
	    virtual void NullSerCntr(){ };

	    unsigned int AddSgndToPlay(int16_t val, unsigned int mode);
	    unsigned int AddSgndToPause(int16_t val, unsigned int mode);
	    unsigned int AddSgndToFw(int16_t val, unsigned int mode);
	    unsigned int AddSgndToBw(int16_t val, unsigned int mode);
	    unsigned int AddSgndToVup(int16_t val, unsigned int mode);
	    unsigned int AddSgndToVdown(int16_t val, unsigned int mode);

private:
	    uint16_t play, pause, fw, bw,vu, vd,
				playOld, pauseOld, fwOld, bwOld,vuOld, vdOld,
				playNew, pauseNew, fwNew, bwNew,vuNew, vdNew;

	    void CatchUnderflow(uint16_t* dest, int16_t src, unsigned int mode);
};

#endif /* SHARE_GRAPH_APP_Z_MUSICCONTROL_H_ */
