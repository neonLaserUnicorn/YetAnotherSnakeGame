#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>

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
    Ui::GameScreen *ui;

};

#endif // GAMESCREEN_H
