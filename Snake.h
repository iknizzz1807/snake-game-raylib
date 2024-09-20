#pragma once
#include <vector>
#include "raylib.h"

class Snake
{
private:
	std::vector<Vector2> body;
	Vector2 direction;
	int gridSize; // This means how many grid it will move per movement
	bool growFlag;
	int initialLength;
public:
	Snake(int intialLength, int gridSize);
	void init();
	void Move();
	void Grow();
	void ChangeDirection(Vector2 newDir);
	bool CheckCollision();
	Vector2 GetHeadPosition();
	void Draw();
};

