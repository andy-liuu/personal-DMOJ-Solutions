#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int sizes[3];

    for(int i = 0;i<3;i++){
        cin>>sizes[i];
    }

    int dp[n+1] = {};
    for(int e = 0;e<=n;e++){
        dp[e] = -1;
    }
    dp[0] = 0;

    for(int q = 1;q<=n;q++){

        for(int w : sizes){
            if (q-w>=0){
                if (dp[q-w] != -1){
                    dp[q] = max(dp[q],dp[q-w]+1);
                }
            }
        }

    }
    cout<<dp[n]<<endl;

}
