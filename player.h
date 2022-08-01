#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "health.h"
class Player : public  QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    ~Player();
    void GameOver();
    void RestartGame();


protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public slots:
    void move();

private:
    bool m_bUp,m_bDown,m_bLeft,m_bRight; //m: member£¬ b:bool

    QTimer* timer;

};

#endif // PLAYER_H
