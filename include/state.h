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

void state_update(State state);