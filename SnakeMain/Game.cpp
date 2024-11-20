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
    
}

void Game::Init() {
   
}

void Game::Update() {
    
}

void Game::Render() {
    
}

void Game::Run() {
   
}

void Game::ProcessInput() {
    
}