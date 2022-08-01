#include "player.h"
#include <QGraphicsScene>
#include "main.h"
#include <QKeyEvent>
#include "bullet.h"

Player::Player()
{
    setPixmap(QPixmap("://image/player.png"));
    setPos((WIDTH - pixmap().width())/2, (HEIGHT - pixmap().height())/ 2);

    setFlags(QGraphicsItem::ItemIsFocusable);
    setFocus();

    m_bUp = false;
    m_bDown = false;
    m_bLeft = false;
    m_bRight = false;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Player::move);
    timer->start(5);

}

Player::~Player()
{
    delete timer;
}

void Player::RestartGame()
{
    m_bUp = false;
    m_bDown = false;
    m_bLeft = false;
    m_bRight = false;

    setPos((WIDTH - pixmap().width())/2, (HEIGHT - pixmap().height())/ 2);
    timer->start(5);
}

void Player::GameOver()
{
    timer->stop();
}



void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        this->m_bUp = true;
    }
    if(event->key() == Qt::Key_Down){
        this->m_bDown = true;
    }
    if(event->key() == Qt::Key_Left){
        this->m_bLeft = true;
    }
    if(event->key() == Qt::Key_Right){
        this->m_bRight = true;
    }
    if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().width()/2, y());
        scene()->addItem(bullet);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        this->m_bUp = false;
    }
    if(event->key() == Qt::Key_Down){
        this->m_bDown = false;
    }
    if(event->key() == Qt::Key_Left){
        this->m_bLeft = false;
    }
    if(event->key() == Qt::Key_Right){
        this->m_bRight = false;
    }
}

void Player::move()
{
    //up
    if(m_bUp){
        if(y() > 0){
            setPos(x(), y() - 1);
        }
    }
    if(m_bDown){
        if(y() < HEIGHT - pixmap().height()){
            setPos(x(), y() + 1);
        }
    }
    if(m_bLeft){
        if(x() > 0){
            setPos(x() - 1, y());
        }
    }
    if(m_bRight){
        if(x() < WIDTH - pixmap().width()){
            setPos(x() + 1, y());
        }
    }
}
