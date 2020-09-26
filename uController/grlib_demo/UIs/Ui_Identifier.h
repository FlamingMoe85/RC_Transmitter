/*
 * Ui_Identifier.h
 *
 *  Created on: 25.09.2018
 *      Author: Justus
 */

#ifndef UIS_UI_IDENTIFIER_H_
#define UIS_UI_IDENTIFIER_H_

#include "Ui_Identifier_I.hpp"

class Ui_Identifier : public Ui_Identifier_I {
public:
	Ui_Identifier();
	virtual ~Ui_Identifier();

	virtual uint16_t GetStackPos();
	virtual uint16_t GetActUi();
	virtual void SetActUi(uint16_t acUi);

private:

	uint16_t myStackPos;

};

#endif /* UIS_UI_IDENTIFIER_H_ */
