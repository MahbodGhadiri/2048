#ifndef TILE_H
#define TILE_H

#define EXP_MULTIPLIER 2

class Tile
{
    private:
        int value;
    public:
        Tile();
        Tile(const Tile& other);
        Tile(int value);
        int getValue();
        void merge();
};
#endif