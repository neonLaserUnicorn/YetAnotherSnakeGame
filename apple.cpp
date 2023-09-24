
#include "apple.h"
#include "gamescreen.h"
#include<QColor>

Apple::Apple(QPoint pos)
{
    position = pos;
}

void Apple::draw(QPainter &painter)
{
    painter.setBrush(QBrush(QColor("red")));
    painter.drawEllipse(QRect(position.x(), position.y(), GameScreen::OFFSET, GameScreen::OFFSET ));
}

QPoint Apple::pos()
{
    return position;
}
