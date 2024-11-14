#pragma once
#include "Snake.h"

Snake::Snake(int startX, int startY) : direction(RIGHT), isGrowing(false) {
	body.push_back({ startX, startY });
}

void Snake::Move() {
	int headX = body[0].first;
	int headY = body[0].second;

	switch (direction) {
	case UP:    headY--; break;
	case DOWN:  headY++; break;
	case LEFT:  headX--; break;
	case RIGHT: headX++; break;
	}

	body.insert(body.begin(), { headX, headY });
	if (!isGrowing) {
		body.pop_back();
	}
	isGrowing = false;
}

void Snake::Grow() {
	isGrowing = true;
}

bool Snake::CheckCollision(int maxWidth, int maxHeight) {
	int headX = body[0].first;
	int headY = body[0].second;

	if (headX < 0 || headX >= maxWidth || headY < 0 || headY >= maxHeight) return true;

	for (size_t i = 1; i < body.size(); ++i) {
		if (body[i] == body[0]) return true;
	}
	return false;
}

void Snake::SetDirection(Direction newDirection) {
	direction = newDirection;
}

std::pair<int, int> Snake::GetHeadPosition() const {
	return body[0];
}

const std::vector<std::pair<int, int>>& Snake::GetBody() const {
	return body;
}
