#include "graphics.hpp"
#include "widgets.hpp"
#include "window.h"
#include "NumberSelect.h"
#include "DropDownMenu.h"
#include "GameField.h"
#include "GameMaster.h"
#include "button.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace genv;



void clear(){
        gout << move_to(0, 0) << color(0, 0, 0) << box(800, 800) << color(255, 255, 255);
    }


struct ablak : public window{

    GameField * a1;
    Button* b1;
    Button* b2;
    Button* b3;
    GameMaster* g;
    vector<Widget*> widgets;


    ablak(){
    g = new GameMaster(7,7);
    a1   = new GameField(this, 100, 200, 600, 500);
    b1 = new Button(this, 300, 20, 40, 60, 0, "<", [this]()
    {
    g->movepuck_left();
    a1->load(g);
    });
    b2 = new Button(this, 460, 20, 40, 60, 0, ">", [this]()
    {
    g->movepuck_right();
    a1->load(g);
    });
    b2 = new Button(this, 350, 20, 100, 60, 0, "GO", [this]()
    {
    g->savepuck();
    g->addpuck();
    a1->load(g);
    if(g->check())cout << "win" << endl;
    });
    };
};

int main()
{
    gout.open(800,800);
    event ev;
    gout.load_font("LiberationSans-Regular.ttf",32,true);
    ablak a;
    a.event_loop();
    return 0;
}

