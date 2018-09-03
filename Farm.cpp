#include "Farm.h"

Utils utils;

void Farm::init() {
    utils.printMenu();
    switch (utils.getInput()){
        case 1:
            addChicken();
        case 2:
            qDebug() << "KILL CHICKEN";
        default:
            break;
    }
}

void Farm::addChicken() {
    Chicken *chicken = new Chicken();
    QThreadPool::globalInstance()->start(chicken);
}
