/*
 * UtilClass.h
 *
 *  Created on: 05.05.2019
 *      Author: Justus
 */

#ifndef UTILS_UTILCLASS_H_
#define UTILS_UTILCLASS_H_

#include "stdint.h"

class UtilClass {

private:
	static void RearangeCharArr(char* txtStrngIn, int16_t val, bool sgned, uint16_t presicion, char sepSign, char endSgn)
	{
		uint16_t existNumbers =0, i, minAmtOfFigs = 2, minAmtOfNmbrs = 1, lagOfNmbrs = 0, numbOvrFl = 0;

		while(txtStrngIn[existNumbers] != '\0') existNumbers++;

		minAmtOfFigs = 2;
		if(presicion > 0)
		{
			minAmtOfFigs = presicion +3;
		}

		minAmtOfNmbrs = presicion + 1;
		if(existNumbers < minAmtOfNmbrs)
		{
			lagOfNmbrs = minAmtOfNmbrs - existNumbers;
			//minAmtOfFigs += lagOfNmbrs;
		}
		else
		{
			numbOvrFl = existNumbers - minAmtOfNmbrs;
			minAmtOfFigs += numbOvrFl;
		}


		txtStrngIn[minAmtOfFigs] = '\0';
		txtStrngIn[minAmtOfFigs - 1] = endSgn;

		for(i=0; i<presicion; i++)
		{
			if((existNumbers - 1) >= i)
			{
				txtStrngIn[minAmtOfFigs - 2 - i] = txtStrngIn[existNumbers - 1 - i];
			}
			else
			{
				txtStrngIn[minAmtOfFigs - 2 - i] = '0';
			}
		}
		if(presicion > 0)txtStrngIn[minAmtOfFigs - 2 - i] = sepSign;
		if(lagOfNmbrs > 0)txtStrngIn[0] = '0';
	}

public:
	UtilClass();
	virtual ~UtilClass();

	//static uint16_t CatchWrap(uint16_t amt, uint16_t pos, int16_t deviation);
	//static void SgndIntToStrng(char* txtStrng, int16_t val);


	static void SgndIntToStrng(char* txtStrng, int16_t val)
	{

		uint16_t cycles = 0;
		uint32_t workVal;
		txtStrng[0] = '+';
		if(val < 0)
		{
			val = val *(-1);
			txtStrng[0] = '-';
		}
		workVal = val;


        if(workVal > 9999)cycles = 5;
        else if(workVal > 999){cycles = 4; workVal = workVal * 10;}
        else if(workVal > 99){cycles = 3; workVal = workVal * 100;}
        else if(workVal > 9){cycles = 2; workVal = workVal * 1000;}
        else if(workVal > 0){cycles = 1; workVal = workVal * 10000;}
        if(workVal == 0){txtStrng[0] = '0';}

		for(uint16_t i=0; i<cycles; i++)
		{
			if(workVal > 89999)		{txtStrng[i+1] = '9'; workVal = workVal - 90000;}
			else if(workVal > 79999){txtStrng[i+1] = '8'; workVal = workVal - 80000;}
			else if(workVal > 69999){txtStrng[i+1] = '7'; workVal = workVal - 70000;}
			else if(workVal > 59999){txtStrng[i+1] = '6'; workVal = workVal - 60000;}
			else if(workVal > 49999){txtStrng[i+1] = '5'; workVal = workVal - 50000;}
			else if(workVal > 39999){txtStrng[i+1] = '4'; workVal = workVal - 40000;}
			else if(workVal > 29999){txtStrng[i+1] = '3'; workVal = workVal - 30000;}
			else if(workVal > 19999){txtStrng[i+1] = '2'; workVal = workVal - 20000;}
			else if(workVal > 9999){txtStrng[i+1] = '1'; workVal = workVal - 10000;}
			else {txtStrng[i+1] = '0';}
			workVal = workVal * 10;
		}

		txtStrng[cycles+1] = '\0';


	}

	static void UnsgndIntToStrng(char* txtStrng, uint16_t val)
	{

		uint16_t cycles = 0;
		uint32_t workVal;
		workVal = val;


        if(workVal > 9999)cycles = 5;
        else if(workVal > 999){cycles = 4; workVal = workVal * 10;}
        else if(workVal > 99){cycles = 3; workVal = workVal * 100;}
        else if(workVal > 9){cycles = 2; workVal = workVal * 1000;}
        else if(workVal > 0){cycles = 1; workVal = workVal * 10000;}
        else cycles = 1;
        //if(workVal == 0){txtStrng[0] = '0';}

		for(uint16_t i=0; i<cycles; i++)
		{
			if(workVal > 89999)		{txtStrng[i] = '9'; workVal = workVal - 90000;}
			else if(workVal > 79999){txtStrng[i] = '8'; workVal = workVal - 80000;}
			else if(workVal > 69999){txtStrng[i] = '7'; workVal = workVal - 70000;}
			else if(workVal > 59999){txtStrng[i] = '6'; workVal = workVal - 60000;}
			else if(workVal > 49999){txtStrng[i] = '5'; workVal = workVal - 50000;}
			else if(workVal > 39999){txtStrng[i] = '4'; workVal = workVal - 40000;}
			else if(workVal > 29999){txtStrng[i] = '3'; workVal = workVal - 30000;}
			else if(workVal > 19999){txtStrng[i] = '2'; workVal = workVal - 20000;}
			else if(workVal > 9999){txtStrng[i] = '1'; workVal = workVal - 10000;}
			else {txtStrng[i] = '0';}
			workVal = workVal * 10;
		}

		txtStrng[cycles] = '\0';


	}

static void IntToPercStrng(char* txtStrngIn, int16_t val, bool sgned)
{
	IntToPercStrng(txtStrngIn, val, sgned, 1, '.', '%');
}

	static void IntToPercStrng(char* txtStrngIn, int16_t val, bool sgned, uint16_t presicion, char sepSign, char endSgn)
	{



		/* [1] ['\0'] [] []
		 * perc = 1
		 * [0] [.] [1] [%] ['\0']
		 *
		 */
		if(val == 0)sgned = false;
		if(sgned == true)
		{
			UtilClass::SgndIntToStrng(txtStrngIn, val);
			RearangeCharArr(&(txtStrngIn[1])  , val, sgned, presicion, sepSign, endSgn);
		}
		else
		{
			UtilClass::UnsgndIntToStrng(txtStrngIn, val);
			RearangeCharArr(&(txtStrngIn[0])  , val, sgned, presicion, sepSign, endSgn);
		}



	}

	static uint16_t CatchWrap(uint16_t amt, uint16_t pos, int16_t deviation)
	{
		if(deviation >= 0)
		{
			if((pos + deviation) >= amt) return ((pos + deviation)-amt);
			return (pos + deviation);
		}
		else
		{
			if((pos + deviation) < 0) return (amt + (pos + deviation));
			return (pos + deviation);

		}
	}
};

#endif /* UTILS_UTILCLASS_H_ */
