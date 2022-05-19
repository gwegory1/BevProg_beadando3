#include "DropDownMenu.h"
#include "iterator"
#include <iostream>
#include <vector>
#include <string>

using namespace genv;
using namespace std;


Part::Part(int x, int y, int sx, int sy, string content) :_x(x), _y(y), _content(content)
{
     _clicked =false;
     _hover =false;
     _size_x =sx;
     _size_y =sy;
}

void Part::draw(){
    gout << color(255,255,255);
    if(_hover) gout << color(85,85,85);
    gout << move_to(_x,_y) << box(_size_x,_size_y);
    gout << move_to(_x,_y) << color(215,215,215) << box(3,_size_y);
    gout << move_to(_x,_y) << color(215,215,215) << box(_size_x,3);
    gout << move_to(_x,_y+ _size_y - 3) << color(225,225,225) << box(_size_x,3);
    gout << move_to(_x + 5, _y + _size_y/2 - (gout.cascent()+ gout.cdescent())/2) << color(0,0,0) << text(_content);
}

void Part::handle(event ev){
     if(ev.pos_x>_x && ev.pos_x<_x+_size_x && ev.pos_y>_y && ev.pos_y<_y+_size_y) _hover = true;
     else{
        _hover = false;
     }
     if(_hover && ev.type == ev_mouse && ev.button == btn_left) _clicked =true;
     else{
        _clicked = false;
     }
}

bool Part::isclicked(){
    return _clicked;
    }

DropDown::DropDown(window * w, int x, int y, int sx, int sy, int lim, vector<string>&contents): Widget(w,x,y,sx,sy)
{
    for(int i= 0; i < contents.size(); i ++){
        Part p(x, y + i*sy, sx, sy, contents[i]);
        _partvec.push_back(p);
    }
    _SelectedPart = 0;
    _open=false;
    _lim = lim;
}

void DropDown::draw(){
    vector<Part> visible;
    for(int i =0; i < _partvec.size(); i++)
        {
            if(_partvec[i]._y >= _y && _partvec[i]._y < _y + _lim*_size_y ) visible.push_back(_partvec[i]);

        }
    if(_open){
        for(int i =0; i < visible.size(); i++)
        {
            visible[i].draw();
        }
    }
    else{
    gout << color(255,255,255);
    gout << move_to(_x,_y) << box(_size_x,_size_y);
    gout << move_to(_x,_y) << color(215,215,215) << box(3,_size_y);
    gout << move_to(_x,_y) << color(215,215,215) << box(_size_x,3);
    gout << move_to(_x,_y+ _size_y - 3) << color(225,225,225) << box(_size_x,3);
    gout << move_to(_x + 5, _y + _size_y/2 - (gout.cascent()+ gout.cdescent())/2) << color(0,0,0) << text(_partvec[_SelectedPart]._content);
    }
}


bool DropDown::is_selected(int mouse_x, int mouse_y){
    if(_open){
     for(Part p: _partvec){
        if (mouse_x > p._x && mouse_x < p._x+p._size_x && mouse_y > p._y && mouse_y < p._y+p._size_y) return true;
    }
    return false;
    }
    else{
       return Widget::is_selected(mouse_x, mouse_y);
    }
}

void DropDown::handle(event ev){
    if(_open){
        for(int i = 0; i < _partvec.size(); i++){
            _partvec[i].handle(ev);
            if(_partvec[i]._clicked){
                cout << "closed" << endl;
                _SelectedPart = i;
                _open =false;
            }
        }
        if(ev.type == ev_mouse && ev.button==btn_wheelup){
            if(_partvec[_partvec.size()-1]._y > _y + (_lim -1)* _size_y){
            for(Part& p: _partvec){
                p._y -=_size_y;
            }
            }
        }
        if(ev.type == ev_mouse && ev.button==btn_wheeldown){
            if(_partvec[0]._y < _y){
            for(Part& p: _partvec){
                p._y +=_size_y;
            }
            }
    }
    }
    else if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) _open =true;
}

string DropDown::result(){
 return _partvec[_SelectedPart]._content;
}

void DropDown::addItem(string item){
    for(Part p : _partvec){
        if(p._content == item) return;
    }
    Part p(_x, _y, _size_x, _size_y, item);
    _partvec.insert(_partvec.begin(),p);
    for(int i = 1; i < _partvec.size(); i++){
        _partvec[i]._y +=_size_y;
    }
}

void DropDown::removeItem(){
    if(_partvec.size() >= 1){
    _partvec.erase(_partvec.begin() + _SelectedPart);
    for(int i = _SelectedPart; i < _partvec.size(); i++){
        _partvec[i]._y -=_size_y;
    }
    }
}

