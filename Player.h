#ifndef Player_h
#define Player_h

#include <cmath>
#include <iostream>
#include "Actor.h"
#include <vector>
#include "Rect.h"

class Player: public Actor {

        int upK, downK, leftK, rightK;


public:
        Player(const char* filename, float x, float y, float w, float h, 
                int upK, int rightK, int downK, int leftK, bool doesMove, int index, float speed);

        void move(int key);
        void stop(int key);
        void action(std::vector<Actor*> actors);
};

#endif
