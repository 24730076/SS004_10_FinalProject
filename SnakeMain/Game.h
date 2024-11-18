#pragma once
#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

class Game {
private:
    Snake snake;
    Food food;
    int width, height;
    int score;
    bool isRunning;
    std::pair<int, int> lastTail;
    bool isFast;
    bool isPaused;
public:
    Game(int gameWidth, int gameHeight);
    void Init();
    void Update();
    void Render();
    void Run();
    void ProcessInput();
    void ShowMenu();
    void ViewScore();
};

void GotoXY(int x, int y);
#endif // GAME_H
