#include <bits/stdc++.h>
using namespace std;

int len;
int lastnum = 0;

bool foundFirstNum[12] = {};
pair<int,int> start[12] = {};
pair<int,int> lasts[12] = {};

int dirs[4][2] = {{-1,0},{0,-1}, {1,0}, {0,1}};


string allnums = "0123456789";

//[vert][hor]
char grid[7][7] = {};
int finalpos[7][7] = {};



bool solved = false;
bool completelysolved = false;


void solve(int x,int y, char currnum){

    if (completelysolved){
        return;
    }
    else {

        for(int i = 0; i< 4; i++){



            int cx = dirs[i][0];
            int cy = dirs[i][1];

            //in range
            if (x + cx >= 0 && x + cx < len && y + cy >= 0 && y + cy < len){

                //is blank
                if (grid[x + cx][y + cy] == '.'){
                    grid[x + cx][y + cy] = currnum;
                    solve(x + cx, y + cy, currnum);

                    if (! completelysolved){
                        grid[x + cx][y + cy] = '.';
                    }
                }


                //you are at the end
                else if (grid[x + cx][y + cy] == currnum && finalpos[x + cx][y + cy] == (int)currnum - 48){

                    int realnum = (int)currnum - 48;
                    //last guy actually
                    if (realnum == lastnum){

                        bool ans = true;
                        for(int i = 0; i<len; i++){
                            for(int j = 0; j<len; j++){
                                if (grid[i][j] == '.'){
                                    ans = false;
                                    break;
                                }
                            }
                            if (!ans){
                                break;
                            }
                        }

                        if (ans){
                            completelysolved = true;
                            for(int y = 0; y<len; y++){
                                for(int x = 0; x<len; x++){
                                    cout<<grid[y][x];
                                }
                            cout<<endl;
                        }


                        }

                        return;
                    }
                    else{

                        solve (start[realnum + 1].first, start[realnum + 1].second, allnums.at(realnum + 1));
                    }


                }



            }


        }










    }





}



int main(void){

    for(int a = 0; a < 10; a++){

    for(int i = 0; i<7; i++){
        for(int j = 0; j<7; j++){
            grid[i][j] = '.';
            finalpos[i][j] = 0;
        }
    }

    lastnum = 0;
    solved = false;
    completelysolved = false;

    for(int i =- 0; i<12; i++){
        foundFirstNum[i] = false;
        start[i] = make_pair(0,0);
        lasts[i] = make_pair(0,0);

    }


    string temp;
    cin>>temp;

    len = temp.size();
    for(int j = 0; j<len; j++){
        char let = temp.at(j);
            if (let >= '1' && let <= '9'){

                int realnum = (int)let - 48;
                lastnum = max(lastnum, realnum);

                if (!foundFirstNum[realnum]){
                    foundFirstNum[realnum] = true;
                    start[realnum] = make_pair(0,j);


                }
                else{
                    lasts[realnum] = make_pair(0,j);
                    finalpos[0][j] = realnum;
                }
            }



        grid[0][j] = temp.at(j);
    }

    for(int i = 1; i<len; i++){
        cin>>temp;
        for(int j = 0; j<len; j++){

            char let = temp.at(j);
            if (let >= '1' && let <= '9'){

                int realnum = (int)let - 48;
                lastnum = max(lastnum, realnum);

                if (!foundFirstNum[realnum]){
                    foundFirstNum[realnum] = true;
                    start[realnum] = make_pair(i,j);


                }
                else{
                    lasts[realnum] = make_pair(i,j);
                    finalpos[i][j] = realnum;
                }
            }


            grid[i][j] = temp.at(j);
        }

    }


    solve(start[1].first, start[1].second, '1');
    cout<<endl;


    }








}


