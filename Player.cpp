#include "Player.h"
#include <vector>

using namespace std;

Player::Player(const char* filename, float x, float y, float w, float h, 
        int upK, int rightK, int downK, int leftK, bool doesMove): Actor(filename, x, y, w, h, doesMove) {
    
    this->upK = upK;
    this->rightK = rightK;
    this->downK = downK;
    this->leftK = leftK;

}


void Player::action(vector<Actor*> act, int size, int self) {
    //CHECK COLLISOION
    for (int i = 0; i < size; i ++){
        if (i != self){
            checkCollision(act[i]);
        }
    }

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


void Player::move(int key) {
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
