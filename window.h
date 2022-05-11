#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED
#include<vector>
#include"graphics.hpp"
#include"widgets.hpp"
#include "GameMaster.h"

class window{;
protected:
    std::vector<Widget*> widgets;
public:
    void WidgetReg(Widget *w){widgets.push_back(w);}
    void event_loop();
};

#endif // WINDOW_H_INCLUDED
