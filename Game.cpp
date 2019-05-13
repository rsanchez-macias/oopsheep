#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"

Game::Game(){

    //Adding a player to the game
    player1 = new Player("../cutecat.jpg", 0.0, 0.0, 0.2, 0.2, 101, 102, 103, 100);
    player2 = new Player("../pikachu.png", 0.5, 0.5, 0.2, 0.2, 119, 100, 115, 97);

    startButton = new TexRect("../start.png", -0.55, 0.0, 0.4, 0.2);
    title = new TexRect("../title.png", -0.75, 0.5, 1.5, 0.2);
    optionButton = new TexRect("../options.png", 0.15, 0.0, 0.4, 0.2);
    
    inMenu = true;
    inGame = false;
    inOver = false;

    setRate(1);
    start();
}

void Game::action(){
    if(inGame) {
        player1->action();
        player2->action();
    }
}

void Game::draw() const {
    if(inGame) {
        player1->draw(0.0);
        player2->draw(0.0);
    }
    if(inMenu) {
        startButton->draw(0.0);
        optionButton->draw(0.0);
        title->draw(0.0);
    }    
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
    else if(key == 119 || key == 100 || key == 115 || key == 97) {
        player2->move(key);
    }
}

void Game::handleKeyUp(unsigned char key, float x, float y) {
    if(key == 119 || key == 100 || key == 115 || key == 97) {
        player2->stop(key);
    }
}

void Game::handleSpecialKeyDown(int key, float x, float y) {
    if(key >= 100 && key <= 103) {
        player1->move(key);
    }
}

void Game::handleSpecialKeyUp(int key, float x, float y) {
    if(key >= 100 && key <= 103) {
        player1->stop(key);
    }
}

void Game::handleLeftMouseDown(float x, float y) {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
    if(inMenu) {
        if(startButton->contains(x, y)) {
            inMenu = false;
            inGame = true;
        }
    }
}

Game::~Game(){
    delete player1;
    delete player2;
    delete startButton;
    delete optionButton;
    stop();
}
