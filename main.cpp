#include <QCoreApplication>
#include "Farm.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    Farm farm();

    return app.exec();
}