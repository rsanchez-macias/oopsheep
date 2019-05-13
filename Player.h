#ifndef PL_H
#define PL_H

#include <iostream>
#include "TexRect.h"

class Player: public TexRect {

    // Members variables that support moving the player
    bool up, down, left, right;
    int upK, downK, leftK, rightK;

public:

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

    void action() {
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

};

#endif