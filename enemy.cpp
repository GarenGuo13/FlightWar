#include "enemy.h"
#include "main.h"
#include <typeinfo>
#include "bullet.h"
#include "player.h"
#include <QDebug>

Enemy::Enemy(uint level, QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap("://image/enemy.png"));
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Enemy::move);

    timer->start(100 - 30 * level);
}

Enemy::~Enemy()
{
    qDebug() << "Enemy::~Enemy";
}

void Enemy::GameOver()
{
    timer->stop();
    delete this;
}


void Enemy::move()
{
    QList<QGraphicsItem *>  colliding = collidingItems(Qt::IntersectsItemShape);
//    QGraphicsPixmapItem* item;
//     item = dynamic_cast<QGraphicsPixmapItem*>(colliding[i]) ;
    for(int i=0; i< colliding.size(); ++i){
        if(typeid (*colliding[i]) == typeid (Bullet)){
            emit hit(this);
            delete colliding[i];
            return;

        }
        if(typeid (*colliding[i]) == typeid (Player)){
            emit hurt(this);
            return;
        }
    }

    setPos(x(), y() + 1);
    if(y() > HEIGHT){
        emit out(this);
        return;
    }
}
