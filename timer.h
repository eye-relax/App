#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QTime>
class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);
    void startWorking();
    void setWorkingInterval(QTime time);
    void stopWorking();
    QTime remainingTime();
private:
    void createWorkTimer();
    QTimer* WorkTimer;
signals:

public slots:
    void test()
    {
        qDebug() << "update";
        qDebug()<<this->remainingTime().toString("hh:mm:ss.zzz");
        qDebug()<<this->remainingTime().toString("hh:mm:ss.zzz");
        qDebug()<<this->remainingTime().toString("hh:mm:ss.zzz");
        qDebug()<<this->remainingTime().toString("hh:mm:ss.zzz");
    }
};

#endif // TIMER_H
