#include "graphics.hpp"
#include "textbox.hpp"
#include <iostream>
using namespace genv;

Textbox::Textbox(window *w, int x, int y, int sx, int sy) : Widget(w,x,y,sx,sy)
{
  _checked = false;
  _saved = "";
  _caps = false;
  _content = "";
}

void Textbox::draw(){
    gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y);
    gout << move_to(_x + _size_x,_y) << color(155,155,155) << box(-3,_size_y);
    gout << move_to(_x,_y) << color(155,155,155) << box(_size_x,3);
    gout << color(255,255,255);
    gout << move_to(_x,_y) << color(0,0,0) << text(_saved);
}

void Textbox::handle(event ev){
        if(ev.keycode == key_backspace && _saved.length() > 1){
            if(_content != ""){
              _saved = _content[_content.length()-1] + _saved;
              _content.pop_back();
            }
        _saved.pop_back();
        _saved.pop_back();
        _saved += '|';
        }
        else if (ev.keycode > 0 && ev.keycode != 225 && ev.keycode !=  57 && ev.keycode !=  -57 && ev.keycode != -225 && ev.keycode != 8 && ev.keycode != 13){
        std::cout << ev.keycode << std::endl;
        _saved.pop_back();
        if (_caps == true){
          _saved += toupper(ev.keycode);
        }
        else{
          _saved += ev.keycode;
        }
        _saved += '|';
        }
        if(ev.keycode ==  225){
          _caps = true;
        }
        if(ev.keycode == -225){
            _caps =false;
        }
        if(ev.keycode == 57){
            _caps = abs(_caps-1);
        }
        if(ev.keycode ==  13){
            if(_size_x*2 < 400) _size_x *= 2;
        }
    if(gout.twidth(_saved)  >= _size_x){
        _content += _saved[0];
        _saved = _saved.substr(1, _saved.length()-1);
        std::cout << "visible: "<< _content << std::endl;
        std::cout <<  "content: "<<_saved << std::endl;
}
}

void Textbox::set_value(string value, bool op){
    if(!op)_saved += value;
    else _saved= value;
}



