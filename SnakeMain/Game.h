#pragma once
#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <iostream>
#include <conio.h> // Cho _kbhit() và _getch()

class Game {
private:
    Snake snake;
    Food food;
    int width, height;
    int score;
    bool isRunning;

public:
    Game(int gameWidth, int gameHeight);
    void Init();
    void Update();
    void Render();
    void Run();
    void ProcessInput();
};

#endif // GAME_H
