
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::menuAnimation()
{
    //TODO: изменять градиент бэкграунда каждый тик
        qint32 delta = ((int)(x1BackgroundOffset*100)+1)%100;
        x1BackgroundOffset = delta / 100.0;
        QString insert;
        insert.setNum(x1BackgroundOffset);
        this->setStyleSheet(QString("background-color: qlineargradient(spread:reflect, x1:" + insert + ", y1:0.54, x2:0.553, y2:0.476864, stop:0.0666667 rgba(69, 100, 23, 255), stop:0.385714 rgba(116, 101, 35, 255), stop:1 rgba(255, 134, 18, 255));"));

}


void MainWindow::on_startButton_clicked()
{
    qDebug("Начало игры");
    //TODO: ПЕРЕХОД НА ЭКРАН НАЧАЛА ИГРЫ
}

void MainWindow::on_scoreButton_clicked()
{
    qDebug("Рекорд");
    //TODO: ОКНО РЕКОРДОВ
}
