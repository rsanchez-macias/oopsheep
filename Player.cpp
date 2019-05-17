#include "Player.h"

Player::Player(const char* filename, float x, float y, float w, float h, 
        int upK, int rightK, int downK, int leftK, bool doesMove, int index, float speed): 
        Actor(filename, x, y, w, h, doesMove, index, speed) {
    
    this->upK = upK;
    this->rightK = rightK;
    this->downK = downK;
    this->leftK = leftK;

    
}


void Player::action(std::vector<Actor*> actors) {

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


void Player::move(int key) {
    if(key == leftK) {
        left = true;
        right = false;
        dirX = -1;
    }
    if(key == upK) {
        up = true;
        down = false;
        dirY = 1;
    }
    if(key == rightK) {
        right = true;
        left = false;
        dirX = 1;
    }
    if(key == downK) {
        down = true;
        up = false;
        dirY = -1;
    }
}

void Player::stop(int key) {
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