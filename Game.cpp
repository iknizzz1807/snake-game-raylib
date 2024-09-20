#include "Game.h"
#include <cstdlib>
#include <iostream>

Game::Game(int gridSize, int initialSnakeLength, int screenWidth, int screenHeight)
    : gridSize(gridSize), snake(initialSnakeLength, gridSize), screenWidth(screenWidth), screenHeight(screenHeight) {
    Init();
}

void Game::Init() {
    snake.init();
    isGameOver = false;
    foodPosition = {
        (float)(rand() % (screenWidth / gridSize)) * gridSize,
        (float)(rand() % (screenHeight / gridSize)) * gridSize
    };
}

void Game::Update() {
    if (!isGameOver) {

        if (IsKeyPressed(KEY_D)) snake.ChangeDirection({ 1, 0 });
        if (IsKeyPressed(KEY_A)) snake.ChangeDirection({ -1, 0 });
        if (IsKeyPressed(KEY_W)) snake.ChangeDirection({ 0, -1 });
        if (IsKeyPressed(KEY_S)) snake.ChangeDirection({ 0, 1 });

        snake.Move();

        CheckFoodCollision();

        if (snake.CheckCollision()) {
            GameOver();
        }

        Vector2 head = snake.GetHeadPosition();
        if (head.x < 0 || head.y < 0 || head.x >= screenWidth || head.y >= screenHeight) {
            GameOver();
        }
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangleV(foodPosition, { (float)gridSize, (float)gridSize }, RED);

    snake.Draw();

    if (isGameOver) {
        DrawText("GAME OVER", screenWidth / 2 - 100, screenHeight / 2, 40, WHITE);
        DrawText("Press [R] to Restart", screenWidth / 2 - 100, screenHeight / 2 + 50, 20, WHITE);
        if (IsKeyPressed(KEY_R)) {
            Init();
        }
    }

    EndDrawing();
}

void Game::CheckFoodCollision() {
    Vector2 head = snake.GetHeadPosition();
    if (head.x == foodPosition.x && head.y == foodPosition.y) {
        snake.Grow();

        foodPosition = {
            (float)(rand() % (screenWidth / gridSize)) * gridSize,
            (float)(rand() % (screenHeight / gridSize)) * gridSize
        };
    }
}

void Game::GameOver() {
    isGameOver = true;
}