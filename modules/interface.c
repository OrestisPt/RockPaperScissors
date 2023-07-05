#include "interface.h"
#include "raylib.h"
#include "Canvas.h"

Texture2D RockTexture;
Texture2D PaperTexture;
Texture2D ScissorsTexture;

void interface_init() {
	// Αρχικοποίηση του παραθύρου
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RockPaperScissors");
	SetTargetFPS(60);
    InitAudioDevice();
	RockTexture = LoadTexture("assets/rock.png");
	PaperTexture = LoadTexture("assets/Paper.png");
	ScissorsTexture = LoadTexture("assets/scissors.png");
}

void interface_close() { 
	CloseAudioDevice();
	CloseWindow();
}

void interface_draw_frame(State state) {
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
	for(int i = 0; i < state->totalCount; i++) {
		if(state->Blocks[i]->type == Rock) {
			DrawTexture(RockTexture, state->Blocks[i]->x, state->Blocks[i]->y, WHITE);
		} else if(state->Blocks[i]->type == Paper) {
			DrawTexture(PaperTexture, state->Blocks[i]->x, state->Blocks[i]->y, WHITE);
		} else if(state->Blocks[i]->type == Scissors) {
			DrawTexture(ScissorsTexture, state->Blocks[i]->x, state->Blocks[i]->y, WHITE);
		}
	}
	if(state->paused){
		int size = MeasureText("Paused", 100);
		DrawText("Paused", (SCREEN_WIDTH-size)/2, SCREEN_HEIGHT/2 - 70, 100, BLACK);
	}
    EndDrawing();
}