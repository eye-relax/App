#include "mainwindow.h"
#include <QPen>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QLabel>
#include <string>
#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(56,100,900,900);
    this->setCentralWidget(&k); //tu jest włączenie klasy "Kolo" do okna
}

MainWindow::~MainWindow()
{

}
