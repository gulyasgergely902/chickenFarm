//
// Created by dsindahouse on 9/3/18.
//

#ifndef CHICKENFARM_CHICKEN_H
#define CHICKENFARM_CHICKEN_H

#include <QRunnable>
#include <QThreadPool>
#include <QDebug>

class Chicken : public QRunnable{
public:
    void run() override;
};


#endif //CHICKENFARM_CHICKEN_H
