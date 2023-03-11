#include <QApplication>
#include <QPushButton>
#include "gui/qgame.h"
#include <iostream>
int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QGame qgame;
    qgame.show();
    return app.exec();
}