#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score();
    void RestartGame();
    int getScore() const;

public slots:
    void increase();

private:
    int score;
};

#endif // SCORE_H
