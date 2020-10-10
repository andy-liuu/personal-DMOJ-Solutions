#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const int MAXN = 100;
const int MAXW = 1e9;
const int MAXVI = 1e3;

ll dp[MAXN+1][MAXN*MAXVI + 1]; //[item, value] holds minimum weight considering first n items and x value



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    int n, w;
    cin>>n>>w;

    ll curv, curw;
    for(int item = 1; item <= n; item++){
        cin>>curw>>curv;
        for(int val = 0; val <= n * MAXVI; val++){
            //not possivle to consider taking this item
            if(val - curv < 0){
                dp[item][val] = dp[item-1][val];
            }
            else{
                //some values may not exist denoted by -1

                //both exist, take min weight of take case and no take case
                if (dp[item-1][val] != -1 && dp[item-1][val-curv] != -1){
                    dp[item][val] = min(dp[item-1][val], dp[item-1][val-curv]+curw);
                }
                else if (dp[item-1][val] != -1){
                    dp[item][val] = dp[item-1][val];
                }
                else if (dp[item-1][val-curv] != -1){
                    dp[item][val] = dp[item-1][val-curv] + curw;
                }

            }
        }
    }


    for(int i = n*MAXVI; i>=0; i--){
        if(dp[n][i] != -1 && dp[n][i] <= w){
            cout<<i<<endl;
            break;
        }
    }





}
