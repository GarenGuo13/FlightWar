#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QDateTime>
#include <QVector>
#include <QtAlgorithms>



namespace Ui {
class ScoreBoard;
}

struct RecordInfo{
    RecordInfo(QString _dataTime, QString _score):
        dataTime(_dataTime),score(_score) {};
    QString   dataTime;
    QString         score;
};

class ScoreBoard : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreBoard(QWidget *parent = nullptr);
    ~ScoreBoard();
    void UpdataTable(QVector<RecordInfo*>* vecInfo);

    void setScore(int newScore);

signals:
    void exit();
    void restart();

private slots:
    void on_okButton_clicked();

    void on_retryButton_clicked();

private:
    Ui::ScoreBoard *ui;
    int score;
    static bool scoreCmpare(RecordInfo* recordInfo1, RecordInfo* recordInfo2);
};

#endif // SCOREBOARD_H
