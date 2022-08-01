#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "main.h"

Bullet::Bullet()
{
    Bullet::iNumer++;
    if(Bullet::iNumer > 10)
    {
        Bullet::iNumer = 10;
        return;
    }


    setPixmap(QPixmap(":/image/bullet2.png"));

    setPos(WIDTH/2, HEIGHT/2);

    timer = new QTimer();
    //    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(10);
}

int Bullet::iNumer = 0;

Bullet::~Bullet()
{
    qDebug() << "Bullet::~Bullet()...";
    delete timer;
    Bullet::iNumer--;
}

void Bullet::move()
{
    setPos(x(), y() - 1);
    if(y() < - pixmap().height()){
//        qDebug() << "before Bullet::move()...";
        delete this;
        return;
    }
}
