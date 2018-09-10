#include "Farm.h"

Farm::Farm() {
    srand (static_cast <unsigned> (time(0)));
}

Farm::~Farm() {

}

void Farm::addChicken() {
    float X = 11.5;
    float randomInterval = (static_cast <float> (rand()) / (RAND_MAX/X)) + 1;

    Chicken* chicken = new Chicken(randomInterval, numberOfChicken);
    QThread* thread = new QThread;

    QPair<QThread*, Chicken*> chickenData;
    chickenData.first = thread;
    chickenData.second = chicken;

    chickens.insert(numberOfChicken, chickenData);

    chickens.value(numberOfChicken).second->moveToThread(chickens.value(numberOfChicken).first);

    connect(chickens.value(numberOfChicken).first, &QThread::finished, chickens.value(numberOfChicken).second, &Chicken::onChickenKill_slot);
    connect(chickens.value(numberOfChicken).first, &QThread::started, chickens.value(numberOfChicken).second, &Chicken::initChicken_slot);

    chickens.value(numberOfChicken).first->start(QThread::NormalPriority);

    numberOfChicken++;

    for(auto it = chickens.begin(); it != chickens.end(); ++it){
        qDebug() << it.value().first << " is running: " << it.value().first->isRunning() << ", is finished: " << it.value().first->isFinished();
    }
}

void Farm::killChicken(const int &id){
    chickens.take(id).first->quit();
    qDebug() << "[killChicken]: chicken " << id << "'s thread is quitting";

    chickens.take(id).first->wait();
    qDebug() << "[killChicken]: chicken " << id << "'s thread is waiting";

    delete chickens.take(id).second;
    qDebug() << "[killChicken]: chicken " << id << " is deleted";
}

void Farm::listEggs() {
    for(auto it = chickens.begin(); it != chickens.end(); ++it){
        qDebug() << "Chicken " << it.key() << " has " << it.value().second->getEggCount() << " eggs already!";
    }
}

void Farm::listIntervals() {
    for(auto it = chickens.begin(); it != chickens.end(); ++it){
        qDebug() << "Chicken " << it.key() << " has " << it.value().second->getInterval() << " seconds between eggs!";
    }
}

void Farm::layEgg(const int &id) {
    for(auto it = chickens.begin(); it != chickens.end(); ++it){
        if(it.key() == id){
            it.value().second->layEgg_slot();
        }
    }
}

/*void Farm::emitHandler_slot(const int &incomingEmit) {
    qDebug() << incomingEmit;
}*/
