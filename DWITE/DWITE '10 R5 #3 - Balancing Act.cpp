#include <bits/stdc++.h>

using namespace std;

#define maxN 30
#define maxS 30000




int main(void){

    for(int q = 0; q<5; q++){



    int grid[maxN + 1] = {};

    bool dp[maxN + 1][maxS + 1] = {};

    int n;
    cin>>n;

    int sum = 0;
    for(int i = 1; i<=n; i++){
        int temp;
        cin>>temp;
        grid[i] = temp;
        sum += temp;
        dp[i][0] = true;
    }
    dp[0][0] = true;


    for (int i = 1; i <= n; i++){
        for (int j = 1; j<= sum; j++){

           bool exclude = dp[i-1][j];
           bool include = false;

           if (grid[i] <= j){
                include = dp[i-1][j - grid[i]];
           }



           if (exclude || include){
                dp[i][j] = true;
           }

        }

    }

    int ans = INT_MAX;

    for (int j=sum/2; j>=0; j--) {

        if (dp[n][j] == true) {
            ans = sum-2*j;
            break;
        }
    }

    cout<<ans<<endl;

    }






}
