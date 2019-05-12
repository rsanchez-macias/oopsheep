#ifndef MEN_H
#define MEN_H

#include "TexRect.h"
#include <vector>
#include <iterator>

class Menu {
protected:
    bool display;
    std::vector<TexRect*> buttons;
    
public:
    virtual void draw();
    void setDisplay(bool state);

    void handleMouseDown(float x, float y) {
        for(std::vector<TexRect*>::iterator i = buttons.begin(); i != buttons.end(); i++) {
            if(*(i)->contains(x, y)) {
                
            }
        }
    }

    virtual ~Menu();
};

#endif