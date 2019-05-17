#include "Net.h"
#include <string>


Net::Net(const char* filename, float x, float y, float w, float h, bool pointPosition):
    TexRect(filename, x, y, w, h) {
    
    points = 0;
    
    if(pointPosition) {
        screenPts = new TextBox("0", -1.70, 0.7, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0, 0.4);
    }
    else {
        screenPts = new TextBox("0", 1.6, 0.7, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0, 0.4);
    }
   
}

int Net::getTotal() const {
    return points;
}

void Net::addPoints() {
    points++;
}

void Net::draw(float z) {
    TexRect::draw(z);

    std::string sPoints = std::to_string(points);
    const char* cPoints = sPoints.c_str();
    screenPts->changeText(cPoints);

    screenPts->draw();
}

void Net::action(std::vector<Sheep*> flock) {
    float x, y, w, h;
    for(int i = 0; i < flock.size(); i++) {
        x = flock[i]->getX();
        y = flock[i]->getY();
        w = flock[i]->getW();
        h = flock[i]->getH();

        if(contains(x + (w / 2), y - (h / 2))) {
            flock[i]->setIn(true);
            flock[i]->setX(5.0);
            addPoints();
        }
    }
}
