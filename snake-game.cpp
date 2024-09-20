#include "Game.h"
#include "raylib.h"

int main() {
    int screenWidth = 800;
    int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Snake Game");

    int gridSize = 20;
    Game game(gridSize, 5, screenWidth, screenHeight);

    SetTargetFPS(10);

    while (!WindowShouldClose()) {
        game.Update();
        game.Draw();
    }

    CloseWindow();
    return 0;
}
