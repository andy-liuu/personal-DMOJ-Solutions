#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100;
const int MAXW = 1e5;

ll vals[MAXN+1];
ll weights[MAXN+1];
ll dp[MAXN+1][MAXW+1];//value with up to n items, considering a sack of w weight



ll solve(int item, int weight){

    //already found
    if(dp[item][weight] != -1){
        return dp[item][weight];
    }
    //no items considered or no weight in sub-bag
    else if (weight == 0 || item == 0){
        dp[item][weight] = 0;
        return dp[item][weight];
    }
    else{
        ll value = vals[item];
        ll mass = weights[item];

        //enough room to hold this item
        if (weight - mass >= 0){
            dp[item][weight] = max(solve(item-1, weight), solve(item-1, weight - mass) + value);
        }
        else{
            dp[item][weight] = solve(item - 1, weight);
        }


        return dp[item][weight];


    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int n, w;
    cin>>n>>w;

    for(int i = 1; i<=n; i++){
        cin>>weights[i]>>vals[i];
    }

    cout<<solve(n,w)<<endl;



    /*
    bad_allocs (need a n + w memory solution) but gives correct solution (MLE?)
    */


}
