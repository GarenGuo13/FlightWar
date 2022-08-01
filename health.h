#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

#define HEALTH_PLAYER   1

class Health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health();
    void RestartGame();

public slots:
    void decrease();

signals:
    void EGameOver();

private:
    int health;
};

#endif // HEALTH_H
