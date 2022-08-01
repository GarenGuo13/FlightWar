#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "bullet.h"
#include "player.h"
#include "enemy.h"
#include "health.h"
#include "score.h"
#include <vector>
#include "scoreboard.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(const QString& username, const uint level);
    void run();

private:
    void SaveScore(const QString& path, const QString& score);
    QVector<RecordInfo*>* ReadScore(const QString& path) const;
    void ClearFullEnemy();

private slots:
    void CreateEnemy();
    void SGameOver();
    void UpdateVecEnemy(Enemy*);
    void Exit();
    void Restart();

private:
    QGraphicsScene* scene;
    Bullet* bullet;
    Player* player;
    Health* health;
    Score*  score;
    QTimer* timerCreateEnemy;
    std::vector<Enemy *>* vecEnemy;
    ScoreBoard* scoreBoard;
    QString* path;
    QString username;
    uint    level;

};

#endif // GAME_H
