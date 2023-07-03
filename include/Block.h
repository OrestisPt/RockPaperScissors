#pragma once


typedef struct block *Block;

typedef enum {
    Rock, Paper, Scissors
}blockType;

struct block {
    int directionx;
    int directiony;
    blockType type;
    int x;
    int y;
};

Block block_create(blockType type);

void move(Block element);

void block_destroy(Block block);