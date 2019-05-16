#include "Actor.h"
#include <cmath>

Actor::Actor(const char* filename, float x, float y, float w, float h, bool doesMove, int index, float speed):
             TexRect(filename, x, y, w, h){

    up = false;
    down = false;
    left = false;
    right = false;

    dirX = 0;
    dirY = 0;

    this->speed = speed;
    this->index = index;

    this->doesMove = doesMove;
}


void Actor::checkCollision(Actor* act) {

    float x = act->getX(), y = act->getY(), w = act->getW(), h = act->getH();

    float centerX = x + (w / 2);
    float centerY = y - (h / 2);

    
    if(
        (contains(x, y) && 
        abs(getX() + getW() - x) <= 0.005)
        || (contains(x, y - h) && 
        (abs(getX() + getW() - x) <= 0.005))
        || (contains(x, centerY))
    ) {
            right = false;
    }

    if(
        (contains(x, y) && 
        abs(getY() - getH() - y) <= 0.005)
        || (contains(x + w, y) && 
        !(abs(x + w - getX()) <= 0.005))
        || (contains(centerX, y))
    ) {
            down = false;
    }

    if(
        (contains(x + w, y) &&
        abs(x + w - getX()) <= 0.005)
        || (contains(x + w, y - h) &&
        !(abs(getY() - y + h) <= 0.005))
        || contains(x + w, centerY)
    ) {
            left = false;
    }

    if(
        (contains(x + w, y - h) && 
        abs(getY() - y + h) <= 0.005)
        || (contains(x, y - h) &&
        !(abs(getX() + getW() - x) <= 0.005))
        || contains(centerX, y - h)
    ) {
            up = false;
    }
}

Actor::~Actor() {

}