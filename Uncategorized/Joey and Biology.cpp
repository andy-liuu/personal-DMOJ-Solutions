#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1000;
ll dp[MAXN+1][MAXN+1];

int n,m;
string top, bot;

int cost(int a, int b){
    if (top.at(a-1) == bot.at(b-1)){
        return 0;
    }
    else{
        return 1;
    }
}

ll solve(int x, int y){
    if (dp[x][y] != -1){
        return dp[x][y];
    }
    else{
        ll ans = LLONG_MAX;

        //cases for deletion
        for(int i = 1; i<=3; i++){
            if (x - i >= 0){
                ans = min(ans, solve(x-i, y) + 1);
            }

            if(y - i >= 0){
                ans = min(ans, solve(x, y-i) + 1);
            }
        }

        //case for replacing/same letter
        if (x-1 >= 0 && y - 1 >= 0){
            ans = min(ans, solve(x-1, y-1) + cost(x,y));
        }


        dp[x][y] = ans;
        return dp[x][y];


    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);


    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    cin>>n>>m;
    cin>>top>>bot;

    cout<<solve(n,m)<<endl;






}
