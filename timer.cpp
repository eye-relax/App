#include "timer.h"

Timer::Timer(QObject *parent) : QObject(parent)
{
    createWorkTimer();
}

void Timer::createWorkTimer()
{
    WorkTimer=new QTimer(this);
    setWorkingInterval(QTime(0,0));
    WorkTimer->setTimerType(Qt::VeryCoarseTimer);
    connect(WorkTimer,SIGNAL(timeout()),this,SLOT(test()));
}



void Timer::startWorking()
{
    WorkTimer->start();
}


//remake so that it can take second parameter named "interval"(maybe a string?)

//i don't know how yet
void Timer::setWorkingInterval(QTime arg=QTime(0,0))
{
    int milis=(arg.hour()*3600+arg.minute()*60+arg.second())*1000;
    WorkTimer->setInterval(milis);
}

void Timer::stopWorking()
{
    WorkTimer->stop();
}

QTime Timer::remainingTime()
{
    QTime remaining(0,0, WorkTimer->remainingTime()/1000);
    return remaining;

}
