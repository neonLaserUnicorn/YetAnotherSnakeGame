#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "apple.h"

GameScreen::GameScreen(QWidget *parent, int width, int height) :
    QWidget(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
    setGeometry(0,0, width, height);
    setWindowTitle("YASG");
    apple = new Apple(QPoint(100,100));
    timerId = new QTimer(this);
    timerId->setInterval(100);
    connect(timerId, SIGNAL(QTimer::timeout), this, SLOT(repaint()));
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

void GameScreen::paintEvent(QPaintEvent* pEvent)
{
    Q_UNUSED(pEvent);
    QPainter paint(this);
    apple->draw(paint);
}

void GameScreen::timer(QTimerEvent* tEvent)
{
    Q_UNUSED(tEvent);
    qDebug("aaa");
    repaint();
}
