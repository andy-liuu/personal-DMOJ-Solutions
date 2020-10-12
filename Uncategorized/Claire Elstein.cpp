#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//CONSTRAINTS
const int MAXN = 100000;//number of nodes
const int MAXM = 500000;//number of edges
const int MOD = 1e9 + 7;

/*
Given:
    - Directed acyclic graph

RFT:
    - sum of paths between all starting to ending nodes

Ideas:
    - topological sort? makes linear array
    - * NOT NEEDED SINCE SMALLER NODES ALWAYS GO TO LARGER NODES
    dp:
    - for all node in topsort:
        add running total sum to connected nodes
        if no connected nodes, add that total to ans sum

*/


vector<int> graph[MAXN+1];
int indegree[MAXN+1];
int outdegree[MAXN+1];





//dp data
ll sums[MAXN+1] = {};
ll numstarts[MAXN+1] = {};

ll modnum(ll x){
    return x%MOD;
}

int main(void){

    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));



    ios::sync_with_stdio(0);
    cin.tie(0);



    int n,m;
    cin>>n>>m;

    //make graph
    for(int q = 0; q<m; q++){
        int i,j;
        cin>>i>>j;
        graph[i].push_back(j);
        indegree[j]++;
        outdegree[i]++;
    }


    //dp time
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        int node = i;



        //node is starting node
        if(indegree[node] == 0){
            numstarts[node] = 1;
        }

        //keep running totals
        for(auto next : graph[node]){
            sums[next] = modnum(modnum(sums[node]) + modnum(sums[next]) + modnum(numstarts[node]));
            numstarts[next] = modnum(modnum(numstarts[node]) + modnum(numstarts[next]));
        }

        //node is ending node, sum already computed
        if(outdegree[node] == 0){
            ans = modnum(ans + modnum(sums[node]));
        }


    }

    cout<<modnum(ans)<<endl;



}
