#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include "kolo.h"

class MainWindow : public QMainWindow
{
    Kolo k;
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

#endif // MAINWINDOW_H
