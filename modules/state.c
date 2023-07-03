#include "state.h"
#include "Block.h"
#include <stdlib.h>

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
        move(state->Blocks[i]);
    }
}