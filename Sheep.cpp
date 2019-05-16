#include "Sheep.h"
#include <vector>

using namespace std;

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

void Sheep::action(vector<Actor*> act, int size, int self) {
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
