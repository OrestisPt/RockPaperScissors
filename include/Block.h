#pragma once

typedef enum {
    Rock, Paper, Scissors
}blockType;

typedef struct block {
    blockType type;
    int x;
    int y;
}*Block;

Block block_create(blockType type);

void move(Block element);

void block_destroy(Block block);