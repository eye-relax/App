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
                                              //SLOT
    //connect(WorkTimer,SIGNAL(timeout()),this,SLOT());
}

QTime Timer::elapsed(QTime first,QTime second)
{
    int sec1=first.hour()*3600+first.minute()*60+first.second();
    int sec2=second.hour()*3600+second.minute()*60+second.second();
    int r=sec1-sec2;
    return QTime(r/3600,(r%3600)/60,(r%3600)%60);
}



void Timer::startWorking()
{
    WorkTimer->start();
}

void Timer::setWorkingInterval(QTime arg)
{
    this->workingTime=arg;
    int milis=(workingTime.hour()*3600+workingTime.minute()*60+workingTime.second())*1000;
    WorkTimer->setInterval(milis);
}

void Timer::stopWorking()
{
    WorkTimer->stop();
}

QTime Timer::remaining()
{
    return QTime(0,0, WorkTimer->remainingTime()/1000);

}
