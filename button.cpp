#include "button.h"
#include "DropDownMenu.h"
#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace genv;


Button::Button(window* w, int x, int y, int sx, int sy, int value, string dir, std::function<void()> fv) : Widget(w,x,y,sx,sy)
{
     _clicked =false;
     _hover =false;
     _size_x =sx;
     _size_y =sy;
     _dir =dir;
     _content =value;
     _fv = fv;
}

void Button::draw(){
    gout << color(255,255,255);
    if(_hover ) gout << color(215,215,215);
    gout << move_to(_x,_y) << box(_size_x,_size_y);
    gout << move_to(_x,_y) << color(215,215,215) << box(3,_size_y);
    gout << move_to(_x,_y) << color(215,215,215) << box(_size_x,3);
    gout << move_to(_x,_y+ _size_y - 3) << color(225,225,225) << box(_size_x,3);
    gout << move_to(_x + _size_y/2 - 10, _y + _size_y/2 - (gout.cascent()+ gout.cdescent())/2) << color(0,0,0) << text(_dir);
    /*
    if(_dir == "right"){
        gout << move_to(_x +_size_x/2 - 5 , _y + _size_y/2 -10) << color(10,10,10);
    for(int i = 20; i > 0; i -= 2){
        gout << line(0,i);
        gout << genv::move(1,-i+2);
    }
    }
        if(_dir == "left"){
        gout << move_to(_x +_size_x/2 + 5 , _y + _size_y/2 -10) << color(10,10,10);
    for(int i = 20; i > 0; i -= 2){
        gout << line(0,i);
        gout << genv::move(-1,-i+2);
    }
    }
 */
}

void Button::handle(event ev){
     if(ev.pos_x>_x && ev.pos_x<_x+_size_x && ev.pos_y>_y && ev.pos_y<_y+_size_y) _hover = true;

     else{
        _hover = false;
     }
     if(_hover && ev.type == ev_mouse && ev.button == btn_left){
        _clicked =true;
        _fv();
     }
     else{
        _clicked = false;
     }
}

bool Button::isclicked(){
    return _clicked;
    }
