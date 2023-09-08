
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamescreen.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void menuAnimation();
private slots:
    void on_startButton_clicked();
    void on_scoreButton_clicked();

private:
    Ui::MainWindow *ui;
    qreal x1BackgroundOffset = 0.0;
    GameScreen* gs = nullptr;
};

#endif // MAINWINDOW_H
