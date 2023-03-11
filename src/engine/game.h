#ifndef GAME_H
#define GAME_H
#define SIZE 4

#include <vector>
#include "tile.h"

class Game
{
    private:
        std::vector<std::vector<Tile*>> board;
        bool gameover = false;
        int score = 0;
        int freeSpace = SIZE * SIZE;
    public:
        Game();
        ~Game();
        std::vector<std::vector<Tile*>> getBoard();
        void move(int direction);
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        void merge(int i1, int j1, int i2, int j2);
        void generateTile();
        enum Direction{
            UP = 0,
            DOWN = 1,
            LEFT = 2,
            RIGHT = 3
        };
        bool hasGameEnded();
        bool isGameOver();
        int getScore();
        void restart();
};


# endif