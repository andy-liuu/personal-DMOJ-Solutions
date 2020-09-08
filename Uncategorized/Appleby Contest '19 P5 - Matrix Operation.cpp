#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1500;
int n;

const int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};


int dp[MAXN][MAXN] = {{}};//-1 denotes not found yet
int graph[MAXN][MAXN] = {{}};


int longestpath(int x, int y){
    if (dp[x][y] != -1){
        return dp[x][y];
    }
    else{
        int val = graph[x][y];
        int ans = -1;
        for(int i = 0; i<4; i++){
            int newx = x + dirs[i][0];
            int newy = y + dirs[i][1];

            if (min(n, max(0, newx)) == newx && min(n, max(0, newy)) == newy){
                if (graph[newx][newy] > val){
                    ans = max(ans, longestpath(newx, newy));
                }
            }
        }

        dp[x][y] = ans+1;
        return dp[x][y];
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    int ans = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans = max(ans, longestpath(i,j));
        }
    }
    cout<<ans<<endl;

}
