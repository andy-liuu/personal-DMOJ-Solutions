#include <bits/stdc++.h>
using namespace std;

//constraints
const int MAXN = 10000;
const int MAXC = 1e5;
const int MAXK = 1e5;

//[node] is number of cherries at the node
int cherries[MAXN+1];

//(node, weight)
vector<pair<int,int>> tree[MAXN+1];


int prevbranch[MAXN+1];//weight of branch that goes to this node (tree so only one guaranteed)

int dp[MAXN+1][2];//denotes number of cherries and weight of branches of subtree at node i (does not include prev branch)


//recursive functions to find weight of branches (not including prev) and number of cherries a given node subtree has
pair<int,int> data(int node){
    //already found
    if(dp[node][0] != -1 && dp[node][1] != -1){
        return make_pair(dp[node][0], dp[node][1]);
    }
    else{
        int totw = 0, totcherry = 0;
        for(auto p : tree[node]){
            pair<int,int> nex = data(p.first);


            totw += nex.first;
            totcherry += nex.second;
        }

        dp[node][0] = totw + prevbranch[node];
        dp[node][1] = totcherry + cherries[node];

        return make_pair(dp[node][0],dp[node][1]);
    }


}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, c, k;
    cin>>n>>c>>k;

    //get cherries on each patch
    for(int i = 1; i<=n; i++){
        cin>>cherries[i];
    }

    memset(dp, -1, sizeof(dp));

    //input and make tree
    for(int i = 0; i<n-1; i++){
        int ai,bi,ki;
        cin>>ai>>bi>>ki;

        if (bi > ai) swap(ai,bi);

        tree[bi].push_back(make_pair(ai,ki));
        prevbranch[ai] = ki;
    }

    /*
    for(int i = 1; i<= n; i++){
        cout<<"Node "<<i<<" ";
        for(auto j : tree[i]){
            cout<<"( "<<j.first<<" "<<j.second<<" )"<<" , ";
        }
        cout<<endl;
    }

    cout<<data(7).first<<" "<<data(7).second<<endl;
    */

    int ans = 0;
    for(int poss = 2; poss <= n; poss++){
        pair<int,int> d = data(poss);
        if (d.first <= k && d.second >= c){
            ans++;
        }
    }
    cout<<ans<<endl;








}
