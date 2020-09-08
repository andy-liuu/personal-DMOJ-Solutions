#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m,a,b;
    cin>>n>>m>>a>>b;

    int sum = 0;

    vector<int> graph[n+1];

    for(int i = 0;i<m;i++){
        int st,en;
        cin>>st>>en;
        graph[st].push_back(en);
        graph[en].push_back(st);
    }

    //do distra from 1 -> a
    queue<int> pts;
    pts.push(1);

    int dists[n+1];
    for(int i = 0;i<=n;i++){
        dists[i] = INT_MAX;
    }
    dists[1] = 0;

    while (!pts.empty()){
        int cur;
        cur = pts.front();
        pts.pop();

        for(int i = 0;i<graph[cur].size();i++){
            int nex = graph[cur].at(i);
            if(dists[cur] + 1 < dists[nex]){
                pts.push(nex);
                dists[nex] = dists[cur] + 1;
            }
        }

    }

    if (dists[a] != INT_MAX){
        sum += dists[a];
    }
    else{
        sum = -1;
    }



    //from a to b
    pts.push(a);


    for(int i = 0;i<=n;i++){
        dists[i] = INT_MAX;
    }
    dists[a] = 0;

    while (!pts.empty()){
        int cur;
        cur = pts.front();
        pts.pop();

        for(int i = 0;i<graph[cur].size();i++){
            int nex = graph[cur].at(i);
            if(dists[cur] + 1 < dists[nex]){
                pts.push(nex);
                dists[nex] = dists[cur] + 1;
            }
        }

    }

    if (sum != -1 && dists[b] != INT_MAX){
        sum += dists[b];
    }

    cout<<sum<<endl;












}
