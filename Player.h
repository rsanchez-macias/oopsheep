#ifndef PL_H
#define PL_H

#include <cmath>
#include <iostream>
#include "TexRect.h"
#include "Fence.h"


class Player: public TexRect {

    // Members variables that support moving the player
    //bool up, down, left, right;
    int upK, downK, leftK, rightK;

public:
    bool up, down, left, right;

   // Player(float x, float y, float w, float h, float r, float g, float b);
    Player(const char* filename, float x, float y, float w, float h, int upK, int rightK, int downK, int leftK): TexRect(filename, x, y, w, h) {
        up = false;
        down = false;
        left = false;
        right = false;

        this->upK = upK;
        this->rightK = rightK;
        this->downK = downK;
        this->leftK = leftK;

    }

    void move(int key) {
        if(key == leftK) {
            left = true;
        }
        if(key == upK) {
            up = true;
        }
        if(key == rightK) {
            right = true;
        }
        if(key == downK) {
            down = true;
        }
    }

   // void stop(int key);
    void stop(int key) {
        if(key == leftK) {
            left = false;
        }
        if(key == upK) {
            up = false;
        }
        if(key == rightK) {
            right = false;
        }
        if(key == downK) {
            down = false;
        }
    }

    void action(TexRect* pl, TexRect* fence1, TexRect* fence2) {
        checkCollision(pl);
        checkCollision(fence1);
        checkCollision(fence2);

        if(left && x >= -1.5) {
            x -= 0.001;
        }
        if(right && (x + w) <= 1.5) {
            x += 0.001;
        }
        if(up && y <= 1) {
            y += 0.001;
        }
        if(down && (y - h - 0.1) >= -1) {
            y -= 0.001;
        }
    }

    /*
    Collision Detection :'( Could try to use it for sheep by making the parameter generic
    using a parent class pointer
    */

    void checkCollision(TexRect* pl) {
        float x = pl->getX(), y = pl->getY(), w = pl->getW(), h = pl->getH();
        
        if(
            (contains(x, y) && 
            abs(getX() + getW() - x) <= 0.005)
            || (contains(x, y - h) && 
            (abs(getX() + getW() - x) <= 0.005))
        ) {
                right = false;
        }

        if(
            (contains(x, y) && 
            abs(getY() - getH() - y) <= 0.005)
            || (contains(x + w, y) && 
            !(abs(x + w - getX()) <= 0.005))
        ) {
                down = false;
        }

        if(
            (contains(x + w, y) &&
            abs(x + w - getX()) <= 0.005)
            || (contains(x + w, y - h) &&
            !(abs(getY() - y + h) <= 0.005))
        ) {
                left = false;
        }

        if(
            (contains(x + w, y - h) && 
            abs(getY() - y + h) <= 0.005)
            || (contains(x, y - h) &&
            !(abs(getX() + getW() - x) <= 0.005))
        ) {
                up = false;
        }

    }

};

#endif