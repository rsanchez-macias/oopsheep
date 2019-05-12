#include "Sheep.h"

class Sheep: public TexRect {

    bool up, down, left, right;
    int upK, downK, leftK, rightK;

public:

   // Player(float x, float y, float w, float h, float r, float g, float b);
    Sheep::Sheep(const char* filename, float x, float y, float w, float h, int upK, int rightK, int downK, int leftK): TexRect(filename, x, y, w, h) {
        up = false;
        down = false;
        left = false;
        right = false;

        this->upK = upK;
        this->rightK = rightK;
        this->downK = downK;
        this->leftK = leftK;
    }

    void move(int key) {
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
    };

    void stop(int key) {
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
    };
};