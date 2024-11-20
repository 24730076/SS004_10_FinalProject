#ifndef FOOD_H
#define FOOD_H

#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>

class Food {
private:
    int x, y;
    int width, height;

public:
    Food(int gameWidth, int gameHeight);
};

#endif
