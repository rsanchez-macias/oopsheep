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

Game::Game(){
     
    player1 = new Player("../player1.jpg", 0.80, 0.0, 0.2, 0.2, 101, 102, 103, 100, false, 0,0.001);
    actors.push_back(player1);

    player2 = new Player("../player2.png", -1.0, 0.0, 0.2, 0.2, 119, 100, 115, 97, false, actors.size(), 0.001);
    actors.push_back(player2);

     // Adding flock 
    flockS = 10;

    for(int i = 0; i < flockS; i ++) {
        flock.push_back(new Sheep("../sheep.png", 0.7-(0.2 * i), 0.8-(0.2 * i), 0.1, 0.1, true, actors.size(), 0.0008));
        actors.push_back(flock[i]);
    }

    net1 = new Net("../net.png", -1.5, 0.4, 0.35, 0.8, true);
    net2 = new Net("../net.png", 1.15, 0.4, 0.35, 0.8, false);


    topWall1 = new Actor("../sideFence.png", -1.5, 0.5, 0.4, 0.1, false, actors.size(), 0.0);
    actors.push_back(topWall1);
    
    bottomWall1 = new Actor("../sideFence.png", -1.5, -0.4, 0.4, 0.1, false, actors.size(), 0.0);
    actors.push_back(bottomWall1);

    topWall2 = new Actor("../sideFence.png", 1.1, 0.5, 0.4, 0.1, false, actors.size(), 0.0);
    actors.push_back(topWall2);
    
    bottomWall2 = new Actor("../sideFence.png", 1.1, -0.4, 0.4, 0.1, false, actors.size(), 0.0);
    actors.push_back(bottomWall2);


    // Menu flags
    inMenu = true;
    inGame = false;
    inOver = false;
    inOptions = false;

    // Main Menu
    startButton = new TexRect("../start.png", -0.55, 0.0, 0.4, 0.2);
    title = new TexRect("../title.png", -0.75, 0.5, 1.5, 0.2);
    optionButton = new TexRect("../help.png", 0.15, 0.0, 0.4, 0.2);

    // In Game objects
    bg = new TexRect("../grass.png", -1.5, 1.0, 3.0, 2);

    // End Menu 
    returnToMenu = new TexRect("../return.png", -0.1, 0.3, 0.4, 0.2);
    startAgain = new TexRect("../playAgain.png", -0.1, -0.1, 0.4, 0.2);
    winnerMsg = new TextBox("", -0.15, 0.5, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0, 800);

    // Help Menu
    helpMenu = new TexRect("../helpMenu.png", -1.50, 1.0, 3.0, 2.0);
    backButton = new TexRect("../back.png", -1.0, 0.7, 0.4, 0.2);

    // Blocks on the side of the screen to display scores
    rightBlock = new Rect(-1.80, 1.0, 0.30, 2.0, 0.0, 0.0, 0.0);
    leftBlock = new Rect(1.50, 1.0, 0.30, 2.0, 0.0, 0.0, 0.0);


    setRate(1);
    start();
}

void Game::action(){
    if(inGame) {
       
        player1->action(actors);
        player2->action(actors);
        
        
        for (int i = 0; i < flockS; i ++){
            if(!flock[i]->getIn())
                flock[i]->action(actors);
        }

        net1->action(flock);
        net2->action(flock);    

        // Checking to see if the game is over
        if(net1->getTotal() == 5 || net2->getTotal() == 5) {
            inGame = false;
            inOver = true;
            if(net1->getTotal() == 5) winnerMsg->changeText("Player 2 has won!!!!!!");
            else winnerMsg->changeText("Player 1 has won!!!!!!");
        }
    }
}


void Game::draw() const {
    rightBlock->draw();
    leftBlock->draw();

    if(inGame) {
        // Change the background color when in the game
        glClearColor(0.6, 0.6, 0.3, 1.0);

        bg->draw(0.0);

        player1->draw(0.2);
        player2->draw(0.2);
        
        // Displaying the sheep
        for (int i = 0; i < flockS; i ++){
            if(!flock[i]->getIn())
                flock[i]->draw(0.2);
        }

        // Displaying each fence
        topWall1->draw(0.2);
        bottomWall1->draw(0.2);
        topWall2->draw(0.2);
        bottomWall2->draw(0.2);

        net1->draw(0.1);
        net2->draw(0.1);

    }

    if(inMenu) {
        glClearColor(0.9, 0.9, 0.9, 1.0);
        startButton->draw(0.0);
        optionButton->draw(0.0);
        title->draw(0.0);
    }    

    if(inOptions) {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        backButton->draw(0.1);
        helpMenu->draw(0.0);
    }

    if(inOver) {
        winnerMsg->draw();
        startAgain->draw(0.0);
        returnToMenu->draw(0.0);
    }
}

void Game::resetGame() {

    net1->resetPoints();
    net2->resetPoints();

    player1->setX(0.80);
    player1->setY(0.0);
    player2->setX(-1.0);
    player2->setY(0.0);

    for(int i = 0; i < flockS; i ++) {
        flock[i]->setX(0.7-(0.15 * i));
        flock[i]->setY(0.8-(0.1 * i));
        flock[i]->setIn(false);
        flock[i]->setHit(false);
    }
}

void Game::handleKeyDown(unsigned char key, float x, float y){
    // If player presses (=/+) key, the games get resetted to its original state
    if (key == 61){
        inMenu = true;
        inGame = false;
        inOver = false;
        inOptions = false;

        resetGame();
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
    if(inOver) {
        if(startAgain->contains(x, y)) {
            inMenu = false;
            inGame = true;
            inOver = false;
            inOptions = false;

            resetGame();
        }

        if(returnToMenu->contains(x, y)) {
            inMenu = true;
            inGame = false;
            inOver = false;
            inOptions = false;

            resetGame();
        }
    }
    if(inOptions) {
        if(backButton->contains(x - 0.45, y + 0.08)) {
            inMenu = true;
            inOptions = false;
            inOver = false;
            inGame = false;
        }
    }
}

Game::~Game(){
    delete player1;
    delete player2;

    delete net1;
    delete net2;

    delete topWall1;
    delete bottomWall1;
    delete topWall2;
    delete bottomWall2;

    delete returnToMenu;
    delete startAgain;
    delete winnerMsg;
    delete startButton;
    delete optionButton;

    delete rightBlock;
    delete leftBlock;

    delete bg;
    delete helpMenu;
    delete backButton;

    for(vector<Sheep*>::iterator i = flock.begin(); i != flock.end(); i++)
        delete *i;

    for(vector<Actor*>::iterator i = actors.begin(); i != actors.end(); i++)
        delete *i;

    stop();
}
