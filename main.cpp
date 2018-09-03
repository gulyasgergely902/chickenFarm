#include <QCoreApplication>
#include "Farm.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Farm farm;
    farm.init();
}