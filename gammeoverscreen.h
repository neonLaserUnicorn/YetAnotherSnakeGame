#ifndef GAMMEOVERSCREEN_H
#define GAMMEOVERSCREEN_H

#include <QWidget>

namespace Ui {
class GammeOverScreen;
}

class GammeOverScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GammeOverScreen(QWidget *parent = nullptr);
    ~GammeOverScreen();

private:
    Ui::GammeOverScreen *ui;
};

#endif // GAMMEOVERSCREEN_H
