#pragma once

#ifndef CHICKENFARM_UTILS_H
#define CHICKENFARM_UTILS_H


#include <QtCore/QTextStream>

class Utils {
public:
    void printMenu();
    QTextStream &qStdOut();
};


#endif //CHICKENFARM_UTILS_H
