#pragma once

#include <QThread>
#include <QDebug>
#include <QTimer>

class Chicken : public QObject {
Q_OBJECT

public:
	Chicken(float _eggInt, int _chickenId);
	~Chicken();
	int getEggCount();
	float getInterval();
	int getId();

public slots:
	void layEgg_slot();
	void initChicken_slot();

private:
	float eggInterval;
	int eggCount = 0;
	int chickenId;
	QTimer *timer;

signals:
	void layEgg_signal(const int &dataToEmit);
};
