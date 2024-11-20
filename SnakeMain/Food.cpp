﻿#include "Food.h"

Food::Food(int gameWidth, int gameHeight) : width(gameWidth), height(gameHeight) {
    
}

void Food::GenerateNewPosition(const std::vector<std::pair<int, int>>& snakeBody) {
    
}

std::pair<int, int> Food::GetPosition() const {
    return { x, y };
}