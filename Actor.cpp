#include "Actor.h"
#include <cmath>

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

void Actor::collided(Actor* act, int dir) {
    for(int i = 0; i < 5; i++) {
        if(dir == 1) act->setX(act->getX() - 0.001);
        if(dir == 2) act->setY(act->getY() + 0.001);
        if(dir == 3) act->setX(act->getX() + 0.001);
        if(dir == 4) act->setY(act->getY() - 0.001);
    }
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
            //act->right = true;
            //hit = true;
    }

    if(
        (contains(x, y) && 
        abs(getY() - getH() - y) <= 0.005)
        || (contains(x + w, y) && 
        !(abs(x + w - getX()) <= 0.005))
        || (contains(centerX, y))
    ) {
            down = false;
            //act->down = true;
            //hit = true;
    }

    if(
        (contains(x + w, y) &&
        abs(x + w - getX()) <= 0.005)
        || (contains(x + w, y - h) &&
        !(abs(getY() - y + h) <= 0.005))
        || contains(x + w, centerY)
    ) {
            left = false;
            //act->left = true;
            //hit = true;
    }

    if(
        (contains(x + w, y - h) && 
        abs(getY() - y + h) <= 0.005)
        || (contains(x, y - h) &&
        !(abs(getX() + getW() - x) <= 0.005))
        || contains(centerX, y - h)
    ) {
            up = false;
            //act->up = true;
            //hit = true;
    }
}

Actor::~Actor() {

}