#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int e = 0;e<5;e++){

        int n,m;
        cin>>n>>m;

        int bills[m] = {};

        for(int q = 0;q<m;q++){
            cin>>bills[q];
        }

        int dp[n+1] = {};
        for(int i = 0;i<=n;i++){
            dp[i] = -1;
        }

        dp[0] = 0;

        for(int z = 0;z<=n;z++){
            for(int a = 0;a<m;a++){
                //can fit
                if(z-bills[a]>=0){
                    if(dp[z-bills[a]]!= -1){
                        if(dp[z] == -1){
                            dp[z] = dp[z-bills[a]]+1;
                        }
                        else{
                            dp[z] = min(dp[z],dp[z-bills[a]]+1);
                        }

                    }
                }
            }
        }
        cout<<dp[n]<<endl;

    }

}
