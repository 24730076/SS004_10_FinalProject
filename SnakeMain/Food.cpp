#include "Food.h"

Food::Food(int gameWidth, int gameHeight) : width(gameWidth), height(gameHeight) {
    srand(static_cast<unsigned>(time(0)));
    x = rand() % width;
    y = rand() % height;
}

void Food::GenerateNewPosition(const std::vector<std::pair<int, int>>& snakeBody) {
    bool isOnSnake;
    do {
        isOnSnake = false;
        x = rand() % width;
        y = rand() % height;
        for (const auto& segment : snakeBody) {
            if (segment.first == x && segment.second == y) {
                isOnSnake = true;
                break;
            }
        }
    } while (isOnSnake);
}

std::pair<int, int> Food::GetPosition() const {
    return { x, y };
}
