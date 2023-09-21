
#include "snake.h"
#include "gamescreen.h"
#include <QPainter>
Snake::Snake(QWidget *parent)
    : QWidget{parent}
{
    dist = GameScreen::OFFSET;
    QPoint startPoint = parent->geometry().center();
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
    painter.setBrush(QBrush(QColor("green")));
    painter.drawEllipse(QRect(head->x(), head->y(), dist, dist ));
    for(auto it = body.begin()+1; it != body.end(); it++)
    {
        painter.setBrush(QBrush(QColor("yellow")));
        painter.drawEllipse(QRect(it->x(), it->y(), dist, dist ));
    }
}
