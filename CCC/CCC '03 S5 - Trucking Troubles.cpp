#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
const int maxC = 10000;
const int maxR = 100000;

vector<pair<int,int>> graph[maxC+1];
vector<int> dests;

int bests[maxC+1];

int main(void){

    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i<=maxC; i++){
        bests[i]=INF;
    }


    //get input and make adjacency lists for graph
    int c,r,d;
    cin>>c>>r>>d;
    for(int i = 0; i<r; i++){

        int start, en, weight;
        cin>>start>>en>>weight;

        graph[start].push_back(make_pair(en,weight));
        graph[en].push_back(make_pair(start, weight));
    }

    //store destination cities
    for(int i = 0; i<d; i++){
        int temp;
        cin>>temp;
        dests.push_back(temp);
    }


    /*
    modified version of BFS shortest path tracks smallest bridge capacityon a path aka max weight along the path
    and optimizes for biggest smallest bridge
    */


    queue<pair<int,int>> q;//<next node, weight of gridge to node
    q.push({1,0});

    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();

        int curnode = cur.first;
        int curweight = cur.second;

        for(int wer = 0; wer<graph[curnode].size(); wer++){
            int nexnode = graph[curnode].at(wer).first;
            int nexweight = graph[curnode].at(wer).second;




            //not visited yet
            if(bests[nexnode] == INF){
                bests[nexnode] = min(bests[curnode], nexweight);
                q.push({nexnode, nexweight});
            }
            else if (bests[nexnode] < min(bests[curnode], nexweight)){
                bests[nexnode] = min(bests[curnode], nexweight);
                q.push({nexnode, nexweight});

            }





        }


    }

    int ans = INF;
    for(int i = 0; i<dests.size(); i++){
        ans = min(ans, bests[dests.at(i)]);
    }
    cout<<ans<<endl;


}
