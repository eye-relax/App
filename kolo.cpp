#include "kolo.h"
#include <math.h>
#include <windows.h>


#define rozX 50
#define rozY 50



Kolo::Kolo()
{
    font=new QFont( "Arial", 15, QFont::Bold);
    opisy[1]="Mrugaj tak czesto jak jablko zmienia barwe.";
    opisy[2]="Poruszaj oczami góra/dół tak jak pokazuje jabłko.";
    opisy[3]="Poruszaj oczami na kształt klepsydry tak jak pokazuje jabłko.";
    opisy[4]="Poruszaj oczami dookoła tak jak pokazuje jabłko.";
    setGeometry(56,100,900,900);
    pal=new QPalette(palette());
    pal->setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(*pal);
    info=new QLabel(("Ćwiczenie: "+ std::to_string(cwiczenie)).c_str(),this);
    info->setStyleSheet("QLabel { color : blue; }");
    info->setGeometry(0,0,500,20);
    ocwiczeniu=new QLabel(opisy[1].c_str(),this);
    ocwiczeniu->setStyleSheet("QLabel { color : blue; }");
    ocwiczeniu->setFont(*font);
    ocwiczeniu->setGeometry(100,800,700,50);
    ocwiczeniu->setAlignment(Qt::AlignCenter);
    scena = new QGraphicsScene(0, 0, 600, 600);
    scena->setBackgroundBrush(QColor(32,32,32));
    widok = new QGraphicsView(scena, this);
    widok->setGeometry(100, 100, 700, 700);
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/img/pliki/why.wav"));
    player->setVolume(50);
    //player->play();
    x=new QPixmap(":/img/pliki/cos.png");
    x2=new QPixmap(":/img/pliki/cos2.png");
    *x=x->scaled(50,50);
    *x2=x2->scaled(50,50);
    kolo = new QGraphicsPixmapItem(*x);
    kolo->setX(275);
    kolo->setY(300);
    scena->addItem(kolo);
    poprz=new QPushButton("Poprzedni",this);
    poprz->setGeometry(QRect(QPoint(100, 40),QSize(200, 50)));
    nast=new QPushButton("Nastepny",this);
    nast->setGeometry(QRect(QPoint(600, 40),QSize(200, 50)));
    zacz=new QPushButton("Start",this);
    zacz->setGeometry(QRect(QPoint(350, 40),QSize(200, 50)));
    connect(nast, SIGNAL(clicked()), this, SLOT(plus()));
    connect(poprz, SIGNAL(clicked()), this, SLOT(minus()));
    connect(zacz, SIGNAL(clicked()), this, SLOT(zaczynamy()));
}

Kolo::~Kolo()
{

        delete widok;
        delete scena;
        delete x;
        delete x2;
        delete pal;
        delete player;
        delete info;
}
void Kolo::zaczynamy()
{
    wybor=0;
    qDebug()<<"hej";
    switch(cwiczenie)
    {
    case 1://mruganie
            kolo->setX(275);
            kolo->setY(300);
            czas=1000;
            krok=5;
            connect(&timer, SIGNAL(timeout()), this, SLOT(mruganie()));
            connect(&odzmiany, SIGNAL(timeout()), this, SLOT(zmiana()));
            timer.start(czas);
            odzmiany.start(czas);
    break;
    case 2://goradol;
            kolo->setX(275);
            kolo->setY(50);
            czas=10;
            krok=3;
            connect(&timer, SIGNAL(timeout()), this, SLOT(goradol()));
            timer.start(czas);
    break;
    case 3://klepsydra

            kolo->setX(25);
            kolo->setY(25);
            czas=10;
            krok=2;
            connect(&timer, SIGNAL(timeout()), this, SLOT(klepsydra()));
            timer.start(czas);
    break;
    case 4://kolo
            kolo->setX(325);
            kolo->setY(0);
            czas=10;
            krok=1;
            connect(&timer, SIGNAL(timeout()), this, SLOT(okrag()));
            timer.start(czas);
    break;
    }


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

void Kolo::zmiana()
{
    static int i=0;
    if(i==0){kolo->setPixmap(*x2);++i;}
    else{kolo->setPixmap(*x);--i;}
}

void Kolo::mruganie()
{
 player->play();
}


void Kolo::klepsydra()
{
    if(wybor<500/krok)
    {
    kolo->setY(kolo->y()+krok);
    wybor++;
    }
    else if(wybor>=500/krok&&wybor<1000/krok)
    {
    kolo->setX(kolo->x()+krok);
    kolo->setY(kolo->y()-krok);
    wybor++;
    }
    else if(wybor>=1000/krok&&wybor<1500/krok)
    {
    kolo->setY(kolo->y()+krok);
    wybor++;
    }
    else if(wybor>=1500/krok&&wybor<2000/krok)
    {
    wybor++;
    kolo->setX(kolo->x()-krok);
    kolo->setY(kolo->y()-krok);
    }
    else
    {
        wybor=0;
    }
    if(wybor%(500/krok)==0) player->play();
}
void Kolo::okrag()
{

    if(wybor<360/krok)
    {
    wybor++;
    kolo->setX(325+300.0*sin((wybor*krok)*0.0174532925199433)-rozX);
    kolo->setY(325+300.0*cos((wybor*krok)*0.0174532925199433)-rozY);
    }
    else
    {
        player->play();
        wybor=0;
    }
}
void Kolo::goradol()
{
    wybor++;
    if(wybor<450/krok)
    {
        kolo->setX(275);
        kolo->setY(kolo->y()+krok);
    }
    else if(wybor>=450/krok&&wybor<900/krok)
    {
        kolo->setX(275);
        kolo->setY(kolo->y()-krok);
    }
    else
    {
         wybor=0;
    }

    if(wybor%(450/krok)==0) player->play();
}
void Kolo::plus()
{
    zatrzymanie();
    cwiczenie++;if(cwiczenie==5)cwiczenie=1;
    info->setText(("Ćwiczenie: "+ std::to_string(cwiczenie)).c_str());
    ocwiczeniu->setText(opisy[cwiczenie].c_str());
    timer.stop();
    odzmiany.stop();
}
void Kolo::minus()
{
    zatrzymanie();
    cwiczenie--;if(cwiczenie==0)cwiczenie=4;
    info->setText(("Ćwiczenie: "+ std::to_string(cwiczenie)).c_str());
    ocwiczeniu->setText(opisy[cwiczenie].c_str());
    timer.stop();
    odzmiany.stop();
}
void Kolo::zatrzymanie()
{
    switch(cwiczenie)
    {
    case 1://mruganie
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(mruganie()));
        disconnect(&odzmiany, SIGNAL(timeout()), this, SLOT(zmiana()));
        kolo->setPixmap(*x);
    break;
    case 2://goradol;
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(goradol()));
    break;
    case 3://klepsydra;
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(klepsydra()));
    break;
    case 4://kolo
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(okrag()));
    break;
    }
    kolo->setX(275);kolo->setY(300);
    timer.stop();
    odzmiany.stop();
}
