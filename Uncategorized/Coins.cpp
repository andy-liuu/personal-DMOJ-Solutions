#include <bits/stdc++.h>
using namespace std;



//CONSTRAINTS
const int MAXN = 2999;


//INPUTS
long double probs[MAXN+1];

long double dp[MAXN+1][MAXN+1];
/*
dp[coins][numeheads] denotes probability for the first [coins] coins that flip [#heads]
*/

//returns probability given #coins and #heads
long double solve(int coins, int heads){
    if(dp[coins][heads] != -1.0){
        return dp[coins][heads];
    }
    else{
        //no heads, no option for 1 less head + this coin is head
        if (heads == 0){
            dp[coins][heads] = solve(coins-1, heads) * (1.0 - probs[coins]);
        }
        //all heads, no option for same number of heads and 1 less coind
        else if (coins == heads){
            dp[coins][heads] = solve(coins-1, heads-1) * (probs[coins]);
        }
        //need to consider both this coin is tails and this coin is heads
        else{
            dp[coins][heads] = (solve(coins-1, heads) * (1.0 - probs[coins])) + (solve(coins-1, heads-1) * (probs[coins]));
        }
        return dp[coins][heads];
    }
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin>>n;



    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            dp[i][j] = (long double)(-1.0);
        }
    }


    for(int i = 1; i<=n; i++){
        cin>>probs[i];
    }

    dp[1][0] = (1.0 - probs[1]);
    dp[1][1] = probs[1];





    long double ans = 0.0;
    for(int i = 0; i<=n; i++){
        if(2*i > n){
            ans += solve(n, i);
        }
    }
    cout.precision(10);
    cout<<fixed<<ans<<endl;






}
