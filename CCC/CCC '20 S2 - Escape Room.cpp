#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

vector<pair<int,int>> factors[MAXN * MAXM + 1];

int grid[MAXN+1][MAXM+1];

bool visited[MAXN+1][MAXM+1] = {};


int endx, endy;

void dfs(int x, int y){
    if (x == endx && y == endy){
        visited[x][y] = true;
        return;
    }
    else if(visited[x][y]){
        return;
    }
    else{
        visited[x][y] = true;

        for(auto nex : factors[grid[x][y]]){
            int nexx = nex.first;
            int nexy = nex.second;


            if (!visited[nexx][nexy]){


                dfs(nexx, nexy);
            }
        }
    }



}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m,n;
    cin>>m>>n;

    endx = m;
    endy = n;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            cin>>grid[i][j];
            factors[(i)*(j)].push_back(make_pair(i,j));
        }
    }

    dfs(1,1);

    if(visited[m][n]){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }






}
