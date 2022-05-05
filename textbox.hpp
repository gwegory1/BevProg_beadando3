#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include <string>
#include "widgets.hpp"
#include "graphics.hpp"

using namespace std;

class Textbox : public Widget {
protected:
    bool _checked;
    std::string _content;
    std::string _saved;
    std::string vis;
    bool _caps;
    window*w;
public:
    Textbox(window *w,int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual void set_value(string value, bool op);
};


#endif // TEXTBOX_HPP_INCLUDED
