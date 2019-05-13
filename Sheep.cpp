#include "Sheep.h"
#include <ctime>
#include <cstdlib>

class Sheep: public TexRect {

    bool up, down, left, right;
    int upK, downK, leftK, rightK;
    int dirX, dirY;

    int timer = 100;

public:

   // Player(float x, float y, float w, float h, float r, float g, float b);
    Sheep(const char* filename, float x, float y, float w, float h, int upK, int rightK, int downK, int leftK): TexRect(filename, x, y, w, h) {
        up = true;
        down = false;
        left = true;
        right = false;

        this->upK = upK;
        this->rightK = rightK;
        this->downK = downK;
        this->leftK = leftK;
    }

    void rmove(){
        //timer = 100;
        
        /*
        up = false;
        down = false;
        left = false;
        right = false;
        */

        if ((x < -0.8 && y > 0.8) || (x > 0.8 && y < -0.8)){ 
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

        /*
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
        */
    };

    void action() {
        if(left) {
            x -= 0.0005;
        }
        if(right) {
            x += 0.0005;
        }
        if(up) {
            y += 0.0005;
        }
        if(down) {
            y -= 0.0005;
        }
        if (timer = 0){
            rmove();
        //    std::cout << "DOT H" << std::endl;
        }
        timer --;
        rmove();
    };
};