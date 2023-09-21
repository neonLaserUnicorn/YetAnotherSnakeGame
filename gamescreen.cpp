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
    init();
}
GameScreen::GameScreen(QWidget *parent, const QRect& geometry) :
    QWidget(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
    setWindowTitle("YASG");
    this->setGeometry(geometry);

    init();
}

void GameScreen::init()
{
    apple = new Apple(QPoint(100,100));
    QTimer* timerId = new QTimer(this);
    connect(timerId, &QTimer::timeout, this, &GameScreen::redraw);
    timerId->start(TIME);
}
GameScreen::~GameScreen()
{
    delete ui;
}

void GameScreen::paintEvent(QPaintEvent* pEvent)
{
    Q_UNUSED(pEvent);
    qDebug("aaaa");
    QPainter paint(this);
    apple->draw(paint);
}

void GameScreen::redraw()
{
    update();
}
