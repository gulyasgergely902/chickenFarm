#include "Farm.h"

Farm::Farm() {
    srand (static_cast <unsigned> (time(0)));
}

Farm::~Farm() {

}

void Farm::addChicken() {
    float X = 11.5;
    float randomInterval = (static_cast <float> (rand()) / (RAND_MAX/X)) + 1;

	auto * chicken = new Chicken(randomInterval, numberOfChicken);
	auto * thread = new QThread;

    QPair<QThread*, Chicken*> chickenData;
    chickenData.first = thread;
    chickenData.second = chicken;

    chickens.insert(numberOfChicken, chickenData);

    chicken->moveToThread(thread);

    connect(thread, &QThread::started, chicken, &Chicken::initChicken_slot);
	connect(thread, &QThread::finished, chicken, &Chicken::onChickenKill_slot);

    thread->start(QThread::NormalPriority);

    numberOfChicken++;
}

void Farm::killChicken(const int &id){
    chickens.value(id).first->quit();

    chickens.value(id).first->wait();

	QPair<QThread*, Chicken*> chickenData = chickens.take(id);

    delete chickenData.first;
    delete chickenData.second;
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

void Farm::killAll() {
	for(auto chicken : chickens.keys()){
		killChicken(chicken);
	}
}