#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Player.h"
#include "TexRect.h"
#include "Fence.h"
#include "Rect.h"

// Adding new libraries
#include "vector"
#include "Sheep.h"
#include "iterator"
#include <ctime>
#include <cstdlib>

using namespace std;


class Game: public AppComponent, private Timer{
    
    std::vector<Actor*> actors;
    int actorsS;

    Player* player1;
    Player* player2;


    TexRect* startButton;
    TexRect* title;
    TexRect* optionButton;

    Fence* fence1;
    Fence* fence2;

    TexRect* blueScreen;


    Rect* leftBlock;
    Rect* rightBlock;

    bool inMenu;
    bool inOptions;
    bool inGame;
    bool inOver;

    // Adding flock
    std::vector<Sheep*> flock;
    int flockS;

    

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
