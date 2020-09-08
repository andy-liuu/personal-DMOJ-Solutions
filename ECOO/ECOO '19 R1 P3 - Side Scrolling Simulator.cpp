#include <bits/stdc++.h>

using namespace std;

int j,w,h;

//[height][width]
string grid[11] = {};

bool canJump(int x,int y){


    //cannot land
    if (grid[y].at(x+2) == '@'){
        return false;
    }
    else{
        //go up (-direction in grid)
        //each height of jump
        for(int i = 1; i<= j; i++){

            if (grid[y-i].at(x) == '@' || grid[y-i].at(x+2) == '@'){
                return false;
            }
            else if (grid[y-i][x+1] == '.'){
                return true;
            }

        }
    }

    return false;








}

void solve(int x, int y){
    //current position is at grid[y].at(x);

    //made it
    if (grid[y].at(x) == 'G'){
        cout<<"CLEAR"<<endl;
        return;
    }
    else{

        //move forward case (into empty space or goal)
        if (grid[y].at(x+1) == '.' || grid[y].at(x+1) == 'G'){
            solve(x+1,y);
        }
        //jump case (there will always be another row behind the @
        else if (canJump(x,y)){
            solve(x+2, y);
        }
        else{
            //1 based indexing for the answer, +1 for the next column
            cout<<x+2<<endl;
            return;
        }
    }
}



int main(){

    for(int andy = 0; andy<10; andy++){


    //reset the grid;
    for(int i = 0; i<=10; i++){
        grid[i] = "";
    }




    cin>>j>>w>>h;

    int j = min(j, h-2);//floor is -1, and the ground floor is a jump of 0

    string temp;

    int startx,starty;
    int endx,endy;

    //all input except for the bottom floor
    for(int q = 0; q<h; q++){

        cin>>temp;

        if (q == h-2){


            for(int k = 0; k<w; k++){
                char cur = temp.at(k);


                if (cur == 'L'){
                    startx = k;
                    starty = q;
                }
                else if (cur == 'G'){
                    endx = k;
                    endy = q;
                }
            }
        }

        grid[q] = temp;
    }

    //floor doesn't matter
    solve(startx,starty);
    }









}
