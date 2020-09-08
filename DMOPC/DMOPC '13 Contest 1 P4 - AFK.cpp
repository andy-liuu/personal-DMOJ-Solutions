#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
const int maxL = 50;
const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


char graph[maxL][maxL];//[length][width]
int dist[maxL][maxL];

int main(void){
    int tests;
    cin>>tests;

    //testcases here
    for(int qwe = 0; qwe<tests; qwe++){


        //reset graph
        for(int i = 0; i<maxL; i++){
            for(int j = 0; j<maxL; j++){
                graph[i][j] = 'T';
                dist[i][j] = INF;
            }

        }

        //input
        int l,w;
        cin>>l>>w;


        int startL, startW;
        int endL, endW;

        for(int i = 0; i<w; i++){
            string temp;
            cin>>temp;

            for(int j = 0; j<l; j++){
                graph[j][i] = temp[j];

                if(temp[j] == 'C'){
                    startL = j;
                    startW = i;
                    dist[j][i] = 0;
                }

                if(temp[j] == 'W'){
                    endL = j;
                    endW = i;
                }
            }
        }



        //do bfs

        queue<pair<int,int>> q;
        q.push(make_pair(startL, startW));

        while(!q.empty()){
            pair<int,int> s = q.front(); q.pop();
            int curx = s.first;
            int cury = s.second;

            //calculate next node
            for(int i = 0; i<4; i++){
                int nexx = curx+dirs[i][0];
                int nexy = cury+dirs[i][1];

                //check for bounds
                if (nexx>=0 && nexx < l && nexy>=0 && nexy<w ){

                    //check for validity
                    if(graph[nexx][nexy] != 'X' && dist[nexx][nexy] == INF && dist[curx][cury] + 1 < 60){
                        dist[nexx][nexy] = dist[curx][cury] + 1;
                        q.push(make_pair(nexx, nexy));
                    }
                }
            }
        }


        //output
        if(dist[endL][endW] == INF){
            cout<<"#notworth"<<endl;
        }
        else{
            cout<<dist[endL][endW]<<endl;
        }

    }


}
