#ifndef NUMBERSELECT_H_INCLUDED
#define NUMBERSELECT_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class NumberSelect : public Widget {
protected:
    int _content;
    int _lower_limit;
    int _upper_limit;
    bool _up;
    bool _down;
    window* _w;

public:
    NumberSelect(window * w, int x, int y, int sx, int sy, int ll, int lh);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual int result();
};

#endif // NUMBERSELECT_H_INCLUDED
