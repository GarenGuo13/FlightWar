#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(uint level = 1, QObject *parent = nullptr);
    ~Enemy();

    void GameOver();
signals:
    void hurt(Enemy*);
    void hit(Enemy*);
    void out(Enemy*);


private slots:
    void move();

private:
    QTimer* timer;
};

#endif // ENEMY_H
