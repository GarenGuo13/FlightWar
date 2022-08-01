#include <QApplication>

#include <QDebug>
#include <gamesetingtweight.h>
//new 创建对象
//delete 销毁对象
int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);

    GameSetingtWeight* gameSet = new GameSetingtWeight();
    gameSet->show();


    return a.exec();
}
