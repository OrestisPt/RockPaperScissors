#pragma once
#include "Block.h"
#include <stdbool.h>

typedef struct state *State;

struct state {
    int RockCount;
    int PaperCount;
    int ScissorsCount;
    int totalCount;
    Block* Blocks;
};

int getwinner(State state);

bool state_is_over(State state);

Block block_collide(State state, Block block);

State state_create(int n);

void state_update(State state);

void state_destroy(State state);