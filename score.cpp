#include "score.h"
#include <QFont>

Score::Score()
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setFont(QFont("times", 16));
    setPos(0, 30);
}

void Score::RestartGame()
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() const
{
    return score;
}

void Score::increase()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
}
