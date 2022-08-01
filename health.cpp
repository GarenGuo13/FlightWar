#include "health.h"
#include <QFont>

Health::Health()
{
    health = HEALTH_PLAYER;
    setPlainText(QString("Health: ") + QString::number(health));
    setFont(QFont("times", 16));
    setPos(0, 0);
}

void Health::RestartGame()
{
    health = HEALTH_PLAYER;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));

    if(health <= 0){
        emit EGameOver();
    }
}
