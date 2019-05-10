#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"

Game::Game(){

    player = new Player("sheep.png", 0.0, 0.0, 0.2, 0.2);
    
    setRate(1);
    start();
}

void Game::action(){
    player->action();
}

void Game::draw() const {
    player->draw(0.0);
}

void Game::handleKeyDown(unsigned char key, float x, float y){
    if (key == ' '){
        
    }
    else if (key == 'p'){
        stop();
    }
    else if (key == 'r'){
        start();
    }
}

void Game::handleSpecialKeyDown(int key, float x, float y) {
    if(key >= 100 && key <= 103) {
        player->move(key);
    }
}

void Game::handleSpecialKeyUp(int key, float x, float y) {
    if(key >= 100 && key <= 103) {
        player->stop(key);
    }
}

Game::~Game(){
    delete player;
    stop();
}
