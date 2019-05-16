#ifndef Act_h
#define Act_h

#include "TexRect.h"
#include <cmath>

class Actor: public TexRect {
protected:
    bool doesMove;
    int up, down, right, left;

public:
    Actor(const char* filename, float x, float y, float w, float h, bool doesMove);

    // Leave it for now :) Convention
    void setD(bool);
    void setU(bool);
    void setR(bool);
    void setL(bool);

    bool getD() const;
    bool getU() const;
    bool getR() const;
    bool getL() const;

    void checkCollision(Actor* act);

    ~Actor();

};

#endif