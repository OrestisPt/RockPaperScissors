#include <stdio.h>
#include "raylib.h"
#include "interface.h"
#include "state.h"
#include "Canvas.h"

State state;
bool is_over = false;
int winner = -1;

void update_and_draw() {
    is_over = state_is_over(state);
    if(!is_over){
        state_update(state);
        interface_draw_frame(state);
    } else {
        BeginDrawing();
        ClearBackground(BLACK);
        if(winner == -1)
            winner = getwinner(state);
        if(winner == Rock){
            int size = MeasureText("Rock Won!", 20);
            DrawText("Rock Won!", (SCREEN_WIDTH-size)/2, SCREEN_HEIGHT/2, 20, WHITE);
        }
        else if(winner == Paper){
            int size = MeasureText("Paper Won!", 20);
            DrawText("Paper Won!", (SCREEN_WIDTH-size)/2, SCREEN_HEIGHT/2, 20, WHITE);
        }
        else if(winner == Scissors){
            int size = MeasureText("Scissors Won!", 20);
            DrawText("Scissors Won!", (SCREEN_WIDTH-size)/2, SCREEN_HEIGHT/2, 20, WHITE);
        }
        int size = MeasureText("Press ESC to Exit", 20);
        DrawText("Press ESC to Exit", (SCREEN_WIDTH-size)/2, SCREEN_HEIGHT/2+50, 20, WHITE);
        EndDrawing();
    }
}

int main() {
    interface_init();
    state = state_create(30);
	
    while (!WindowShouldClose()) {
        update_and_draw();
    }
    state_destroy(state);
    interface_close();
}