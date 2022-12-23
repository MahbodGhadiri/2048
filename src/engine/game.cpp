#include <vector>
#include <utility> // pair
#include <cstdlib>
#include <time.h>
#include "game.h"
#include "tile.h"
#include <iostream>
Game::Game(){
    std::srand(time(0));
    board.resize(SIZE);
    for(int i = 0; i < SIZE; i++){
        board[i].resize(SIZE);
        for(int j = 0; j < SIZE; j++){
            board[i][j] = nullptr;
        }
    }
    generateTile();
}

std::vector<std::vector<Tile*>> Game::getBoard(){
    return board;
}

void Game::move(int direction){
    switch (direction)
    {
        case UP:
            moveUp();
            break;
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
        case DOWN:
            moveDown();
            break;
    }
    generateTile();
}

void Game::moveRight(){
    for(int i = 0; i < SIZE; i++){
        int k = SIZE - 1;
        for(int j = k; j > -1; j--){
            if(board[i][j] != nullptr){
                // merge
                for(int z = j - 1; z > -1; z--){
                    if(board[i][z] != nullptr){
                        if(board[i][z]->getValue() == board[i][j]->getValue()){
                            merge(i, j, i, z);
                        }
                        break;
                    }
                }
                // end merge
                if(j!=k){
                    board[i][k] = board[i][j];
                    board [i][j] = nullptr; 
                }
                k--;
            }
        }
    }
}
void Game::moveLeft(){
    for(int i = 0; i < SIZE; i++){
        int k = 0;
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] != nullptr){
                // merge
                for(int z = j + 1; z < SIZE; z++){
                    if(board[i][z] != nullptr){
                        if(board[i][z]->getValue() == board[i][j]->getValue()){
                            merge(i, j, i, z);
                        }
                        break;
                    }
                }
                // end merge
                if(j!=k){
                    board[i][k] = board[i][j];
                    board [i][j] = nullptr; 
                }
                k++;
            }
        }
    }
}
void Game::moveUp(){
    for(int j = 0; j < SIZE; j++){
        int k = 0;
        for(int i = 0; i < SIZE; i++){
            if(board[i][j] != nullptr){
                //merge
                for(int z = i + 1; z < SIZE; z++){
                    if(board[z][j] != nullptr){
                        if(board[z][j]->getValue() == board[i][j]->getValue()){
                            merge(i, j, z, j);
                        }
                        break;
                    }
                }
                //end merge
                if(i!=k){
                    board[k][j] = board[i][j];
                    board [i][j] = nullptr; 
                }
                k++;
            }
        }
    }
}
void Game::moveDown(){
    for(int j = 0; j < SIZE; j++){
        int k = SIZE - 1;
        for(int i = k; i > -1; i--){
            if(board[i][j] != nullptr){
                //merge
                for(int z = i-1; z > -1; z--){
                    if(board[z][j]!= nullptr){
                        if(board[z][j]->getValue() == board[i][j]->getValue()){
                            merge(i, j, z, j);
                        }
                        break;
                    }
                }
                //end merge
                if(i!=k){
                    board[k][j] = board[i][j];
                    board [i][j] = nullptr; 
                }
                k--;
            }
        }
    }
}

void Game::merge(int i1, int j1, int i2, int j2){
    board[i1][j1]->merge();
    delete board[i2][j2];
    board[i2][j2] = nullptr;
    freeSpace ++;
}

void Game::generateTile(){
    std::vector<std::pair<int, int>> freeSpaces(freeSpace);
    int k = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == nullptr){
                freeSpaces[k] = std::pair<int, int>(i,j);
                //std::cout<< freeSpaces[k].first << "  " << freeSpaces[k].second << std::endl;
                k++;
            }
        }
    }
    int index = rand() % (freeSpace-1);
    std::pair<int, int> dest = freeSpaces[index];
    //std::cout<< dest.first << "  " << dest.second << std::endl;
    board[dest.first][dest.second] = new Tile();
    freeSpace --;
}