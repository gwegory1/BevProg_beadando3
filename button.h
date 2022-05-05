#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "DropDownMenu.h"
#include <string>
#include <functional>
#include <vector>
using namespace std;

class Button:Widget{
protected:
 int _content;
 bool _clicked;
 bool _hover;
 string _dir;
 std::function<void()> _fv;


public:
 Button(window* w, int x, int y, int sx, int sy,int value, string dir,std::function<void()> fv);
 virtual void draw();
 virtual void handle(genv::event ev);
 virtual bool isclicked();
};

#endif // BUTTON_H_INCLUDED
