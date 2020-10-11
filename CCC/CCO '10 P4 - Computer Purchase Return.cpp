#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//constraints
const int MAXT = 5;
const int MAXCI = 3000;
const int MAXVI = 3000;
const int MAXN = 1000;
const int MAXB = 3000;

//denotes max value considering first T items and B cost
int dp[MAXT+1][MAXB+1];

//parts[i] is vector that holds the
vector<pair<int,int>> parts[MAXT+1];



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    int t,n;
    cin>>t>>n;

    for(int i = 0; i<n; i++){
        int ci,vi,ti;
        cin>>ci>>vi>>ti;
        parts[ti].push_back(make_pair(ci,vi));
    }

    int b;
    cin>>b;

    for(int item = 0; item<t; item++){
        for(int cost = 0; cost <= b; cost++){
            if(dp[item][cost] != -1){
                for(auto p : parts[item+1]){
                    if(cost + p.first <= b){
                        dp[item+1][cost + p.first] = max(dp[item+1][cost + p.first], dp[item][cost]+p.second);
                    }
                }
            }
        }
    }

    int ans = -1;
    for(int i = 0; i<=b; i++){
        ans = max(ans, dp[t][i]);
    }
    cout<<ans<<endl;




}
