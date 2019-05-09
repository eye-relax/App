#include "timer.h"

Timer::Timer(QObject *parent) : QObject(parent)
{
    createWorkTimer();
}

void Timer::createWorkTimer()
{
    WorkTimer=new QTimer(this);
    setWorkingInterval(WorkTimer);
    WorkTimer->setTimerType(Qt::VeryCoarseTimer);
    connect(WorkTimer,SIGNAL(timeout()),this,SLOT(test()));
}



void Timer::startWorking()
{
    WorkTimer->start();
}


//remake so that it can take second parameter named "interval"(maybe a string?)

//i don't know how yet
void Timer::setWorkingInterval(QTimer* timer)
{
    timer->setInterval(1000);
}

void Timer::stopWorking()
{
    WorkTimer->stop();
}
