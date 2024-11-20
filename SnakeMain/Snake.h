#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    std::vector<std::pair<int, int>> body;
    Direction direction;
    bool isGrowing;

public:
    Snake(int startX, int startY);
};

#endif // SNAKE_H
