#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define check(num, pos) ((num) & (1<<(pos)))

const int MAXN = 21;
int n;

int compat[MAXN][MAXN];//woman, man
int dp[(1<<MAXN+1)];

//n is the bitset of remaining men to be unmatched
//always try unmatching with the nth woman aka match the woman in order
int solve(int menset, int woman){
    if(dp[menset] != -1){
        return dp[menset];
    }
    else if (menset == 0){
        dp[menset] = 1;
        return dp[menset];
    }
    else{

        int sum = 0;

        //try matching this woman with every remaining man
        for(int man = 0; man<n; man++){
            if (compat[woman][man] == 1 && check(menset, man)){
                int newset = (menset&~(1<<man));
                sum += solve(newset, woman+1);
                sum %= MOD;
            }
        }

        dp[menset] = sum;
        return dp[menset];
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>compat[i][j];
        }
    }
    cout<<solve((1<<n)-1, 0)<<endl;
}
