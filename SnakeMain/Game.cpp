#pragma once
#include "Game.h"
#include <windows.h>

Game::Game(int gameWidth, int gameHeight)
    : snake(gameWidth / 2, gameHeight / 2), food(gameWidth, gameHeight),
    width(gameWidth), height(gameHeight), score(0), isRunning(false) {}

void Game::Init() {
    system("cls");
    score = 0;
    isRunning = true;
}

void Game::Update() {
    snake.Move();

    if (snake.GetHeadPosition() == food.GetPosition()) {
        snake.Grow();
        food.GenerateNewPosition();
        score += 10;
    }

    if (snake.CheckCollision(width, height)) {
        isRunning = false;
    }
}

void Game::Render() {
    system("cls");

    for (int x = 0; x < width + 2; ++x) {
        std::cout << "#";
    }
    std::cout << "\n";

    for (int y = 0; y < height; ++y) {
        std::cout << "#"; 

        for (int x = 0; x < width; ++x) {
            bool printed = false;

            if (snake.GetHeadPosition() == std::make_pair(x, y)) {
                std::cout << "O";
                printed = true;
            }
            // Vẽ thân rắn
            else {
                for (const auto& segment : snake.GetBody()) {
                    if (segment == std::make_pair(x, y)) {
                        std::cout << "o";
                        printed = true;
                        break;
                    }
                }
            }

            
            if (food.GetPosition() == std::make_pair(x, y)) {
                std::cout << "F";
                printed = true;
            }

            if (!printed) {
                std::cout << " ";
            }
        }

        std::cout << "#\n";
    }

    for (int x = 0; x < width + 2; ++x) {
        std::cout << "#";
    }
    std::cout << "\n";

    std::cout << "Score: " << score << "\n";
}

void Game::Run() {
    while (isRunning) {
        ProcessInput();
        Update();
        Render();
        Sleep(1000);
    }
    std::cout << "Game Over! Your Score: " << score << "\n";
}

void Game::ProcessInput() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w': snake.SetDirection(UP); break;
        case 's': snake.SetDirection(DOWN); break;
        case 'a': snake.SetDirection(LEFT); break;
        case 'd': snake.SetDirection(RIGHT); break;
        }
    }
}
