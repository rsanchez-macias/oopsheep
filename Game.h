#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Player.h"
#include "TexRect.h"


class Game: public AppComponent, private Timer{
    Player* player1;
    Player* player2;

    TexRect* startButton;
    TexRect* title;
    TexRect* optionButton;

    TexRect* blueScreen;

    bool inMenu;
    bool inOptions;
    bool inGame;
    bool inOver;

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
