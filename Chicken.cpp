//
// Created by dsindahouse on 9/3/18.
//

#include "Chicken.h"

void Chicken::run() {
    qDebug() << "Thread is running: " << QThread::currentThread();
}
