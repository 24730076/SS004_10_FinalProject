﻿#include "Food.h"

Food::Food(int gameWidth, int gameHeight) : width(gameWidth), height(gameHeight) {
    srand(static_cast<unsigned>(time(0)));
    x = rand() % width;
    y = rand() % height;
}

void Food::GenerateNewPosition(const std::vector<std::pair<int, int>>& snakeBody) {
    
}

std::pair<int, int> Food::GetPosition() const {
    return { x, y };
}