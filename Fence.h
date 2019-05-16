#ifndef Fen_h
#define Fen_h

#include "TexRect.h"
#include "Rect.h"

#include "Player.h"
#include <vector>

using namespace std;

class Fence: public TexRect {
    int points;

public:

    Fence(const char* filename, float x, float y, float w, float h):
    TexRect(filename, x, y, w, h) {}

    int getTotal() const {}

    int subPoints() {}
    int addPoints() {}
};

#endif