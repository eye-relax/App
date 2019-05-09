#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);
    void startWorking();
    void setWorkingInterval(QTimer* timer);
    void stopWorking();
private:
    void createWorkTimer();
    QTimer* WorkTimer;
signals:

public slots:
    void test()
    {
        qDebug() << "update";
    }
};

#endif // TIMER_H
