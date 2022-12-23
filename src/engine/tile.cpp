#include "tile.h"

Tile::Tile(){
    value = 2;
}

Tile::Tile(int value){
    this->value = value;
}

Tile::Tile(const Tile &tile){
    this->value = tile.value;
}

int Tile::getValue(){
    return value;
}

void Tile::merge(){
    value *= EXP_MULTIPLIER;
}