#ifndef Act_h
#define Act_h

#include "TexRect.h"
#include <cmath>

class Actor: public TexRect {
protected:
    bool doesMove;
    int up, down, right, left;

    int dirX, dirY;
    float speed;
    int index;

    bool hit;

public:
    Actor(const char* filename, float x, float y, float w, float h, bool doesMove, int index,  float speed = 0.001);

    void setHit(bool hit);
    bool getHit() const;

    int getSpeed() const {return speed;}

    virtual void move(){};
    void checkCollision(Actor* act);

    // May become private methods
    void checkBorderCollision(Actor* act);

    ~Actor();

};

#endif