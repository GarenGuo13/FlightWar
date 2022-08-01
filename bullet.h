#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>

class Bullet : public  QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    ~Bullet();
//    Bullet(QTimer* timer);

private slots:
    void move();

public:
    static int iNumer;

private:
    QTimer* timer;
};

#endif // BULLET_H
