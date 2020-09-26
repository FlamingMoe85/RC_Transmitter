#include "Utils_Qt.h"

Utils_Qt::Utils_Qt()
{

}

void Utils_Qt::CharrArrToQtring(char* nameArr, QString* name)
{
   char letter;
   unsigned int j;
   name->clear();
   j = 0;
   letter = nameArr[0];
   while(letter != '\0')
   {
       name->append(letter);
       j++;
       letter = nameArr[j];
   }
}
