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
    void Move();
    void Grow();
    bool CheckCollision(int maxWidth, int maxHeight);
    void SetDirection(Direction newDirection);
	Direction GetDirection() const;
    std::pair<int, int> GetHeadPosition() const;
    const std::vector<std::pair<int, int>>& GetBody() const;
};

#endif // SNAKE_H