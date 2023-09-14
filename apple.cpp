
#include "apple.h"
#include "gamescreen.h"

Apple::Apple(QPoint pos)
{
    position = pos;
}

void Apple::draw(QPainter &painter)
{
    painter.drawEllipse(QRect(position.x(), position.y(), GameScreen::OFFSET, GameScreen::OFFSET ));
}
