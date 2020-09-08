#include <bits/stdc++.h>
using namespace std;
#define maxS 4

int dirs[8][2] = { {-1,-1} , {-1,1} , {1,-1} , {1,1} , {-1,0} , {0,-1} , {1,0} , {0,1}};



int score, tooShort, repeat, notFound;


char grid[maxS][maxS];//[vert][hor]
bool visited[maxS][maxS] = {};

bool solved;

int getPoints(string word){
    if (word.size() == 3 || word.size() == 4){
        return 1;
    }
    else if (word.size() == 5){
        return 2;
    }
    else if (word.size() == 6){
        return 3;
    }
    else if (word.size() == 7){
        return 4;
    }
    else if (word.size() > 7){
        return 11;
    }
    return 0;


}




void solve(int x, int y, int sofar, string word ){

    if (solved){
        return;
    }
    else{

        for(int e = 0; e<8; e++){




        }

    }




}


set<string> all;



int main(void){


    //get grid
    string temp;
    for (int q = 0; q<4; q++){
        cin>>temp;
        for( int w = 0; w<4; w++){
            grid[q][w] = temp.at(w);
        }

    }


    //x5 here

    all.clear();
    score = 0;
    tooShort = 0;
    repeat = 0;
    notFound = 0;


    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        string word;
        cin>>word;

        //too short
        if (word.size() <= 2){
            tooShort++;
        }
        else if (all.find(word) != all.end()){
            repeat++;
        }
        else{

            all.insert(word);
            solved = false;




        }



    }






}
