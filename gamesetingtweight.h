#ifndef GAMESETINGTWEIGHT_H
#define GAMESETINGTWEIGHT_H

#include <QWidget>
#include "game.h"

namespace Ui {
class GameSetingtWeight;
}

class GameSetingtWeight : public QWidget
{
    Q_OBJECT

public:
    explicit GameSetingtWeight(QWidget *parent = nullptr);
    ~GameSetingtWeight();

private slots:
    void on_startBtn_clicked();

private:
    Ui::GameSetingtWeight *ui;
    Game* game;
};

#endif // GAMESETINGTWEIGHT_H
