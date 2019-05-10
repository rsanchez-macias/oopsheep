#ifndef PL_H
#define PL_H

#include <iostream>
#include "TexRect.h"

class Player: public TexRect {

    bool up, down, left, right;

public:

   // Player(float x, float y, float w, float h, float r, float g, float b);
    Player::Player(const char* filename, float x, float y, float w, float h): TexRect(filename, x, y, w, h) {
        up = false;
        down = false;
        left = false;
        right = false;

        std::cout << "Hello" << std::endl;
    }

    void move(int key) {
        if(key == 100) {
            std::cout << "Here" << std::endl;
            x -= 0.001;
            left = true;
        }
        if(key == 101) {
            up = true;
        }
        if(key == 102) {
            right = true;
        }
        if(key == 103) {
            down = true;
        }
    };

    void stop(int key) {
        if(key == 100) {
            std::cout << "Here" << std::endl;
            left = false;
        }
        if(key == 101) {
            up = false;
        }
        if(key == 102) {
            right = false;
        }
        if(key == 103) {
            down = false;
        }
    };

    void action() {
        if(left) {
            x -= 0.001;
        }
        if(right) {
            x += 0.001;
        }
        if(up) {
            y += 0.001;
        }
        if(down) {
            y -= 0.001;
        }
    }

};

#endif