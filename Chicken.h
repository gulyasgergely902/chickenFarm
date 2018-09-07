#ifndef CHICKENFARM_CHICKEN_H
#define CHICKENFARM_CHICKEN_H

#include <QThread>
#include <QDebug>
#include <QTimer>

class Chicken : public QObject{
public:
    Chicken(float _eggInt, int _chickenId);
    ~Chicken();
    int getEggCount();
    float getInterval();
public slots:
    void layEgg_slot();
    void onChickenKill_slot();
    void initChicken_slot();
private:
    float eggInterval;
    int eggCount;
    int chickenId;
    QTimer *timer;
signals:
    void layEgg_signal(const int &dataToEmit);
};


#endif //CHICKENFARM_CHICKEN_H
