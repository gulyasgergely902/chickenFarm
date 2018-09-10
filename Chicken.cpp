#include "Chicken.h"

Chicken::Chicken(float _eggInt, int _chickenId) : eggInterval(_eggInt), chickenId(_chickenId) {
	eggCount = 0;
	qDebug() << "[Chicken " << chickenId << "]: Chicken has been created with interval: " << eggInterval;
}

Chicken::~Chicken() {
	timer->stop();
	delete timer;
}

void Chicken::initChicken_slot() {
	timer = new QTimer();
	timer->setInterval(eggInterval * 1000);
	QObject::connect(timer, &QTimer::timeout, this, &Chicken::layEgg_slot);
	timer->start();
}

void Chicken::layEgg_slot() {
	eggCount++;
	qDebug() << "[Chicken " << chickenId << "]: Your chicken with ID " << chickenId << " layed an egg. Total eggs: "
	         << eggCount;
}

int Chicken::getEggCount() {
	return eggCount;
}

float Chicken::getInterval() {
	return eggInterval;
}

int Chicken::getId() {
	return chickenId;
}

void Chicken::onChickenKill_slot() {
	timer->stop();
}
