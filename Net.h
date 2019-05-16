#ifndef Net_h
#define Net_h

#include "TexRect.h"
#include "Rect.h"

#include "Player.h"

class Net: public TexRect {
    int points;

public:

    Net(const char* filename, float x, float y, float w, float h):
    TexRect(filename, x, y, w, h) {}

    int getTotal() const {}

    int subPoints() {}
    int addPoints() {}
};

#endif