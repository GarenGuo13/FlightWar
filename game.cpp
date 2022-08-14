#include "game.h"
#include "main.h"
#include <time.h>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

#include <iostream>

Game::Game(const QString& username, const uint level)
{
    dbOpt.CreateTable();
    dbOpt.InsertDB("大牛", 1, 10);

    this->username = username;
    this->level = level;

    srand(static_cast<unsigned int>(time(nullptr)));
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage("://image/background.jpg")));

    bullet = new Bullet();
    scene->addItem(bullet);

    player = new Player();
    scene->addItem(player);

    health = new Health();
    scene->addItem(health);

    score = new Score();
    scene->addItem(score);

    connect(health, &Health::EGameOver, this, &Game::SGameOver);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setScene(scene);

    timerCreateEnemy = new QTimer();
    connect(timerCreateEnemy, &QTimer::timeout, this, &Game::CreateEnemy);

    timerCreateEnemy->start(1000 - 50 * this->level);

    vecEnemy = new std::vector<Enemy*>();

    scoreBoard = new ScoreBoard();
    scoreBoard->setWindowTitle("积分榜");
    connect(scoreBoard, &ScoreBoard::exit, this, &Game::Exit);
    connect(scoreBoard, &ScoreBoard::restart, this, &Game::Restart);

    path = new QString("c:/socre.txt");
}

void Game::run()
{
    show();
}

void Game::SaveScore(const QString& path, const QString& score)
{
    QFile file(path);
    if(!file.open(QIODevice::Append | QIODevice::Text)){
        return;
    }

//    qDebug() << score;

    QTextStream out(&file);
    out << score;
    out << endl;

    file.close();
}

QVector<RecordInfo *>* Game::ReadScore(const QString& path) const
{
    QVector<RecordInfo *>* vec = new QVector<RecordInfo *>();
    QFile file(path);
    if(! file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return vec;
    }

    QTextStream in(&file);
    while(! in.atEnd()){
        QStringList strList = in.readLine().split("\t", QString::SkipEmptyParts);
        if(strList.size() >= 1){
            vec->push_back(new RecordInfo(strList.at(0), strList.at(1)));
        }
    }

    file.close();
    return vec;
}

void Game::ClearFullEnemy()
{
    //    for (auto item : *vecEnemy){
    //        item->GameOver();
    //    }
    auto iter = vecEnemy->begin();
    while (iter != vecEnemy->end()) {
        (*iter)->GameOver();
//        delete *iter;
        iter = vecEnemy->erase(iter);
    }
}


void Game::CreateEnemy()
{
    Enemy* enemy = new Enemy(this->level);

    vecEnemy->push_back(enemy);
    // 0 ~ WIDTH - enemy
    //rand 伪随机数
    // 随机数种子
    enemy->setPos(static_cast<int>(rand() % (WIDTH - enemy->pixmap().width())), 0);
    scene->addItem(enemy);

    connect(enemy, &Enemy::hurt, health, &Health::decrease);
    connect(enemy, &Enemy::hit, score, &Score::increase);

    connect(enemy, &Enemy::hit, this, &Game::UpdateVecEnemy);
    connect(enemy, &Enemy::hurt, this, &Game::UpdateVecEnemy);
    connect(enemy, &Enemy::out, this, &Game::UpdateVecEnemy);
}

void Game::SGameOver()
{
    timerCreateEnemy->stop();

    player->GameOver();

    ClearFullEnemy();



    SaveScore(*path, QDateTime::currentDateTime().toString("yy-MM-dd hh:mm:ss") + "\t" + QString::number(score->getScore()));

    scoreBoard->setScore(score->getScore());
    scoreBoard->UpdataTable(ReadScore(*path));
    scoreBoard->show();
}

void Game::UpdateVecEnemy(Enemy* _enemy)
{
    auto iter = vecEnemy->begin();
    while (iter != vecEnemy->end()) {
        if(*iter == _enemy){
            delete *iter;
            vecEnemy->erase(iter);
            break;
        }
        iter++;
    }
}

void Game::Exit()
{
    this->close();
}

void Game::Restart()
{
    timerCreateEnemy->start(500);
    health->RestartGame();
    score->RestartGame();
    player->RestartGame();
}
