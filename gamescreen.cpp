#include "gamescreen.h"
#include "ui_gamescreen.h"

GameScreen::GameScreen(QWidget *parent, int width, int height) :
    QWidget(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
    setGeometry(0,0, width, height);
    setWindowTitle("YASG");
}
GameScreen::GameScreen(QWidget *parent, const QRect& geometry) :
    QWidget(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
    setWindowTitle("YASG");
    this->setGeometry(geometry);
}
GameScreen::~GameScreen()
{
    delete ui;
}
