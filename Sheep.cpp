#include "Sheep.h"


Sheep::Sheep(const char* filename, float x, float y, float w, float h, bool doesMove):
             Actor(filename, x, y, w, h, true) {
    
    left = true;
}

void Sheep::move(){
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
}

void Sheep::action(Actor* pl1, Actor* pl2) {
    checkCollision(pl1);
    checkCollision(pl2);

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
