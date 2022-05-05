#include "graphics.hpp"
#include "GameField.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace genv;


GameField::GameField(window * w, int x, int y, int sx, int sy): Widget(w,x,y,sx,sy){
 //   vector<vector<Korong*>>_kvec;
}


void GameField::draw(){
    int r = 40;
    gout << move_to(_x,_y) << color(0,0,240) << box(_size_x, _size_y);
    for(int l =0; l < 6; l++){
        for(int k =0; k < 7; k++){
            for(int i=-r; i < r; i++){
                for(int j=-r; j < r; j++){
                    if(i*i + j*j < r*r) gout << move_to(_x+r+((_size_x-2*r)/6)*k + i, _y+r+(_size_y-2*r)/5*l + j) << color(255,255,255) << dot;
                }
            }
        }
    }
 }

