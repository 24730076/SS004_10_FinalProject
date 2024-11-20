#pragma once
#include "Snake.h"

Snake::Snake(int startX, int startY) : direction(RIGHT), isGrowing(false) {
	body.push_back({ startX, startY });
}

void Snake::Move() {
	
}

void Snake::Grow() {
	
}

bool Snake::CheckCollision(int maxWidth, int maxHeight) {
	
}

void Snake::SetDirection(Direction newDirection) {
	
}

Direction Snake::GetDirection() const {
	return direction;
}

std::pair<int, int> Snake::GetHeadPosition() const {
	return body[0];
}

const std::vector<std::pair<int, int>>& Snake::GetBody() const {
	return body;
}