#include "Utils.h"

void Utils::printMenu() {
    qDebug() << "CHICKEN FARM v1.0";
    qDebug() << "1: Add chicken";
    qDebug() << "2: Kill chicken";
    qDebug() << "3: List chickens' eggs";
    qDebug() << "4: List chickens' intervals";
    qDebug() << "5: Lay an egg";
    qDebug() << "6: Kill all chickens";
    qDebug() << "7: Quit";
}

int Utils::getInput() {
    QTextStream qTextStream(stdin);
    QString input = qTextStream.readLine(1);
    return input.toInt();
}
