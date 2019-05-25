#ifndef KOLO_H
#define KOLO_H

#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QLabel>
#include <string.h>
#include <QKeyEvent>
#include <QtMultimedia/QMediaPlayer>
#include <QSound>
#include <map>
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
    long czaszmiany=500;
    int cwiczenie=1;
    std::map <int,std::string> opisy;
private:
    QGraphicsView *widok;
    QGraphicsScene *scena;
    QGraphicsPixmapItem *kolo;
    QTimer timer;
    QTimer odzmiany;
    QPixmap *x;
    QPixmap *x2;
    QLabel *info;
    QLabel *ocwiczeniu;
    QPalette* pal;
    QMediaPlayer *player;
    QPushButton *poprz;
    QPushButton *nast;
    QPushButton *zacz;
    QFont *font;



private slots:
    void klepsydra();
    void okrag();
    void mruganie();
    void zmiana();
    void goradol();
    void plus();
    void minus();
    void zaczynamy();
    void zatrzymanie();
};

#endif // KOLO_H
