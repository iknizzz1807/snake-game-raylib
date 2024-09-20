#include "Snake.h"
#include "raylib.h"

Snake::Snake(int initialLength, int gridSize) : gridSize(gridSize), growFlag(false), initialLength(initialLength) {
	init();
}

void Snake::init() {
	body.clear();
	direction = { 1, 0 }; // The game starts with the snake moving to the right
	for (int i = 0; i < initialLength; i++) {
		body.push_back({ (float)(-(gridSize * i + gridSize)), (float)(gridSize * 3) });
	}
}

void Snake::Move() {
	// The movement of the snake is just simply, for each time it moves,
	// remove its tail, add one more on its head based on the move direction
	Vector2 newHead = {
		body[0].x + direction.x * gridSize,
		body[0].y + direction.y * gridSize
	};

	body.insert(body.begin(), newHead);

	if (!growFlag) {
		body.pop_back(); // Remove its tail
	}
	else {
		growFlag = false; // If it needs to grow up, do not remove its tail
	}
}

void Snake::Grow() {
	growFlag = true;
}

bool Snake::CheckCollision() {
	// This checks collision whether its head touches its body
	for (int i = 1; i < body.size(); i++) {
		if (body[i].x == body[0].x && body[i].y == body[0].y) {
			return true;
		}
	}
	return false;
}

Vector2 Snake::GetHeadPosition() {
	return body[0];
}

void Snake::Draw() {
	for (auto& segment : body) {
		DrawRectangleV(segment, { (float)gridSize, (float)gridSize }, GREEN);
	}
}

void Snake::ChangeDirection(Vector2 newDir) {
	if ((direction.x + newDir.x != 0) || (direction.y + newDir.y != 0)) {
		direction = newDir;
	}
}
