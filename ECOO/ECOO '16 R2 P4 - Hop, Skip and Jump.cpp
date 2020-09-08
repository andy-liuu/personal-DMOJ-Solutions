#include <bits/stdc++.h>
#define maxS 200
using namespace std;


/*
. clear
# ladder
= platform
*/


//[height][width]
//[x][y]
char grid[maxS][maxS];
bool visitedH[maxS][maxS] = {};
bool visitedS[maxS][maxS] = {};
bool visitedJ[maxS][maxS] = {};


//forward decclarations
void basics(int x,int y, char character);
void hopMove(int x,int y);
void skipMove(int x, int y);
void jumpMove(int x, int y);

void basics(int x,int y, char character){


    //do all falling




}


int main(void){


    int w,h;
    cin>>w>>h;

    int hx,hy;
    int sx,sy;
    int jx,jy;

    int cupx,cupy;
    int flagx,flagy;
    int tresx,tresy;


    string temp;
    for(int i = 0; i<h; i++){
        cin>>temp;
        for(int j = 0; j<w; j++){
            char let = temp.at(j);

            if (let == 'h'){
                hx = i;
                hy = j;
                grid[i][j] = '.';
            }
            else if (let == 's'){
                sx = i;
                sy = j;
                grid[i][j] = '.';
            }
            else if (let == 'j'){
                jx = i;
                jy = j;
                grid[i][j] = '.';
            }
            else if (let == 'C'){
                cupx = i;
                cupy = j;
                grid[i][j] = '.';
            }
            else if (let == 'F'){
                flagx = i;
                flagy = j;
                grid[i][j] = '.';
            }
            else if (let == 'T'){
                tresx = i;
                tresy = j;
                grid[i][j] = '.';
            }
            else{
                grid[i][j] = let;
            }

        }
    }


    //test outputs
    cout<<hx<<" "<<hy<<endl;
    cout<<sx<<" "<<sy<<endl;
    cout<<jx<<" "<<jy<<endl;
    cout<<cupx<<" "<<cupy<<endl;
    cout<<flagx<<" "<<flagy<<endl;
    cout<<tresx<<" "<<tresy<<endl;


    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }



}
