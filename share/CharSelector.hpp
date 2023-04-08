/*
 * CharSelector.hpp
 *
 *  Created on: 25.06.2022
 *      Author: Justus
 */

#ifndef SHARE_CHARSELECTOR_HPP_
#define SHARE_CHARSELECTOR_HPP_

class CharSelector {
public:
	CharSelector();
	virtual ~CharSelector();

	char TypeUp();
	char TypeDown();
	char NextChar();
	char PrvChar();
	char CurChar();

private:
	int curType, curChar;
	#define AMT_SPEC_CHARS 2
	char specialChars[AMT_SPEC_CHARS];
};

#endif /* SHARE_CHARSELECTOR_HPP_ */
