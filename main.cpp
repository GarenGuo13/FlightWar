#include <QApplication>

#include <QDebug>
#include <gamesetingtweight.h>
//new ��������
//delete ���ٶ���
int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);

    GameSetingtWeight* gameSet = new GameSetingtWeight();
    gameSet->show();


    return a.exec();
}
