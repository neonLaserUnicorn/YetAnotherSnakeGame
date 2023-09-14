#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QTimer>
class Apple;
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
    static const int OFFSET = 10;

private:
    QTimer *timerId;
    Apple *apple;
    Ui::GameScreen *ui;
protected:
    void paintEvent(QPaintEvent* pEvent);
    void timer(QTimerEvent* tEvent);
};

#endif // GAMESCREEN_H
