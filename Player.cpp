#include "Player.h"

Player::Player(const char* filename, float x, float y, float w, float h, int upK, int rightK, int downK, int leftK): TexRect(filename, x, y, w, h) {
    up = false;
    down = false;
    left = false;
    right = false;

    this->upK = upK;
    this->rightK = rightK;
    this->downK = downK;
    this->leftK = leftK;

    std::cout << "Hello" << std::endl;
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

void Player::action() {
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


