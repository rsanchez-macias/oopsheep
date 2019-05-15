#ifndef S_H
#define S_H

#include <iostream>
#include "TexRect.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

class Sheep: public TexRect {

    bool up, down, left, right;
    int upK, downK, leftK, rightK;
    int dirX, dirY;
    int counter = 0;

    time_t t;

    int timer = 100;

    //THIS IS THE BUG
    //srand (time(NULL));

public:

   // Player(float x, float y, float w, float h, float r, float g, float b);
    Sheep(const char* filename, float x, float y, float w, float h, int upK, int rightK, int downK, int leftK): TexRect(filename, x, y, w, h) {
        up = false;
        down = false;
        left = true;
        right = false;

        this->upK = upK;
        this->rightK = rightK;
        this->downK = downK;
        this->leftK = leftK;
    }

    void rmove(){
        timer = 10;  
        
        up = false;
        down = false;
        left = false;
        right = false;

/*
        if ((x < -1 && y > 1) || (x > 1 && y < -1)){ 
            if (up){
                up = false;
                left = false;
                right = true;
                down = true;
            }
            else{
                up = true;
                left = true;
                right = false;
                down = false;
            }
        }
*/
        dirX = (rand() % 3);
        dirY = (rand() % 3);

        cout << "X : " << dirX << endl;
        cout << "Y : " << dirY << endl;

        if (dirX == 1){
            left = true;
        }
        if (dirX == 2){
            right = true;
        }
        if (dirY == 1){
            up = true;
        }
        if (dirY == 2){
            down = true;
        }
    };

    void action(TexRect* p1, TexRect* p2, TexRect* f1, TexRect* f2) {
        checkCollision(p1);
        checkCollision(p2);
        checkCollision(f1);
        checkCollision(f2);

        if(left && x >= -1.5) {
            x -= 0.0005;
        }
        if(right && (x + w) <= 1.5) {
            x += 0.0005;
        }
        if(up && y <= 1) {
            y += 0.0005;
        }
        if(down && (y - h - 0.1) >= -1) {
            y -= 0.0005;
        }
        if (timer = 0){
            rmove();
        //    std::cout << "DOT H" << std::endl;
        }
    };

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