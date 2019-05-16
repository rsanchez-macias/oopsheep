#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Game.h"

// Adding new stuff by Francesco
#include "vector"
#include "iterator"
#include <ctime>
#include <cstdlib>

Game::Game(){

    player1 = new Player("../cutecat.jpg", -0.40, 0.0, 0.2, 0.2, 101, 102, 103, 100, true, 0,0.001);
    actors.push_back(player1);

    player2 = new Player("../pikachu.png", 0.20, 0.0, 0.2, 0.2, 119, 100, 115, 97, true, actors.size(), 0.001);
    actors.push_back(player2);

    startButton = new TexRect("../start.png", -0.55, 0.0, 0.4, 0.2);
    title = new TexRect("../title.png", -0.75, 0.5, 1.5, 0.2);
    optionButton = new TexRect("../options.png", 0.15, 0.0, 0.4, 0.2);

    fence1 = new Fence("../fence1.png", -1.5, 0.5, 0.7, 1.0);
    fence2 = new Fence("../fence2.png", 0.80, 0.5, 0.7, 1.0);
    
    inMenu = true;
    inGame = false;
    inOver = false;
    inOptions = false;

    blueScreen = new TexRect("../filler.png", -1.80, 1.0, 4.0, 2.0);
    rightBlock = new Rect(-1.80, 1.0, 0.30, 2.0, 0.0, 0.0, 0.0);
    leftBlock = new Rect(1.50, 1.0, 0.30, 2.0, 0.0, 0.0, 0.0);

    // Adding flock 
    flockS = 10;

    for(int i = 0; i < flockS; i ++) {
        flock.push_back(new Sheep("../sheep.png", 0.5-(0.1 * i),0.5-(0.1 * i), 0.1, 0.1, true, actors.size(), 0.002));
        actors.push_back(flock[i]);
    }

    setRate(1);
    start();
}

void Game::action(){
    if(inGame) {
       
        player1->action(actors);
        player2->action(actors);
        
        // Adding new stuff
        for (int i = 0; i < flockS; i ++){
            flock[i]->action(actors);
        }
    }
}

void Game::draw() const {
    rightBlock->draw();
    leftBlock->draw();
    if(inGame) {
        glClearColor(0.6, 0.6, 0.3, 1.0);
        player1->draw(0.0);
        player2->draw(0.0);
        fence1->draw(0.0);
        fence2->draw(0.0);
        
        // Adding new stuff
        for (int i = 0; i < flockS; i ++){
            flock[i]->draw(0.0);
        }
    }
    if(inMenu) {
        glClearColor(0.9, 0.9, 0.9, 1.0);
        startButton->draw(0.0);
        optionButton->draw(0.0);
        title->draw(0.0);
    }    
    if(inOptions) {
        blueScreen->draw(0.0);
    }
}

void Game::handleKeyDown(unsigned char key, float x, float y){
    if (key == 61){
        inMenu = true;
        inGame = false;
        inOver = false;
        inOptions = false;
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

void Game::handleSpecialKeyDown(int key, float x, float y) {
    if(key >= 100 && key <= 103) {
        player1->move(key);
    }
}

void Game::handleKeyUp(unsigned char key, float x, float y) {
    if(key == 119 || key == 100 || key == 115 || key == 97) {
        player2->stop(key);
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
        if(optionButton->contains(x, y)) {
            inMenu = false;
            inOptions = true;
        }
    }
}

Game::~Game(){
    delete player1;
    delete player2;
    delete startButton;
    delete optionButton;

    for(vector<Sheep*>::iterator i = flock.begin(); i != flock.end(); i++)
        delete *i;

    stop();
}
