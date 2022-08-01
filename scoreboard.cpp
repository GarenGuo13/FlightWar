#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <qdebug.h>
//https://blog.csdn.net/qq_38255284/article/details/116382135
ScoreBoard::ScoreBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScoreBoard)
{
    ui->setupUi(this);
    ui->scoreTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->scoreTable->setRowCount(5);
}

ScoreBoard::~ScoreBoard()
{
    delete ui;
}

void ScoreBoard::UpdataTable(QVector<RecordInfo*>* vecInfo)
{
    qSort(vecInfo->begin(), vecInfo->end(), scoreCmpare);

    for (int i=0; i < vecInfo->size(); ++i) {
        if(i < 3){
            ui->scoreTable->setItem(i,0,new QTableWidgetItem(vecInfo->at(i)->dataTime));
            ui->scoreTable->setItem(i,1,new QTableWidgetItem(vecInfo->at(i)->score));
        }
    }
    ui->scorelabel->setText("本次积分：" + QString::number(this->score));
}

void ScoreBoard::on_okButton_clicked()
{
    emit exit();
    this->close();
}


void ScoreBoard::on_retryButton_clicked()
{
    emit restart();
    this->hide();
}

void ScoreBoard::setScore(int newScore)
{
    score = newScore;
}

bool ScoreBoard::scoreCmpare(RecordInfo* recordInfo1, RecordInfo* recordInfo2)
{
    return  recordInfo1->score.toInt() > recordInfo2->score.toInt();
}


