#include "Actor.h"
#include <cmath>

#include <iostream>

Actor::Actor(const char* filename, float x, float y, float w, float h, bool doesMove, int index, float speed):
             TexRect(filename, x, y, w, h){

    up = false;
    down = false;
    left = false;
    right = false;

    hit = false;

    dirX = 0;
    dirY = 0;

    this->speed = speed;
    this->index = index;

    this->doesMove = doesMove;
}

void Actor::setHit(bool hit) {
    this->hit = hit;
}

bool Actor::getHit() const {
    return hit;
}

void Actor::resetState() {
    state = true;
}

void Actor::checkBorderCollision(Actor* act) {
    if((abs(act->getX() + 1.5) <= 0.005)) {
        //act->hit = false;
        act->right = true;
        act->left = false;
        act->up = false;
        act->down = false;
    }
    if((abs(act->getY() - 1.0) <= 0.005)) {
        //act->hit = false;
        act->right = false;
        act->left = false;
        act->up = false;
        act->down = true;
    }
    if((abs(act->getX() + act->getW() - 1.5) <= 0.005)) {
        //act->hit = false;
        act->right = false;
        act->left = true;
        act->up = false;
        act->down = false;
    }
    if((abs(act->getY() - act->getH() + 0.9) <= 0.05)) {
        //act->hit = false;
        act->right = false;
        act->left = false;
        act->up = true;
        act->down = false;
    }
}

void Actor::checkCollision(Actor* act) {


    float x = act->getX(), y = act->getY(), w = act->getW(), h = act->getH();

    float centerX1 = x + (w / 4);
    float centerX2 = x + (w / 2);
    float centerX3 = x + 3 * (w / 4);

    float centerY1 = y - (h / 4);
    float centerY2 = y - (h / 2);
    float centerY3 = y - (3 * (h / 4));


    if(
        (contains(x, y) && 
        abs(getX() + getW() - x) <= 0.005)
        || (contains(x, y - h) && 
        (abs(getX() + getW() - x) <= 0.005))
        || (contains(x, centerY2))
    ) {
        right = false;

        if(!(index >= 2 && (act->index <= 2)) || (state)) {
            act->right = true;
            hit = true;  
            state = false;
        }
    }

    if(
        (contains(x, y) && 
        abs(getY() - getH() - y) <= 0.005)
        || (contains(x + w, y) && 
        !(abs(x + w - getX()) <= 0.005))
        || (contains(centerX1, y))
        || (contains(centerX2, y))
        || (contains(centerX3, y))
    ) {
        down = false;
        if(!(index >= 2 && (act->index <= 2)) || (state)) {
            act->down = true;
            hit = true;
            state = false;
        }
    }

    if(
        (contains(x + w, y) &&
        abs(x + w - getX()) <= 0.005)
        || (contains(x + w, y - h) &&
        !(abs(getY() - y + h) <= 0.005))
        || contains(x + w, centerY2)
    ) {
        left = false;
        if(!(index >= 2 && (act->index <= 2)) || (state)) {
            act->left = true;
            hit = true;
            state = false;
        }
    }

    if(
        (contains(x + w, y - h) && 
        abs(getY() - y + h) <= 0.005)
        || (contains(x, y - h) &&
        !(abs(getX() + getW() - x) <= 0.005))
        || contains(centerX1, y - h)
        || contains(centerX2, y - h)
        || contains(centerX3, y - h)
    ) {
        up = false;
        if(!(index >= 2 && (act->index <= 2)) || (state)) {
            act->up = true;
            hit = true;
            state = false;
        }
    }

    if(act->index >= 2) {
        checkBorderCollision(act);
    }

}

Actor::~Actor() {

}