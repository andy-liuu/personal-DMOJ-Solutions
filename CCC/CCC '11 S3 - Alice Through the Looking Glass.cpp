#include <bits/stdc++.h>
using namespace std;

int base[5][5] = {

{0,1,1,1,0},
{0,0,1,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0}

};

int baseModify[5][5] = {

{0,1,1,1,0},
{0,2,1,2,0},
{0,0,2,0,0},
{0,0,0,0,0},
{0,0,0,0,0}

};

bool recur(int m, int x, int y){

    //base case when m is one
    if(m == 1){
        return base[y][x];
    }
    else{
        //base cases when you are in a complete box or are completely idiodic
        int xadjust = (x - x%(int)pow(5,m-1))/(int)pow(5,m-1);
        int yadjust = (y - y%(int)pow(5,m-1))/(int)pow(5,m-1);

        if(baseModify[yadjust][xadjust] == 0){
            return false;
        }
        if(baseModify[yadjust][xadjust] == 1){
            return true;
        }

        if(baseModify[yadjust][xadjust] == 2){
            //recur here at a smaller level
            int newx = x%(int)pow(5,m-1);
            int newy = y%(int)pow(5,m-1);

            return recur(m-1, newx, newy);

        }


    }





}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int m,x,y;
        cin>>m>>x>>y;
        if(recur(m,x,y)){
            cout<<"crystal"<<endl;
        }
        else{
            cout<<"empty"<<endl;
        }
    }



}
