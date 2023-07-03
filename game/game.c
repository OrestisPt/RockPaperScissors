#include <stdio.h>
#include "raylib.h"
#include "interface.h"

void update_and_draw() {
    interface_draw_frame();
}

int main() {
    interface_init();
 
	start_main_loop(update_and_draw);

    interface_close();
}