#include <bits/stdc++.h>
using namespace std;


const int MAXN = 20;
const int MAXK = 30;

int ans = 0;


vector<int> graph[MAXN+1];

/*
//need to find the number of nodes involved in a cycle
- directed graph



*/
bool foundcycle;

bool visited[MAXN+1] = {};

void loop(int start, int cur){
    if (start == cur || foundcycle){
        foundcycle = true;
        return;
    }
    else if (visited[cur]){
        return;
    }
    else{
        visited[cur] = true;
        for(auto nex : graph[cur]){
            loop(start, nex);
        }
        visited[cur] = false;
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    //make graph
    for(int i = 0; i<k; i++){
        int a,b,sa,sb;
        cin>>a>>b>>sa>>sb;
        if(sb>sa) swap(a,b);//force a to be bigger than b
        graph[a].push_back(b);

    }

    for(int i = 1; i<=n; i++){
        foundcycle = false;
        for(auto nex : graph[i]){
            loop(i,nex);
        }

        if (foundcycle){
            ans++;
        }
    }

    cout<<ans<<endl;



}
