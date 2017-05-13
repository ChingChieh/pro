#include <QApplication>
#include "Game.h"
#include <QTimer>
Game * game;
int mana = 10;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();



    return a.exec();
}
