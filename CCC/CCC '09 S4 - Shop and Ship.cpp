#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const int MAXN = 5000;
const int MAXT = 25000000;
const int MAXP = 10000;


int graph[MAXN+1][MAXN+1] = {};
//matrix representation for graph
int price[MAXN+1] = {};

priority_queue<pll, vector<pll>, greater<pll>> pq;//stores [best-so-far, node]
ll bests[MAXN+1];

bool visited[MAXN+1] = {};

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);


    //initialzation
    for(int i = 0; i<=MAXN; i++){
        price[i] = INT_MAX;
        bests[i] = LLONG_MAX;
        for(int j = 0; j<=MAXN; j++){
            graph[i][j] = INT_MAX;
        }
    }

    int n;
    cin>>n;

    //input and make graph
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int x, y, cost;
        cin>>x>>y>>cost;
        graph[x][y] = min(graph[x][y], cost);
        graph[y][x] = min(graph[y][x], cost);
    }


    //input destination prices;
    int k;
    cin>>k;
    for(int i = 0; i<k; i++){
        int z, pz;
        cin>>z>>pz;
        price[z] = min(price[z], pz);
    }

    int d;
    cin>>d;

    //run shortest path from destination outwards
    bests[d] = 0;
    pq.push(make_pair(0, d));

    while(!pq.empty()){
        ll sofar = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        visited[cur] = true;

        if(bests[cur] < sofar){

        }
        else{
            for(int nex = 1; nex <= n; nex++){
                if(!visited[nex]){
                    ll newdist = bests[cur] + graph[cur][nex];
                    if(newdist < bests[nex]){
                        bests[nex] = newdist;
                        pq.push(make_pair(newdist, nex));
                    }
                }
            }
        }










    }


    ll ans = LLONG_MAX;
    for(int i = 1; i<=n; i++){
        if (price[i] != INT_MAX && bests[i] != LLONG_MAX){
            ans = min(ans, (ll)price[i] + bests[i]);
        }
    }

    cout<<ans<<endl;









}
