#include "graphics.hpp"
#include "GameField.h"
#include "GameMaster.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace genv;


GameField::GameField(window * w, int x, int y, int sx, int sy): Widget(w,x,y,sx,sy){
        for(int i =0; i < 7;i++){
        vector<int> tempvec;
        for(int j =0; j < 7; j++){
            tempvec.push_back(0);
        }
        Kvec.push_back(tempvec);
        }
}


void GameField::load(GameMaster * g){
    Kvec = g->result();
}

void GameField::draw(){
    int r = 40;
    gout << move_to(_x,_y) << color(0,0,240) << box(_size_x, _size_y+ 10);
    for(int l = 6; l >= 0; l--){
        for(int k =6; k >= 0; k--){

            if(Kvec[k][l] == 0)gout << color(255,255,255);
            if(Kvec[k][l] == 1)gout << color(255,255,0);
            if(Kvec[k][l] == 2)gout << color(255,0,0);
            if(Kvec[k][l] == 0 && l == 0)gout << color(0,0,0);
            for(int i=-r; i < r; i++){
                for(int j=-r; j < r; j++){
                    if(i*i + j*j < r*r) gout << move_to(_x+r+((_size_x-2*r)/6)*k + i, _y-r+(_size_y-2*r)/5*l + j) << dot;
                }
            }
        }
    }

 }

