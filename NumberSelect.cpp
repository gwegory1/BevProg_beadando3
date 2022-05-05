#include "graphics.hpp"
#include "NumberSelect.h"
#include <iostream>
#include <string>

using namespace std;
using namespace genv;

bool _up = false;
bool _down =false;

NumberSelect::NumberSelect(window* w, int x, int y, int sx, int sy, int ll, int lh) : Widget(w,x,y,sx,sy)
{
    _content = 0;
    _lower_limit =ll;
    _upper_limit =lh;
    _up = false;
    _down =false;
}

void NumberSelect::draw(){
 gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y);
 gout << move_to(_x,_y) << color(215,215,215) << box(3,_size_y);
 gout << move_to(_x,_y) << color(215,215,215) << box(_size_x,3);
 gout << move_to(_x,_y+ _size_y - 3) << color(225,225,225) << box(_size_x,3);
 ///Up button
 gout << move_to(_x+_size_x - (_size_x / 7),_y + 3);
 gout << color(215,215,215);
 if(_up) gout << color(115,115,115);
 gout << box(_size_x/7, _size_y/2);
 ///Down button
 gout << move_to(_x+_size_x - (_size_x / 7),_y + _size_y/2);
 gout << color(215,215,215);
 if(_down)gout << color(115,115,115);
 gout << box(_size_x/7, _size_y/2 - 3);
 ///Line in the middle
 gout << move_to(_x+_size_x - (_size_x / 7),_y + _size_y/2 - 1) << color(115,115,115) << box(_size_x/7, 2);
 ///Triangles
 gout << move_to(_x +_size_x -_size_x/14*1.5, _y + _size_y/8 *2.75) << color(10,10,10);
    for(int i = _size_x/14; i > 0; i -= 2){
        gout << line(i,0);
        gout << genv::move(-i+2,-1);
    }
 gout << move_to(_x +_size_x -_size_x/14*1.5, _y + _size_y/8 * 6.5);
    for(int i = _size_x/14; i > 0; i -= 2){
        gout << line(i,0);
        gout << genv::move(-i+2,1);
    }
 ///Text
 gout << move_to(_x + 5, _y + _size_y/2 - (gout.cascent()+ gout.cdescent())/2) << color(0,0,0) << text(to_string(_content));
}

void NumberSelect::handle(event ev){
    if (ev.type == ev_mouse && ev.pos_x > _x + (_size_x -_size_x/7) && ev.pos_x < (_x + _size_x) && ev.pos_y > _y && ev.pos_y < (_y + _size_y/2) && ev.button==btn_left) {
       _up = true;
       if(_content < _upper_limit) _content++;
    }
    if (ev.type == ev_mouse && ev.pos_x > _x + (_size_x -_size_x/7) && ev.pos_x < (_x + _size_x) && ev.pos_y > (_y + _size_y/2) && ev.pos_y < (_y + _size_y) && ev.button==btn_left) {
        _down = true;
        if(_content> _lower_limit) _content--;
    }
    if(ev.keycode == 75){
        cout << ev.keycode << endl;
          _up = true;
          if(_content < _upper_limit)_content += 10;
        }
    if(ev.keycode == 78){
          _down = true;
          if(_content > _lower_limit)_content -= 10;
        }
    if(ev.keycode == 82){
        _up = true;
        if(_content < _upper_limit)_content ++;
        }
    if(ev.keycode == 81){
        _down = true;
        if(_content> _lower_limit)_content --;
        }
    if(ev.button == -btn_left || ev.keycode < 0) {
            _up = false;
            _down = false;

    }
};

int NumberSelect::result(){
    return _content;
}
