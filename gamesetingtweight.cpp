#include "gamesetingtweight.h"
#include "ui_gamesetingtweight.h"

GameSetingtWeight::GameSetingtWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSetingtWeight)
{
    ui->setupUi(this);

}

GameSetingtWeight::~GameSetingtWeight()
{
    delete ui;
}

void GameSetingtWeight::on_startBtn_clicked()
{
    if(ui->username->text().isEmpty())
        return;

    game = new Game(ui->username->text(), ui->level->currentText().toUInt());
    game->run();

    this->close();
}

