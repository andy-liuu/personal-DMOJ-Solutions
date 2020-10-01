#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int arr[MAXN+1];
int dp[MAXN+1];

int solve(int id){

    if(dp[id] != -1){
        return dp[id];
    }
    else if (id < 2){
        return dp[id];
    }
    else{
        dp[id] = max(solve(id-1), solve(id-2)+arr[id]);
        return dp[id];
    }


}

int main(void){


    ios::sync_with_stdio(0);
    cin.tie(0);


    memset(dp, -1, sizeof(dp));

    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[1];



    cout<<solve(n-1)<<endl;






}
