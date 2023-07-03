#include "Block.h"
#include "Canvas.h"
#include <stdlib.h>

Block block_create(blockType type){
    Block block = malloc(sizeof(*block));
    block->type = type;
    block->x = rand() % SCREEN_WIDTH;
    block->y = rand() % SCREEN_HEIGHT;
    return block;
}

void move(Block element){
    element->x += rand() % 3 - 1;
    element->y += rand() % 3 - 1;
}

void block_destroy(Block block){
    free(block);
}