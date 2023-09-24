#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "apple.h"
#include "snake.h"
#include <QRandomGenerator>

int GameScreen::OFFSET = 10;
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
    OFFSET = geometry().width()/20;
    width = geometry().width() / OFFSET;
    height = geometry().height() / OFFSET;
    apple = new Apple(QPoint(100-100%OFFSET,100 -100%OFFSET));
    snake = new Snake(this);
    QTimer* timerId = new QTimer(this);
    connect(timerId, &QTimer::timeout, this, &GameScreen::redraw);
    connect(this, &GameScreen::turn, snake, &Snake::keyPressEvent);
    connect(snake, &Snake::end, this, &GameScreen::stop);
    timerId->start(TIME);
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
    snake->draw(paint);
}

void GameScreen::redraw()
{
    this->findChild<QTimer>().start(TIME);
    if(apple->pos()==snake->position())
    {
        snake->grow();
        replace();
    }
    update();
}
void GameScreen::keyPressEvent(QKeyEvent* e)
{
    emit turn(e);
    redraw();

}

void GameScreen::replace()
{
    QRandomGenerator randGen;
    QList<QPoint> wrongPlaces;
    wrongPlaces.push_back(apple->pos());
    wrongPlaces.append(snake->getBody());
    QPoint newPlace = apple->pos();
    while(wrongPlaces.contains(newPlace))
    {
        newPlace = QPoint(randGen.bounded(width), randGen.bounded(height)) * OFFSET;
    }
    apple->setPosition(newPlace);
    redraw();
}

void GameScreen::stop()
{
    //TODO: remake timer to stop it
    qDebug("STOP!");
    this->findChild<QTimer>().stop();

}
