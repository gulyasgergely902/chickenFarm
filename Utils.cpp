//
// Created by dsindahouse on 9/3/18.
//

#include "Utils.h"

void Utils::printMenu() {
    qStdOut() << "CHICKEN FARM v1.0";
    qStdOut() << "1: Add chicken";
    qStdOut() << "2: Kill chicken";
    qStdOut() << "3: List chickens' eggs";
    qStdOut() << "4: List chickens' intervals";
    qStdOut() << "5: Lay an egg";
    qStdOut() << "6: Kill all chickens";
    qStdOut() << "7: Quit";
}

QTextStream &Utils::qStdOut() {
    static QTextStream ts(stdout);

    return ts;
}
