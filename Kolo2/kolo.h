#ifndef KOLO_H
#define KOLO_H


#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QPen>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QLabel>
#include <string>
#include <QKeyEvent>

class Kolo : public QWidget
{
    Q_OBJECT

public:
    Kolo();
    ~Kolo();
    int wybor=0;
    void keyPressEvent(QKeyEvent *Event);

private:
    QGraphicsView *widok;
    QGraphicsScene *scena;
    QGraphicsPixmapItem *mObraz;
    QGraphicsEllipseItem *kolo;
    QTimer timer;
    void zaczynamy();
    long czas;

private slots:
    void moment();
};

#endif // KOLO_H
