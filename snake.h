
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
    void grow();
private:
    QList<QPoint> body;
    QPoint* head;
    QPoint direction;
    int dist;
    void move();
public slots:
    void keyPressEvent(QKeyEvent*);
signals:

};

#endif // SNAKE_H
