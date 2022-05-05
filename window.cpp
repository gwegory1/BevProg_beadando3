#include "graphics.hpp"
#include "widgets.hpp"
#include "window.h"

using namespace std;
using namespace genv;

static void clear(){
        gout << move_to(0, 0) << color(0, 0, 0) << box(400, 400) << color(255, 255, 255);
    }



    void window::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        clear();
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
        }
}
