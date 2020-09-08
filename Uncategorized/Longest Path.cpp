#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb(i) push_back(i);

const int MAXN = 1e5;
const int MAXM = MAXN;

vi graph[MAXN+1];

int dp[MAXN+1] = {};

int findlong(int val){
    if(dp[val] != -1){
        return dp[val];
    }
    else{
        int ans = -1;
        for (auto i : graph[val]){
            ans = max(findlong(i), ans);
        }
        dp[val] = ans+1;
        return dp[val];
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    int n,m;
    cin>>n>>m;

    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
    }

    int big = -1;

    for(int i = 1; i<=n; i++){
        big = max(big, findlong(i));
    }
    cout<<big<<endl;


}
