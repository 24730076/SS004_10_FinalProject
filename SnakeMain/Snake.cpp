#pragma once
#include "Snake.h"

Snake::Snake(int startX, int startY) : direction(RIGHT), isGrowing(false) {
	body.push_back({ startX, startY });
}
