#ifndef DROPDOWNMENU_H_INCLUDED
#define DROPDOWNMENU_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
#include <vector>
using namespace std;

struct Part{
public:
 int _x, _y, _size_x, _size_y ;
 string _content;
 bool _clicked;
 bool _hover;


 Part(int x, int y, int sx, int sy, string content);
 virtual void draw();
 virtual void handle(genv::event ev);
 virtual bool isclicked();
};


class DropDown: public Widget{
protected:
    bool _open;
    vector<Part> _partvec;
    int _SelectedPart, _lim;
    window* _w;

public:
    DropDown(window*  w,int x, int y, int sx, int sy, int lim, vector<string>&contents);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual string result();
    virtual void addItem(string item);
    virtual void removeItem();
};


#endif // DROPDOWNMENU_H_INCLUDED
