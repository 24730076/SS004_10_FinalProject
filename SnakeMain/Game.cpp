#pragma once
#include "Game.h"
#include <windows.h>
#include <algorithm>
#include <iostream>
void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Game::Game(int gameWidth, int gameHeight)
    : snake(gameWidth / 2, gameHeight / 2), food(gameWidth, gameHeight),
    width(gameWidth), height(gameHeight), score(0), isRunning(false) {}

void Game::ShowMenu() {
    int choice;
    do {
        system("cls");
        std::cout << "1. New Game\n";
        std::cout << "2. Resume\n";
        std::cout << "3. View Score\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            Init();
            Run();
            break;
        case 2:
            if (isPaused) {
                isRunning = true;
                Run();
            }
            else {
                std::cout << "No game to resume.\n";
                system("pause");
            }
            break;
        case 3:
            ViewScore();
            break;
        case 4:
            isRunning = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            system("pause");
        }
    } while (choice != 4);
}

void Game::ViewScore() {
    system("cls");
    std::cout << "Current Score: " << score << "\n";
    system("pause");
}

void Game::Init() {
    system("cls");
    score = 0;
    isRunning = true;

    system("cls");

    for (int x = 0; x < width + 2; ++x) {
        std::cout << "#";
    }
    std::cout << "\n";

    for (int y = 0; y < height; ++y) {
        std::cout << "#";
        for (int x = 0; x < width; ++x) {
            std::cout << " ";
        }
        std::cout << "#\n";
    }

    for (int x = 0; x < width + 2; ++x) {
        std::cout << "#";
    }
    std::cout << "\n";
}

void Game::Update() {
    lastTail = snake.GetBody().back();

    snake.Move();

    if (snake.GetHeadPosition() == food.GetPosition()) {
        snake.Grow();
        food.GenerateNewPosition(snake.GetBody());
        score += 10;
    }

    if (snake.CheckCollision(width, height)) {
        isRunning = false;
    }
}

void Game::Render() {
    GotoXY(lastTail.first + 1, lastTail.second + 1); // +1 để bù viền
    std::cout << " ";

    auto head = snake.GetHeadPosition();
    GotoXY(head.first + 1, head.second + 1);
    std::cout << "O";

    const auto& body = snake.GetBody();
    for (size_t i = 1; i < body.size(); ++i) {
        auto segment = body[i];
        GotoXY(segment.first + 1, segment.second + 1);
        std::cout << "o";
    }
    auto foodPos = food.GetPosition();
    GotoXY(foodPos.first + 1, foodPos.second + 1);
    std::cout << "F";

    GotoXY(0, height + 3);
    std::cout << "Score: " << score << "\n";
}

void Game::Run() {
    Init();

    while (isRunning) {
        ProcessInput();
        Update();
        Render();
        int snakeLength = snake.GetBody().size();
        int sleepDuration = max(50, 1000 - (snakeLength * 10));

        if (isFast) {
            Sleep(sleepDuration / 10);
            isFast = false;
        }
        else {
            Sleep(sleepDuration);
        }
    }

    GotoXY(0, height + 5);
    std::cout << "Game Over! Your Score: " << score << "\n";
}

void Game::ProcessInput() {
    if (_kbhit()) {
        char input = _getch();
        switch (input) {
        case 'w':
            if (snake.GetDirection() == UP) {
                isFast = true;
            }
            else {
                snake.SetDirection(UP);
                isFast = false;
            }
            break;
        case 's':
            if (snake.GetDirection() == DOWN) {
                isFast = true;
            }
            else {
                snake.SetDirection(DOWN);
                isFast = false;
            }
            break;
        case 'a':
            if (snake.GetDirection() == LEFT) {
                isFast = true;
            }
            else {
                snake.SetDirection(LEFT);
                isFast = false;
            }
            break;
        case 'd':
            if (snake.GetDirection() == RIGHT) {
                isFast = true;
            }
            else {
                snake.SetDirection(RIGHT);
                isFast = false;
            }
            break;
        case 27:
            isPaused = true;
            isRunning = false;
            break;
        }

    }
}