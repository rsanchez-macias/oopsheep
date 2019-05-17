#ifndef S_H
#define S_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <vector>
#include "Actor.h"

using namespace std;


class Sheep: public Actor {

    int counter = 0;
    time_t t;
    int timer = 100;

    bool inside;


public:

    Sheep(const char* filename, float x, float y, float w, float h, bool doesMove, int index, float speed);
    
    void move();
    void action(std::vector<Actor*> actors);

    // Flags are used to tell whether the sheep
    // got inside a net or not
    bool getIn() const;
    void setIn(bool inside);
};

#endif