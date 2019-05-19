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
    QTime remaining();
    static QTime elapsed(QTime first,QTime second);
private:
    QTime workingTime;
    void createWorkTimer();
    QTimer* WorkTimer;


signals:

public slots:

};

#endif // TIMER_H
