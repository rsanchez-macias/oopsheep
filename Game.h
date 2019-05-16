#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Player.h"
#include "TexRect.h"
#include "Fence.h"
#include "Rect.h"
#include "vector"
#include "Sheep.h"
#include "iterator"
#include <ctime>
#include <cstdlib>
#include "Actor.h"


class Game: public AppComponent, private Timer{
    
    Player* player1;
    Player* player2;

    Fence* fence1;
    Fence* fence2;

    // Adding flock
    std::vector<Sheep*> flock;
    int flockS;

    std::vector<Actor*> actors;

    // Menu stuff
    bool inMenu;
    bool inOptions;
    bool inGame;
    bool inOver;
    
    TexRect* startButton;
    TexRect* title;
    TexRect* optionButton;

    Rect* leftBlock;
    Rect* rightBlock;
    TexRect* blueScreen;

    

public:
    Game();
    
    void draw() const;
    void handleKeyDown(unsigned char, float, float);
    void handleKeyUp(unsigned char, float, float);
    
    // Special Keyboard Handlign
    void handleSpecialKeyDown(int, float, float);
    void handleSpecialKeyUp(int, float, float);

    // Mouse clicks
    virtual void handleLeftMouseDown(float, float);

    void action();

    ~Game();
};

#endif 
