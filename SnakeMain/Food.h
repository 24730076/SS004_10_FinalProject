#ifndef FOOD_H
#define FOOD_H

#include <utility>
#include <cstdlib>
#include <ctime>

class Food {
private:
    int x, y;
    int width, height;

public:
    Food(int gameWidth, int gameHeight);

    void GenerateNewPosition();

    std::pair<int, int> GetPosition() const;
};

#endif
