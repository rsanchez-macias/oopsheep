#include "Net.h"
#include <string>


Net::Net(const char* filename, float x, float y, float w, float h, bool pointPosition):
    TexRect(filename, x, y, w, h) {
    
    points = 0;
    
    if(!pointPosition) {
        screenPts = new TextBox("0", -1.70, 0.7, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0, 0.4);
        playerName = new TextBox("PL 1", -1.75, 0.9, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 0.0, 0.0, 800);
    }
    else {
        screenPts = new TextBox("0", 1.6, 0.7, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0, 0.4);
        playerName = new TextBox("PL 2", 1.55, 0.9, GLUT_BITMAP_TIMES_ROMAN_24, 0.0, 1.0, 0.0, 800);
    }
   
}

int Net::getTotal() const {
    return points;
}

void Net::resetPoints() {
    points = 0;
}

void Net::addPoints() {
    points++;
}

/*
Display the net.png as well as the score so far
the net
*/
void Net::draw(float z) {
    TexRect::draw(z);

    std::string sPoints = std::to_string(points);
    const char* cPoints = sPoints.c_str();
    screenPts->changeText(cPoints);

    playerName->draw();
    screenPts->draw();
}

/*
Check to see if the center point of the sheep is 
in the net. If it is, remove sheep from the screen
and add points to the corresponding net
*/
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
