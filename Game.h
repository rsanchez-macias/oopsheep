#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Player.h"

class Game: public AppComponent, private Timer{
    Player* player;

public:
    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);
    
    // Special Keyboard Handlign
    void handleSpecialKeyDown(int, float, float);
    void handleSpecialKeyUp(int, float, float);

    void action();

    ~Game();

};

#endif 
