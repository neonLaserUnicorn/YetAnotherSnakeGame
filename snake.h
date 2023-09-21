
#ifndef SNAKE_H
#define SNAKE_H


#include <QWidget>


class Snake : public QWidget
{
    Q_OBJECT
public:
    explicit Snake(QWidget *parent = nullptr);
    QPoint position() const;
    void draw(QPainter& p);
private:
    QList<QPoint> body;
    QPoint* head;
    QPoint direction;
    int dist;
signals:

};

#endif // SNAKE_H
