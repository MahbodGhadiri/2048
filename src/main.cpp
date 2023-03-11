#include <QApplication>
#include <QPushButton>
#include "gui/grid.h"
#include <iostream>
int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    Grid grid;
    grid.show();
    return app.exec();
}