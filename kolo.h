#ifndef KOLO_H
#define KOLO_H


#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsPixmapItem>
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
    int krok=1;
    long czas=10;
private:
    QGraphicsView *widok;
    QGraphicsScene *scena;
    QGraphicsPixmapItem *kolo;
    QTimer timer;
    QPixmap *x;
    QPixmap *x2;
    QLabel *info;

    void zaczynamy(int i);



private slots:
    void moment();
    void klepsydra();
    void okrag();
    void zmiana();
};

#endif // KOLO_H
