#include "graphics.hpp"
#include "widgets.hpp"
#include "window.h"
#include "NumberSelect.h"
#include "DropDownMenu.h"
#include "GameField.h"
#include "GameMaster.h"
#include "Button.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace genv;

void shift();

void clear(){
        gout << move_to(0, 0) << color(0, 0, 0) << box(800, 800) << color(255, 255, 255);
    }


struct ablak : public window{

    GameField * a1;
    vector<Widget*> widgets;


    ablak(){
    a1   = new GameField(this, 100, 100, 600, 500);
    };
};
int main()
{
    gout.open(800,800);
    event ev;
    GameMaster g(7,6);
    while(gin >> ev){
        if(ev.type == ev_key) g.drawconsole();
        gout << refresh;
        if(ev.keycode == 'a'){
            g.addpuck();
        }
        if(ev.keycode == 'd'){
            g.movepuck_right();
        }
        if(ev.keycode == 's'){
            g.movepuck_left();
        }
        if(ev.keycode == 'w'){
            g.savepuck();
        }
        }
    gout.load_font("LiberationSans-Regular.ttf",32,true);
    ablak a;
    //a.event_loop();
    return 0;
}

