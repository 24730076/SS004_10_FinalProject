#include "Food.h"

Food::Food(int gameWidth, int gameHeight) : width(gameWidth), height(gameHeight) {
    srand(static_cast<unsigned>(time(0)));
    GenerateNewPosition();
}

void Food::GenerateNewPosition() {
    x = rand() % width;
    y = rand() % height;
}

std::pair<int, int> Food::GetPosition() const {
    return { x, y };
}
