﻿#pragma once
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
   
}

void Game::ProcessInput() {
    
}