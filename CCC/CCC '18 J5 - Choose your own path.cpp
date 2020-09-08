#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){


    int n;
    cin>>n;

    vector<int> graphs[n];

    //make graph
    for(int i = 0;i<n;i++){

        int nums;cin>>nums;
        for(int q = 0;q<nums;q++){
            int temp;cin>>temp;
            graphs[i].push_back(temp-1);
        }

    }

    //dijtra from 0
    int shorts[n];
    for(int i = 0;i<n;i++){
        shorts[i] = INT_MAX;
    }
    shorts[0] = 1;

    queue<int> points;

    points.push(0);

    while (!points.empty()){


        int cur = points.front();
        points.pop();

        for(int i = 0;i<graphs[cur].size();i++){

            int next = graphs[cur].at(i);
            if (shorts[next] >= shorts[cur] + 1){
                shorts[next] = shorts[cur] + 1;
                points.push(next);
            }


        }

    }

    //find min and see if all are visited
    bool visited = true;
    int smallest = INT_MAX;
    for(int i = 0;i<n;i++){
        if (shorts[i] == INT_MAX){
            visited = false;
        }

        if (shorts[i] < smallest && graphs[i].size() == 0){
            smallest = shorts[i];
        }

    }


    if (visited){
        cout<<"Y"<<endl;
    }
    else{
        cout<<"N"<<endl;
    }

    cout<<smallest<<endl;


}
