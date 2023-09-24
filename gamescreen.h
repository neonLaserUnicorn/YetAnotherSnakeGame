#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QTimer>

class Apple;
class Snake;

namespace Ui {
class GameScreen;
}

class GameScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = nullptr, int width = 300, int height = 300);
    explicit GameScreen(QWidget *parent = nullptr, const QRect& geometry = QRect());
    ~GameScreen();
    static int OFFSET;


private:
    int width, height;
    const int TIME = 1000;
    void init();
    Apple *apple;
    Snake *snake;
    Ui::GameScreen *ui;
    void replace();
signals:
    void turn(QKeyEvent* e);
protected slots:
    void paintEvent(QPaintEvent* pEvent);
    void redraw();
    void keyPressEvent(QKeyEvent*);
};

#endif // GAMESCREEN_H
