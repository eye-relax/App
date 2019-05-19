#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QPixmap pix1("C:/Users/Eugen/Documents/QT/Photos/eye1.png");
//    int w = ui->pix_label->width();
//    int h = ui->pix_label->height();
//    ui->pix_label->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix0("C:/Users/Eugen/Documents/QT/Photos/patryk.png");
    int Pw = ui->PatrykLabel->width();
    int Ph = ui->PatrykLabel->height();
    ui->PatrykLabel->setPixmap(pix0.scaled(Pw,Ph,Qt::KeepAspectRatio));
    // ui->PatrykLabel->setGeometry(20,3,28,28);

    QPixmap pix1("C:/Users/Eugen/Documents/QT/Photos/konrad.png");
    int Kw = ui->KonradLabel->width();
    int Kh = ui->KonradLabel->height();
    ui->KonradLabel->setPixmap(pix1.scaled(Kw,Kh,Qt::KeepAspectRatio));

    QPixmap pix2("C:/Users/Eugen/Documents/QT/Photos/michal.png");
    int Mw = ui->MichalLabel->width();
    int Mh = ui->MichalLabel->height();
    ui->MichalLabel->setPixmap(pix2.scaled(Mw,Mh,Qt::KeepAspectRatio));

    QPixmap pix3("C:/Users/Eugen/Documents/QT/Photos/stanislav1.png");
    int Sw = ui->StanislavLabel->width();
    int Sh = ui->StanislavLabel->height();
    ui->StanislavLabel->setPixmap(pix3.scaled(Sw-5,Sh-5,Qt::KeepAspectRatio));

    QPixmap pix4("C:/Users/Eugen/Documents/QT/Photos/eugene.png");
    int Ew = ui->EugeneLabel->width();
    int Eh = ui->EugeneLabel->height();
    ui->EugeneLabel->setPixmap(pix4.scaled(Ew,Eh,Qt::KeepAspectRatio));

    ui->clock->display("12:44");
}

MainWindow::~MainWindow()
{
    delete ui;
}




//void MainWindow::on_pbmanu_clicked()
//{
    // ui->pbmanu->setStyleSheet("QPushButton:pressed { background-color: yellow }");
//}





void MainWindow::on_pbManu_clicked()
{
    ui->pbData->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbSettings->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbAbout->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );

    ui->pbManu->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px;}");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pbData_clicked()
{
    ui->pbManu->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbSettings->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbAbout->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );

    ui->pbData->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pbSettings_clicked()
{
    ui->pbData->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }" );
    ui->pbManu->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }" );
    ui->pbAbout->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }" );

    ui->pbSettings->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pbAbout_clicked()
{
    ui->pbData->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbSettings->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbManu->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );

    ui->pbAbout->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");

    ui->stackedWidget->setCurrentIndex(3);
}


