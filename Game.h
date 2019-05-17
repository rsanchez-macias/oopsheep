#ifndef Game_hpp
#define Game_hpp

#include <iterator>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "AppComponent.h"
#include "Timer.h"
#include "Player.h"
#include "TexRect.h"
#include "Net.h"
#include "Rect.h"
#include "Sheep.h"
#include "Actor.h"
#include "TextBox.h"

class Game: public AppComponent, private Timer{
    
    Player* player1;
    Player* player2;

    // Adding flock
    std::vector<Sheep*> flock;
    int flockS;

    // Vector used for collision detection
    std::vector<Actor*> actors;


    // Goals on each side of the screen 
    Net* net1;
    Actor* topWall1;
    Actor* bottomWall1;

    Net* net2;
    Actor* topWall2;
    Actor* bottomWall2;

    
    // Menu stuff
    bool inMenu;
    bool inOptions;
    bool inGame;
    bool inOver;
    
    // Main Menu objects
    TexRect* startButton;
    TexRect* title;
    TexRect* optionButton;

    // Left and right dark blocks to cover for space
    // throughtout the game. Scores are displayed on this space
    Rect* leftBlock;
    Rect* rightBlock;

    // In Game objects
    TexRect* bg;

    // In Help Menu
    TexRect* helpMenu;
    TexRect* backButton;

    // End Screen objects 
    TextBox* winnerMsg;
    TexRect* returnToMenu;
    TexRect* startAgain;


private:
    void resetGame();

public:
    Game();
    
    void draw() const;

    // Regular keyboar handling 
    void handleKeyDown(unsigned char, float, float);
    void handleKeyUp(unsigned char, float, float);
    
    // Special Keyboard Handling 
    void handleSpecialKeyDown(int, float, float);
    void handleSpecialKeyUp(int, float, float);

    // Mouse clicks
    virtual void handleLeftMouseDown(float, float);

    void action();

    ~Game();
};

#endif 
