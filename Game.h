#pragma once
#include "raylib.h"
#include "Snake.h"
class Game
{
private:
	Snake snake;
	Vector2 foodPosition;
	int gridSize;
	int screenWidth, screenHeight;
	bool isGameOver;
public:
	Game(int gridSize, int initialSnakeLength, int screenWidth, int screenHeight);

	void Init();
	void Update();
	void Draw();
	void GameOver();
	void CheckFoodCollision();
};

