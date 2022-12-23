#ifndef GRID_H
#define GRID_H

#include "../engine/game.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QVector>
#include "qtile.h"
class Grid: public QWidget{
    public:
        explicit Grid(QWidget *parent = 0);
        int width;
        int height;
        
    protected:
        void keyPressEvent(QKeyEvent *event);

    private:
        QVBoxLayout *mainLayout;
        QGridLayout *boardLayout;
        QVector<QVector<QTile*> > gui_board;
        Game *game = new Game();
        void render();

};

#endif