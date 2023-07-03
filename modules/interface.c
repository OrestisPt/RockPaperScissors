#include "interface.h"
#include "raylib.h"

void interface_init() {
	// Αρχικοποίηση του παραθύρου
	InitWindow(800, 900, "RockPaperScissors");
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