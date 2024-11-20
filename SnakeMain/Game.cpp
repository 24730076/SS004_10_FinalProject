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

