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

public:
    Actor(const char* filename, float x, float y, float w, float h, bool doesMove, int index,  float speed = 0.001);

    // Leave it for now :) Convention
    void setD(bool);
    void setU(bool);
    void setR(bool);
    void setL(bool);

    bool getD() const;
    bool getU() const;
    bool getR() const;
    bool getL() const;

    int getSpeed() const {return speed;}

    virtual void move(){};
    void checkCollision(Actor* act);

    ~Actor();

};

#endif