#ifndef GAMEFIELD_H_INCLUDED
#define GAMEFIELD_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "GameMaster.h"
#include <vector>

using namespace std;

class GameField:public Widget{
protected:
    vector<vector<int>> Kvec;

public:
    GameField(window * w,int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev){};
    virtual bool is_selected(int mouse_x, int mouse_y){};
    void load(GameMaster* g);
};

#endif // GAMEFIELD_H_INCLUDED
