
#include "mainwindow.h"

#include <QApplication>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Yet Another Snake Game");

    w.show();
        w.menuAnimation();
    return a.exec();
}
