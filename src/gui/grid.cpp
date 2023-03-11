#include "grid.h"
#include <QPushButton>
#include <QPainter>
#include <QVBoxLayout>
#include <QGridLayout>
#include "../engine/tile.h"
#include "../engine/game.h"
#include "qtile.h"
#include <QWidget>
#include <QKeyEvent>
#include <QObject>
Grid::Grid(QWidget* parent){
    width = 600;
    height = 600;
    resize(width,height);
    // create the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");
    

    gui_board.resize(4);

    for (int i = 0; i < 4; ++i){
        gui_board[i].resize(4);
        for (int j = 0; j < 4; ++j){
            gui_board[i][j] = NULL;
        }
    }
    render();
    connect(gameover.getResetBtn(), SIGNAL(clicked()), this, SLOT(restart()));
}

void Grid::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()){
    case Qt::Key_Up:
        game->move(Game::UP);
        break;
    case Qt::Key_W:
        game->move(Game::UP);
        break;
    case Qt::Key_Left:
        game->move(Game::LEFT);
        break;
    case Qt::Key_A:
        game->move(Game::LEFT);
        break;
    case Qt::Key_Right:
        game->move(Game::RIGHT);
        break;
    case Qt::Key_D:
        game->move(Game::RIGHT);
        break;
    case Qt::Key_Down:
        game->move(Game::DOWN);
        break;
    case Qt::Key_S:
        game->move(Game::DOWN);
        break;
    }
    render();

    // check if game ended after this move
    // if so, show game over widget   
    if(game->isGameOver()){
        gameover.setScore(game->getScore());
        gameover.show();
    }
}

void Grid::render(){
    boardLayout = new QGridLayout();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            delete gui_board[i][j];
            gui_board[i][j] = new QTile(game->getBoard()[i][j]);
            boardLayout->addWidget(gui_board[i][j], i, j);
            gui_board[i][j]->draw();
        }
    }

    mainLayout->insertLayout(0, boardLayout);
}

void Grid::restart() {
    game->restart();
    gameover.hide();
    render();
}

