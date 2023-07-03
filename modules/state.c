#include "state.h"
#include "Block.h"
#include <stdlib.h>

bool state_is_over(State state){
    return state->RockCount == state->totalCount || state->PaperCount == state->totalCount || state->ScissorsCount == state->totalCount;
}

int getwinner(State state){
    if(state->RockCount == state->totalCount)
        return Rock;
    else if(state->PaperCount == state->totalCount)
        return Paper;
    else if(state->ScissorsCount == state->totalCount)
        return Scissors;
    return -1;
}

Block block_collide(State state, Block block){
    for(int i = 0; i < state->totalCount; i++){
        if(block->x < state->Blocks[i]->x + 50 && block->x + 50 > state->Blocks[i]->x && block->y < state->Blocks[i]->y + 50 && block->y + 50 > state->Blocks[i]->y && block != state->Blocks[i]){
            return state->Blocks[i];
        }
    }
    return NULL;
}

State state_create(int n){
    State state = malloc(sizeof(*state));
    state->RockCount = n;
    state->PaperCount = n;
    state->ScissorsCount = n;
    state->totalCount = 3*n;
    state->Blocks = malloc(sizeof(Block) * (3*n));
    for(int i = 0; i < n; i++){
        state->Blocks[i] = block_create(Paper);
        state->Blocks[i+n] = block_create(Rock);
        state->Blocks[i+2*n] = block_create(Scissors);
    }
    return state;
}

void state_update(State state){
    for(int i = 0; i < state->totalCount; i++){
        Block collide = block_collide(state, state->Blocks[i]);
        if(collide != NULL){
            if(state->Blocks[i]->type == Rock){
                if(collide->type == Scissors){
                    collide->type = Rock;
                    state->RockCount++;
                    state->ScissorsCount--;
                } else if(collide->type == Paper){
                    state->Blocks[i]->type = Paper;
                    state->PaperCount++;
                    state->RockCount--;
                }
            } 
            else if(state->Blocks[i]->type == Paper){
                if(collide->type == Rock){
                    collide->type = Paper;
                    state->PaperCount++;
                    state->RockCount--;
                } else if(collide->type == Scissors){
                    state->Blocks[i]->type = Scissors;
                    state->ScissorsCount++;
                    state->PaperCount--;
                }
            } 
            else if(state->Blocks[i]->type == Scissors){
                if(collide->type == Paper){
                    collide->type = Scissors;
                    state->ScissorsCount++;
                    state->PaperCount--;
                } else if(collide->type == Rock){
                    state->Blocks[i]->type = Rock;
                    state->RockCount++;
                    state->ScissorsCount--;
                }
            }
        }
        move(state->Blocks[i]);
    }
}

void state_destroy(State state){
    for(int i = 0; i < state->totalCount; i++){
        block_destroy(state->Blocks[i]);
    }
    free(state->Blocks);
    free(state);
}