#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pbManu_clicked();

    void on_pbData_clicked();

    void on_pbSettings_clicked();

    void on_pbAbout_clicked();





private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
