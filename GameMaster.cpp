#include "GameMaster.h"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;


GameMaster::GameMaster(int a, int b){
    for(int i =0; i < a;i++){
        vector<int> tempvec;
        for(int j =0; j < b+1; j++){
            tempvec.push_back(0);
        }
       fieldvec.push_back(tempvec);
    }
    gamestate = 0;
}

void GameMaster::drawconsole(){
for(vector<int> vec : fieldvec){
    for(int i:vec){
        cout << i << " | ";
    }
    cout << endl;
    }
}

void GameMaster::addpuck(){
    vector<int>cvec =fieldvec[fieldvec.size()/2];
    cvec.erase(cvec.begin());
    if(gamestate%2 == 0)cvec.insert(cvec.begin(),1);
    else cvec.insert(cvec.begin(),2);
}

void GameMaster::movepuck_right(){
    for(int i = 0; i < fieldvec.size(); i++){
        if(fieldvec[i][0] != 0){
            fieldvec[i].erase(fieldvec[i].begin());
            fieldvec[i+1].erase(fieldvec[i+1].begin());
            if(gamestate%2 == 0)fieldvec[i].insert(fieldvec[i].begin(),1);
            else fieldvec[i+1].insert(fieldvec[i+1].begin(),2);
        }
    }
}


void GameMaster::movepuck_left(){
for(int i = 0; i < fieldvec.size(); i++){
        if(fieldvec[i][0] != 0){
            fieldvec[i].erase(fieldvec[i].begin());
            fieldvec[i-1].erase(fieldvec[i-1].begin());
            if(gamestate%2 == 0)fieldvec[i].insert(fieldvec[i].begin(),1);
            else fieldvec[i-1].insert(fieldvec[i-1].begin(),2);
        }
    }
}

void GameMaster::savepuck(){
for(int i = 0; i < fieldvec.size(); i++){
        if(fieldvec[i][0] != 0){
            for(int j =0; j<fieldvec[i].size(); j++){
                if (fieldvec[i][j] !=0 && j > 1){
                    if(gamestate%2 == 0) fieldvec[i].insert(fieldvec[i].begin() + j-1, 1);
                    else  fieldvec[i].insert(fieldvec[i].begin() + j-1, 1);
                }
                if(j < fieldvec[i].size()){
                    if(gamestate%2 == 0) fieldvec[i].insert(fieldvec[i].begin() + j-1, 1);
                    else  fieldvec[i].insert(fieldvec[i].begin() + j-1, 2);
                }
            }
        }
    }
    gamestate++;
}
