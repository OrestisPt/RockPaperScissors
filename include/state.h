#pragma once
#include <Block.h>


typedef struct state {
    int RockCount;
    int PaperCount;
    int ScissorsCount;
    int totalCount;
    Block* Blocks;
}* State;

State state_create(int n);

// void state_update(State state){
//     for(int i = 0; i < state->RockCount; i++){
//         move(state->Rocks[i]);
//         if()
//     }
//     for(int i = 0; i < state->PaperCount; i++){
//         move(state->Papers[i]);
//     }
//     for(int i = 0; i < state->ScissorsCount; i++){
//         move(state->Scissors[i]);
//     }
// }