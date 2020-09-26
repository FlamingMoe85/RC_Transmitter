#ifndef UTILS_QT_H
#define UTILS_QT_H

#include <QObject>
#include <QWidget>
#include <QString>

class Utils_Qt
{
public:
    Utils_Qt();

    void CharrArrToQtring(char* nameArr, QString* name);
};

#endif // UTILS_QT_H
