#include "kolo.h"

Kolo::Kolo()
{
    setGeometry(56,100,800,800);

    scena = new QGraphicsScene(0, 0, 600, 600);
    widok = new QGraphicsView(scena, this);
    widok->setGeometry(50, 50, 700, 700);
    QPen pen;
    int x = 200, y = 300, w = 50, h = 50;
    kolo = new QGraphicsEllipseItem(x,y,w,h);
    kolo->setBrush(Qt::red);
    pen.setColor(QColor(Qt::black));
    pen.setWidth(6);
    kolo->setPen(pen);
    scena->addItem(kolo);
    czas = 10;
    zaczynamy();
}

Kolo::~Kolo()
{
        delete widok;
        delete scena;
}
void Kolo::keyPressEvent(QKeyEvent *Event)
{
    switch (Event->key()) {
    case Qt::Key_Up:

    break;
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
    default:
        break;
    }
}
void Kolo::zaczynamy()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(moment()));
    timer.start(czas);
}

void Kolo::moment()
{
    static int krok = 1;
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
