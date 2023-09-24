
#include "snake.h"
#include "gamescreen.h"
#include <QPainter>
#include <QKeyEvent>
Snake::Snake(QWidget *parent)
    : QWidget{parent}
{
    dist = GameScreen::OFFSET;
    QPoint startPoint = parent->geometry().center()/2;
    startPoint -= QPoint(startPoint.x()%dist, startPoint.y()%dist);
    direction = QPoint(0,1);
    body.push_back(startPoint);
    body.push_back(startPoint - direction*dist);
    body.push_back(startPoint - direction*dist*2);
    head = body.begin();
}

QPoint Snake::position() const
{
    return *head;
}

void Snake::draw(QPainter& painter)
{
    move();
    painter.setBrush(QBrush(QColor("green")));
    painter.drawEllipse(QRect(head->x(), head->y(), dist, dist ));

    for(auto it = body.begin()+1; it != body.end(); it++)
    {
        painter.setBrush(QBrush(QColor("yellow")));
        painter.drawEllipse(QRect(it->x(), it->y(), dist, dist ));
    }
}
void Snake::move()
{
    QPoint current = *head;
    (*head)+=direction*dist;
    for(auto it = body.begin()+1; it != body.end(); it++)
    {
        QPoint temp = *it;
        *it = current;
        current = temp;
    }
    //TODO: optimize it
    if(body.contains(*head + direction*dist))
    {
        emit end();
    }
}
void Snake::keyPressEvent(QKeyEvent* event)
{

    int key = event->key();
    if((key == Qt::Key_A || key == Qt::Key_Left) && direction != QPoint(1,0))
    {
        direction = QPoint(-1,0);
    }
    if((key == Qt::Key_W || key == Qt::Key_Up) && direction != QPoint(0,1))
    {
        direction = QPoint(0,-1);
    }
    if((key == Qt::Key_D || key == Qt::Key_Right)&& direction != QPoint(-1,0))
    {
        direction = QPoint(1,0);
    }
    if((key == Qt::Key_S || key == Qt::Key_Down)&& direction != QPoint(0,-1))
    {
        direction = QPoint(0,1);
    }
}

void Snake::grow()
{
    QPoint tempDirection = *(body.crbegin()+1) - *(body.crbegin());
    QPoint newPiece(body.last()-tempDirection*dist);
    body.push_back(newPiece);
    head = body.begin();
}
QList<QPoint> Snake::getBody() const
{
    return body;
}
