#include <stdio.h>
#include "raylib.h"
#include "interface.h"
#include "state.h"

State state;

void update_and_draw() {
    interface_draw_frame(state);
}

int main() {
    interface_init();
    state = state_create(5);
 
	start_main_loop(update_and_draw);

    interface_close();
}