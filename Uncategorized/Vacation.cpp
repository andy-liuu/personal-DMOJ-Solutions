#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;
    cin>>n;
    int acts[3][n+1];

    acts[0][0] = 0;
    acts[1][0] = 0;
    acts[2][0] = 0;
    for(int i = 1;i<= n;i++){
        cin>>acts[0][i]>>acts[1][i]>>acts[2][i];
    }



    //init all to 0
    int dp[3][n+1];
    for(int w = 0;w<=n;w++){
        for(int a = 0;a<3;a++){
            dp[a][w] = 0;
        }

    }

    //loop thru days

    for(int q = 1;q<=n;q++){
        dp[0][q] = max(dp[0][q],acts[0][q] + max(dp[1][q-1],dp[2][q-1]));
        dp[1][q] = max(dp[1][q],acts[1][q] + max(dp[0][q-1],dp[2][q-1]));
        dp[2][q] = max(dp[2][q],acts[2][q] + max(dp[1][q-1],dp[0][q-1]));
    }


    cout<<max(dp[0][n],max(dp[1][n],dp[2][n]))<<endl;


}
