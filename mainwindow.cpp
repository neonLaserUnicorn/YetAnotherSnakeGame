
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
