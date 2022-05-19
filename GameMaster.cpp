#include "GameMaster.h"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;


GameMaster::GameMaster(int a, int b){
    for(int i =0; i < a;i++){
        vector<int> tempvec;
        for(int j =0; j < b; j++){
            tempvec.push_back(0);
        }
       fieldvec.push_back(tempvec);
    }
    gamestate = 0;

}

void GameMaster::drawconsole(){
for(int i= 0; i < fieldvec.size(); i++){
    for(int j =0;j < fieldvec[i].size();j++){
        cout << fieldvec[j][i] << " | ";

    }
    cout << endl;
    }
    cout << endl;
}

void GameMaster::addpuck(){
        if(gamestate%2 == 0)fieldvec[3][0] = 1;
        else fieldvec[3][0] = 2;
}

void GameMaster::movepuck_right(){
    for(int i = 0; i < fieldvec.size()-1; i++){
        if(fieldvec[i][0] != 0){
            fieldvec[i][0] = 0;
            if(gamestate%2 == 0)fieldvec[i+1][0] = 1;
            else fieldvec[i+1][0] = 2;
            break;
        }
    }
}
void GameMaster::movepuck_left(){
    for(int i = 1; i < fieldvec.size(); i++){
        if(fieldvec[i][0] != 0){
            fieldvec[i][0] = 0;
            if(gamestate%2 == 0)fieldvec[i-1][0] = 1;
            else fieldvec[i-1][0] = 2;
            break;
        }
    }
}


void GameMaster::savepuck(){
for(int i = 0; i < fieldvec.size(); i++){
        if(fieldvec[i][0] != 0){
            for(int j =0; j<fieldvec[i].size(); j++){
                if (fieldvec[i][j] !=0 && j > 1){
                    fieldvec[i][0] =0;
                    if(gamestate%2 == 0) fieldvec[i][j-1]=1;
                    else  fieldvec[i][j-1]=2;
                    break;
                }
                if(j == fieldvec[i].size()-1){
                    fieldvec[i][0] =0;
                    if(gamestate%2 == 0) fieldvec[i][j]=1;
                    else  fieldvec[i][j]=2;
                    break;
                }
            }
        }
    }
    gamestate++;
}

bool GameMaster::check(){
    for(vector<int> vec: fieldvec){
        for(int i =0; i < 4; i++){
            string st;
            for(int j = 0; j < 4; j++){
                st += to_string(vec[i+j]);
                if(st=="1111" || st =="2222")return true;
            }

        }
    }

    for(int l =1; l < 7; l++){
        for(int i =0; i < 3; i++){
            string st;
            for(int j=0; j < 4; j++){
                st += to_string(fieldvec[i+j][l]);
                //cout << st << endl;
            if(st=="1111" || st =="2222")return true;
            }
        }
     }

        for(int i =3; i >= 1 ; i--){
            for(int j=0; j < 3; j++){
                string st;
                for(int k= 0; k < 4; k++){
                    st += to_string(fieldvec[j+k][i+j+k]);
                    //cout << st << endl;
                    if(st=="1111" || st =="2222")return true;
                }
            }
        }

        for(int i =1; i < 4 ; i++){
            for(int j=0; j < 4-i; j++){
                string st;
                for(int k=0; k < 4; k++){
                    st += to_string(fieldvec[i+j+k][1+j+k]);
                    //cout << st << endl;
                    if(st=="1111" || st =="2222")return true;
                }
            }
        }

        for(int i =3; i >= 1 ; i--){
            for(int j=0; j < 3; j++){
                string st;
                for(int k= 0; k < 4; k++){
                    st += to_string(fieldvec[6-j-k][i+j+k]);
                    //cout << st << endl;
                    if(st=="1111" || st =="2222")return true;
                }
            }
        }

        for(int i =1; i < 4 ; i++){
            for(int j=0; j < 4-i; j++){
                string st;
                for(int k=0; k < 4; k++){
                    st += to_string(fieldvec[6-i-j-k][1+j+k]);
                    //cout << st << endl;
                    if(st=="1111" || st =="2222")return true;
                }
            }
        }

         return false;
    }

vector<vector<int>> GameMaster::result(){
        return fieldvec;
    }

