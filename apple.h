
#ifndef APPLE_H
#define APPLE_H

#include<QWidget>
#include<QPainter>

class Apple
{

    QPoint position;
public:
    Apple(QPoint pos);
    QPoint pos();
    void draw(QPainter &painter);
};

#endif // APPLE_H
