#ifndef Net_h
#define Net_h

#include <vector>

#include "TexRect.h"
#include "Rect.h"
#include "TextBox.h"

#include "Sheep.h"

class Net: public TexRect {
    int points;
    bool pointPosition;

    TextBox* screenPts;

public:

    Net(const char* filename, float x, float y, float w, float h, bool pointPosition);

    int getTotal() const;
    void addPoints();

    void draw(float z);

    void action(std::vector<Sheep*> flock);
};

#endif