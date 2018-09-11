#pragma once

#include <QMap>
#include <QThread>
#include <QPair>

#include "Chicken.h"

class Farm : public QObject {
public:
	Farm();
	void addChicken();
	void killChicken(const int &id);
	void listEggs();
	void listIntervals();
	void layEgg(const int &id);
	void killAll();

private:
	QMap<int, QPair<QThread *, Chicken *>> chickens;
	int numberOfChicken = 0;
	float RNG_MAX = 11.5;
};
