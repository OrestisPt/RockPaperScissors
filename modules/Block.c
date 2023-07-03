#include "Block.h"
#include "Canvas.h"
#include <stdlib.h>

Block block_create(blockType type){
    Block block = malloc(sizeof(*block));
    block->directionx = rand() % 5 + 1;
    block->directiony = rand() % 5 + 1;
    block->type = type;
    block->x = rand() % (SCREEN_WIDTH-50);
    block->y = rand() % (SCREEN_HEIGHT-50);
    return block;
}

void move(Block element){
    if(element->x < 0 || element->x > SCREEN_WIDTH-50)
        element->directionx *= -1;
    if(element->y < 0 || element->y > SCREEN_HEIGHT-50)
        element->directiony *= -1;
    element->x += element->directionx;
    element->y += element->directiony;
}

void block_destroy(Block block){
    free(block);
}