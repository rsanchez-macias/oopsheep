#ifndef S_H
#define S_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "Actor.h"

using namespace std;

class Sheep: public Actor {

    int dirX, dirY;
    int counter = 0;

    time_t t;

    int timer = 100;

public:

    Sheep(const char* filename, float x, float y, float w, float h, bool doesMove);
    
    void rmove();
    void action();
};

#endif