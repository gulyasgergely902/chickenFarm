#include "Farm.h"

Farm::Farm() {
    srand (static_cast <unsigned> (time(0)));
}

Farm::~Farm() {

}

void Farm::addChicken() {
    float X = 11.5;
    float randomInterval = (static_cast <float> (rand()) / (RAND_MAX/X)) + 1;

    qDebug() << "creating chicken";
    qDebug() << "randint:" << randomInterval;
    qDebug() << "numofc:" << numberOfChicken;
    Chicken* chicken = new Chicken(randomInterval, numberOfChicken);

    qDebug() << "creating thread";
    QThread* thread = new QThread;

    QPair<QThread*, Chicken*> chickenData;
    chickenData.first = thread;
    chickenData.second = chicken;
    qDebug() << "creating qpair";

    chickens.insert(numberOfChicken, chickenData);
    qDebug() << "inserting into chickens";

    chickens.value(numberOfChicken).second->moveToThread(chickens.value(numberOfChicken).first);
    qDebug() << "moving chicken onto thread";

    connect(chickens.value(numberOfChicken).first, &QThread::finished, chickens.value(numberOfChicken).second, &Chicken::onChickenKill_slot);
    connect(chickens.value(numberOfChicken).first, &QThread::started, chickens.value(numberOfChicken).second, &Chicken::initChicken_slot);
    qDebug() << "connecting";

    chickens.value(numberOfChicken).first->start(QThread::NormalPriority);
    qDebug() << "starting threads";

    numberOfChicken++;
    qDebug() << "chickens++";

    for(auto it = chickens.begin(); it != chickens.end(); ++it){
        qDebug() << it.value().first << " is running: " << it.value().first->isRunning() << ", is finished: " << it.value().first->isFinished();
    }
    qDebug() << "debug info";
}

void Farm::killChicken(const int &id){
    qDebug() << "chickens @ id: " << id << ". entry is scheduled for deletion!";

    chickens.take(id).first->quit();
    qDebug() << "chickens @ id: thread is quitting";

    chickens.take(id).first->wait();
    qDebug() << "chickens @ id: thread is waiting";

    delete chickens.take(id).second;
    qDebug() << "chickens @ id: deleting entry";
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
