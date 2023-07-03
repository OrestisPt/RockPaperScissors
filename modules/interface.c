#include "interface.h"
#include "raylib.h"
#include "Canvas.h"

void interface_init() {
	// Αρχικοποίηση του παραθύρου
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RockPaperScissors");
	SetTargetFPS(60);
    InitAudioDevice();
}

void interface_close() { 
	CloseAudioDevice();
	CloseWindow();
}

void interface_draw_frame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}