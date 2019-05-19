#include "kolo.h"
#include <math.h>
#include <string.h>
#include <windows.h>
#include <QtMultimedia/QMediaPlayer>

#define rozX 50
#define rozY 50

int funk(int x)
{
    return (int)sqrt((325*325)-((x-325)*(x-325)))+325;
}
int funk2(int x)
{
    return (int)sqrt((325*325)-((x-325)*(x-325)))+325;
}

Kolo::Kolo()
{

    setGeometry(56,100,800,800);
    info=new QLabel(("Krok: "+ std::to_string(krok)+" Czas: "+ std::to_string(czas)).c_str(),this);
    info->setGeometry(0,0,500,20);
    scena = new QGraphicsScene(0, 0, 600, 600);
    scena->setBackgroundBrush(Qt::black);
    widok = new QGraphicsView(scena, this);
    widok->setGeometry(50, 50, 700, 700);
    x=new QPixmap("C:/Users/Patryk/Desktop/Cos/Kolo2/cos.png");
    x2=new QPixmap("C:/Users/Patryk/Desktop/Cos/Kolo2/cos2.png");  
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Patryk/Desktop/Cos/Kolo2/mf.wav"));
    player->setVolume(50);
    player->play();
    *x=x->scaled(50,50);
    *x2=x2->scaled(50,50);
    kolo = new QGraphicsPixmapItem(*x);
    scena->addItem(kolo);
    zaczynamy(1);
}

Kolo::~Kolo()
{

        delete widok;
        delete scena;
        delete info;
        delete x;
        delete x2;
}

void Kolo::keyPressEvent(QKeyEvent *Event)
{
    switch (Event->key()) {
    case Qt::Key_W:
    kolo->setY(kolo->y()-1);
        break;
    case Qt::Key_S:
    kolo->setY(kolo->y()+1);
        break;
    case Qt::Key_A:
    kolo->setX(kolo->x()-1);
        break;
    case Qt::Key_D:
    kolo->setX(kolo->x()+1);
        break;
    case Qt::Key_E:
        timer.stop();
        break;
    case Qt::Key_Q:
        timer.start(czas);
        break;
    case Qt::Key_Z:
        czas+=1;
        info->setText(("Krok: "+ std::to_string(krok)+" Czas: "+ std::to_string(czas)).c_str());
        timer.start(czas);
        break;
    case Qt::Key_X:
        if((czas-=1)<1)czas=1;
        info->setText(("Krok: "+ std::to_string(krok)+" Czas: "+ std::to_string(czas)).c_str());
        timer.start(czas);
        break;
    case Qt::Key_C:
        krok+=1;
        info->setText(("Krok: "+ std::to_string(krok)+" Czas: "+ std::to_string(czas)).c_str());
        break;
    case Qt::Key_V:
        if((krok-=1)<1)krok=1;
        info->setText(("Krok: "+ std::to_string(krok)+" Czas: "+ std::to_string(czas)).c_str());
        timer.start(czas);
        break;
    default:
        break;
    }
}
void Kolo::zaczynamy(int i)
{

    connect(&timer, SIGNAL(timeout()), this, SLOT(zmiana()));
    switch(i)
    {
    case 1://klepsydra
            kolo->setX(-rozX);
            kolo->setY(-rozY);
            connect(&timer, SIGNAL(timeout()), this, SLOT(klepsydra()));
    break;
    case 2://kolo
            kolo->setX(325);
            kolo->setY(0);
            connect(&timer, SIGNAL(timeout()), this, SLOT(okrag()));
    break;
    }
    timer.start(czas);
}
void Kolo::zmiana()
{
    static int i=0;
    if(i==0){kolo->setPixmap(*x2);++i;}
    else{kolo->setPixmap(*x);--i;}
}
void Kolo::moment()
{


    if(wybor<200/krok)
    {
    kolo->setX(kolo->x()+krok);
    kolo->setY(kolo->y()+krok);
    wybor++;
    }
    else if(wybor>=200/krok&&wybor<400/krok)
    {
    kolo->setX(kolo->x()+krok);
    kolo->setY(kolo->y()-krok);
    wybor++;
    }
    else if(wybor>=400/krok&&wybor<600/krok)
    {
    kolo->setX(kolo->x()-krok);
    kolo->setY(kolo->y()-krok);
    wybor++;
    }
    else if(wybor>=600/krok&&wybor<800/krok)
    {
    wybor++;
    kolo->setX(kolo->x()-krok);
    kolo->setY(kolo->y()+krok);
    }
    else
    {
        wybor=0;
    }
}

void Kolo::klepsydra()
{
    if(wybor<650/krok)
    {
    kolo->setY(kolo->y()+krok);
    wybor++;
    }
    else if(wybor>=650/krok&&wybor<1300/krok)
    {
    kolo->setX(kolo->x()+krok);
    kolo->setY(kolo->y()-krok);
    wybor++;
    }
    else if(wybor>=1300/krok&&wybor<1950/krok)
    {
    kolo->setY(kolo->y()+krok);
    wybor++;
    }
    else if(wybor>=1950/krok&&wybor<2600/krok)
    {
    wybor++;
    kolo->setX(kolo->x()-krok);
    kolo->setY(kolo->y()-krok);
    }
    else
    {
        wybor=0;
    }
}
void Kolo::okrag()
{
    if(wybor<360/krok)
    {
    kolo->setX(325+300.0*sin((wybor*krok)*0.0174532925199433)-rozX);
    kolo->setY(325+300.0*cos((wybor*krok)*0.0174532925199433)-rozY);
    wybor++;
    }
    else
    {
        kolo->setPixmap(*x);
        wybor=0;
    }
}
