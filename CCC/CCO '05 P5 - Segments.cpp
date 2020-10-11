#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MAXN = 20000;

int dp[MAXN+1][2];//denotes minimum distance for if you end at the left node [0] or right node [1]




int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[0][1] = 0;


    int n;
    cin>>n;

    int prevL = 1;
    int prevR = 1;

    int curL, curR;


    for(int level = 1; level <= n; level++){
        cin>>curL>>curR;
        int dist = abs(curR - curL);

        int LtoL = abs(prevL - curR) + dist;
        int RtoL = abs(prevR - curR) + dist;
        int LtoR = abs(prevL - curL) + dist;
        int RtoR = abs(prevR - curL) + dist;

        dp[level][0] = min(dp[level-1][0]+LtoL + 1, dp[level-1][1]+RtoL + 1);
        dp[level][1] = min(dp[level-1][0] + LtoR + 1, dp[level-1][1]+RtoR + 1);

        prevL = curL;
        prevR = curR;



    }

    cout<<min(abs(n - prevL) + dp[n][0], abs(n - prevR) + dp[n][1]) - 1<<endl;


}
