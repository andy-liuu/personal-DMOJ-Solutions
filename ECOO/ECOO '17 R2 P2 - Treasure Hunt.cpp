#include <bits/stdc++.h>
using namespace std;
#define maxS 1000
#define maxKey 10

//record where treasures are
vector<pair<int,int>> chests;

//[vert][hor]
char grid[maxS][maxS];
bool visited[maxS][maxS][maxKey] = {};



int n;


int numKeys;
int ans;

void solve(int x, int y){

    //up
    if (x-1 >= 0){

        if (!visited[x-1][y][numKeys]){

            if (grid[x-1][y] == 'T'){
                visited[x-1][y][numKeys] = true;
                grid[x-1][y] = '.';
                ans++;
                //cout<<x-1<<" "<<y<<endl;
                solve(x-1,y);
            }
            else if (grid[x-1][y] == 'K'){
                //cout<<numKeys<<" "<<x-1<<" "<<y<<endl;
                visited[x-1][y][numKeys] = true;
                grid[x-1][y] = '.';
                numKeys++;
                visited[x-1][y][numKeys] = true;
                numKeys = min(9,numKeys);
                solve(x-1,y);
            }
            else if (grid[x-1][y] >= '1' && grid[x-1][y] <= '9' && (int)grid[x-1][y] - 48 <= numKeys){
                //cout<<"door"<<endl;
                visited[x-1][y][numKeys] = true;
                grid[x-1][y] = '.';
                solve(x-1,y);
            }
            else if (grid[x-1][y] == '.'){
                visited[x-1][y][numKeys] = true;
                solve(x-1,y);
            }
        }
    }

    //down
    if (x+1 < n){
        if (!visited[x+1][y][numKeys]){

            if (grid[x+1][y] == 'T'){
                visited[x+1][y][numKeys] = true;
                grid[x+1][y] = '.';
                ans++;
                //cout<<x+1<<" "<<y<<endl;
                solve(x+1,y);
            }
            else if (grid[x+1][y] == 'K'){
                //cout<<numKeys<<" "<<x+1<<" "<<y<<endl;
                visited[x+1][y][numKeys] = true;
                grid[x+1][y] = '.';
                numKeys++;
                visited[x+1][y][numKeys] = true;
                numKeys = min(9,numKeys);
                solve(x+1,y);
            }
            else if (grid[x+1][y] >= '1' && grid[x+1][y] <= '9' && (int)grid[x+1][y] - 48 <= numKeys){
                //cout<<"door"<<endl;
                visited[x+1][y][numKeys] = true;
                grid[x+1][y] = '.';
                solve(x+1,y);
            }
            else if (grid[x+1][y] == '.'){
                visited[x+1][y][numKeys] = true;
                solve(x+1,y);
            }
        }


    }


    if (y-1 >= 0){
        if (!visited[x][y-1][numKeys]){

            if (grid[x][y-1] == 'T'){
                visited[x][y-1][numKeys] = true;
                grid[x][y-1] = '.';
                ans++;
                //cout<<x<<" "<<y-1<<endl;
                solve(x,y-1);
            }
            else if (grid[x][y-1] == 'K'){
                //cout<<numKeys<<" "<<x<<" "<<y-1<<endl;
                visited[x][y-1][numKeys] = true;
                grid[x][y-1] = '.';
                numKeys++;
                visited[x][y-1][numKeys] = true;
                numKeys = min(9,numKeys);
                solve(x,y-1);
            }
            else if (grid[x][y-1] >= '1' && grid[x][y-1] <= '9' && (int)grid[x][y-1] - 48 <= numKeys){
                //cout<<"door"<<endl;
                visited[x][y-1][numKeys] = true;
                grid[x][y-1] = '.';
                solve(x,y-1);
            }
            else if (grid[x][y-1] == '.'){
                visited[x][y-1][numKeys] = true;
                solve(x,y-1);
            }
        }
    }

    if (y+1 < n){
        if (!visited[x][y+1][numKeys]){

            if (grid[x][y+1] == 'T'){
                visited[x][y+1][numKeys] = true;
                grid[x][y+1] = '.';
                ans++;
                //cout<<x<<" "<<y+1<<endl;
                solve(x,y+1);
            }
            else if (grid[x][y+1] == 'K'){
                //cout<<numKeys<<" "<<x<<" "<<y+1<<endl;
                visited[x][y+1][numKeys] = true;
                grid[x][y+1] = '.';
                numKeys++;
                visited[x][y+1][numKeys] = true;
                numKeys = min(9,numKeys);
                solve(x,y+1);
            }
            else if (grid[x][y+1] >= '1' && grid[x][y+1] <= '9' && (int)grid[x][y+1] - 48 <= numKeys){
                //cout<<"door"<<endl;
                visited[x][y+1][numKeys] = true;
                grid[x][y+1] = '.';
                solve(x,y+1);
            }
            else if (grid[x][y+1] == '.'){
                solve(x,y+1);
                visited[x][y+1][numKeys] = true;
            }
        }
    }



}

//x is vert
//y = hor










int main(void){

    for(int andy = 0; andy < 10; andy++){




    //reset
    for(int i = 0; i<1000; i++){
        for(int j = 0; j<1000; j++){
            grid[i][j] = '#';
            for(int q = 0; q<10; q++){
                visited[i][j][q] = false;
            }
        }
    }


    numKeys = 0;
    ans = 0;
    cin>>n;
    string temp;

    int sx,sy;//[sx][sy]
    for(int i = 0; i<n; i++){
        cin>>temp;
        for(int q = 0; q<n; q++){

            char let = temp.at(q);
            grid[i][q] = let;

            if (let == 'S'){
                sx = i;
                sy = q;
            }


        }

    }


    visited[sx][sy][0] = true;
    grid[sx][sy] = '.';

    //solve
    solve(sx,sy);
    cout<<ans<<endl;

    }









}
