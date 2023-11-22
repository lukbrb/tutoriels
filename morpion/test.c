#include "raylib/src/raylib.h"

int main(void){
    InitWindow(600, 800, "Ma fenetre raylib");

    while (! WindowShouldClose()){
        BeginDrawing();
        EndDrawing();
    }
}