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