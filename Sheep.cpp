#include "Sheep.h"


Sheep::Sheep(const char* filename, float x, float y, float w, float h, bool doesMove, int index, float speed):
             Actor(filename, x, y, w, h, true, index, speed) {
    
    inside = false;
}

void Sheep::setIn(bool inside) {
    this->inside = inside;
}

bool Sheep::getIn() const {
    return inside;
}

void Sheep::move(){
    timer = 10;  
    
    up = false;
    down = false;
    left = false;
    right = false;

    dirX = (rand() % 3);
    dirY = (rand() % 3);


    if (dirX == 1) {
        left = true;
    }
    if (dirX == 2) {
        right = true;
    }
    if (dirY == 1) {
        up = true;
    }
    if (dirY == 2) {
        down = true;
    }
}

void Sheep::action(std::vector<Actor*> actors) {

    if(!hit)
        move();

    for(int i = 0; i < actors.size(); i++) {
        if(i != index) checkCollision(actors[i]);
    }

    if(left && x >= -1.5) {
        x -= speed;
    }

    if(right && (x + w) <= 1.5) {
        x += speed;
    }

    if(up && y <= 1) {
        y += speed;
    }

    if(down && (y - h - 0.1) >= -1) {
        y -= speed;
    }
}
