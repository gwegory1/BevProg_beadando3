#include "graphics.hpp"
#include "widgets.hpp"
#include "window.h"
#include "NumberSelect.h"
#include "DropDownMenu.h"
#include "GameField.h"
#include "Button.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace genv;


void clear(){
        gout << move_to(0, 0) << color(0, 0, 0) << box(800, 800) << color(255, 255, 255);
    }


struct win : public window{

    ablak(){
     for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    };
};
int main()
{
    gout.open(800,800);
    gout.load_font("LiberationSans-Regular.ttf",32,true);
    win a;
    a.event_loop();
    return 0;
}

