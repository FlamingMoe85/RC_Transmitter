/*
 * CharSelector.cpp
 *
 *  Created on: 25.06.2022
 *      Author: Justus
 */

#include "CharSelector.hpp"

CharSelector::CharSelector() {
	// TODO Auto-generated constructor stub
	curType = 0;
	curChar = 'A';
	specialChars[0] = ' ';
	specialChars[1] = '_';

}


char CharSelector::TypeUp()
{

	switch(curType)
	{
		case 0:
			curChar = 'a';
			curType++;
			break;
		case 1:
			curChar = '0';
			curType++;
			break;
		case 2:
			curChar = 0;
			curType++;
			break;
		case 3:
			curChar = 'A';
			curType = 0;
			break;
	}

	return CurChar();

}
char CharSelector::TypeDown()
{
	switch(curType)
	{
		case 0:
			curChar = 0;
			curType = 3;
			break;
		case 1:
			curChar = 'A';
			curType--;
			break;
		case 2:
			curChar = 'a';
			curType--;
			break;
		case 3:
			curChar = '0';
			curType--;
			break;
	}

	return CurChar();
}
char CharSelector::NextChar()
{
	switch(curType)
	{
		case 0:
			if(curChar < 'Z')curChar++;
			else curChar = 'A';
			break;
		case 1:
			if(curChar < 'z')curChar++;
			else curChar = 'a';
			break;
		case 2:
			if(curChar < '9')curChar++;
			else curChar = '0';
			break;
		case 3:
			if(curChar < AMT_SPEC_CHARS)curChar++;
			else curChar = 0;
			break;
	}

	return CurChar();

}
char CharSelector::PrvChar()
{

	switch(curType)
	{
		case 0:
			if(curChar > 'A')curChar--;
			else curChar = 'Z';
			break;
		case 1:
			if(curChar > 'a')curChar--;
			else curChar = 'z';
			break;
		case 2:
			if(curChar > '0')curChar--;
			else curChar = '9';
			break;
		case 3:
			if(curChar > 0)curChar--;
			else curChar = AMT_SPEC_CHARS;
			break;
	}

	return CurChar();
}
char CharSelector::CurChar()
{
	switch(curType)
	{
		case 0:
			return curChar;
		case 1:
			return curChar;
		case 2:
			return curChar;
		case 3:
			return specialChars[curChar];
	}
}

CharSelector::~CharSelector() {
	// TODO Auto-generated destructor stub
}

