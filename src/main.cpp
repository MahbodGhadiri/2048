#include <QApplication>
#include <QPushButton>
#include "gui/grid.h"
#include <iostream>
int main(int argc, char **argv)
{
    // std::cout<< "Mahbod1";
    QApplication app (argc, argv);
    // QWidget window;
    // window.setFixedSize(400, 400);

    // QPushButton *button = new QPushButton("Hello World", &window);
    // button->setGeometry(10, 10, 80, 30);

    // window.show();
    Grid grid;
    grid.show();
    return app.exec();
}