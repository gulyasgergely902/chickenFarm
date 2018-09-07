#include <QCoreApplication>
#include "Farm.h"
#include "Utils.h"
#include <QDebug>

enum class Actions{
    ADD = 1,
    KILL,
    LISTEGGS,
    LISTINTERVALS,
    LAYEGG,
    KILLALL,
    EXIT
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Farm *farm = new Farm();
    Utils *utils = new Utils;

    while(true){
        utils->printMenu();
        switch(utils->getInput()){
            case static_cast<int>(Actions::ADD):
                farm->addChicken();
                break;
            case static_cast<int>(Actions::KILL):
                break;
            case static_cast<int>(Actions::LISTEGGS):
                farm->listEggs();
                break;
            case static_cast<int>(Actions::LISTINTERVALS):
                farm->listIntervals();
                break;
            case static_cast<int>(Actions::LAYEGG):
                qDebug() << "Chicken id: ";
                farm->layEgg(utils->getInput());
                break;
            case static_cast<int>(Actions::KILLALL):

                break;
            case static_cast<int>(Actions::EXIT):
                return 0;
        }
    }

    app.exec();
}