#pragma once

#ifndef CHICKENFARM_FARM_H
#define CHICKENFARM_FARM_H

#include "Chicken.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QMap>
#include <QThread>
#include <QPair>

class Farm: public QObject{
public:
    Farm();
    ~Farm();
    void addChicken();
    void killChicken(const int &id);
    void listEggs();
    void listIntervals();
    void layEgg(const int &id);
public slots:
    //void emitHandler_slot(const int &incomingEmit);
private:
    QMap<int, QPair<QThread*, Chicken*>> chickens;
    int numberOfChicken;
};


#endif //CHICKENFARM_FARM_H
