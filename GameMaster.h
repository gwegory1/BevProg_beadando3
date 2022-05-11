#ifndef GAMEMASTER_H_INCLUDED
#define GAMEMASTER_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

using namespace std;

class GameMaster{
protected:
vector<vector<int>> fieldvec;
int gamestate;
public:
GameMaster(int, int);
virtual void addpuck();
virtual void movepuck_right();
virtual void movepuck_left();
virtual void drawconsole();
virtual void savepuck();
};



#endif // GAMEMASTER_H_INCLUDED
