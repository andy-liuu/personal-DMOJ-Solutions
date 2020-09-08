#include <bits/stdc++.h>
using namespace std;
long long  n;
int main(){
    //set up inputs and dp arrays
    cin>>n;

    long long items[n+1];
    for(int i = 1;i<=n;i++){
        cin>>items[i];
    }

    long long dp[n+1] = {};
    dp[1] = items[1];

    for(int q = 2;q<=n;q++){
        dp[q] = max(dp[q-1],max(dp[q-2]+items[q],max(dp[q-2],items[q])));

    }
    cout<<dp[n]<<endl;
}
