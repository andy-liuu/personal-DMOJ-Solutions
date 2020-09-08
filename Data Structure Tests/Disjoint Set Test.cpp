#include <bits/stdc++.h>
using namespace std;


const int maxN = 100000;
const int maxM = 1000000;

//union-find set implementation
int link[maxN+1];
int size[maxN+1];

int find(int x){
    while (x != link[x]) x = link[x];
    return x;
}

int isSame(int a, int b){
    return find(a) == find(b);

}

void unite(int a, int b){
    a = find(a);
    b = find(b);


    //a is larger than b
    if(size[a] < size[b]) swap(a,b);

    //the leader of b family is now the leader of a
    link[b] = a;
    size[a] += size[b];



}


//graph
vector<pair<int,int>> edges;



int main(void){

    cin.sync_with_stdio(0);
    cin.tie(0);

    //get inputs
    int n,m;
    cin>>n>>m;

    //initialize the union-find set
    for(int i = 0; i<=n; i++){
        link[i] = i;
        size[i] = 1;
    }

    for(int i = 0; i<m; i++){
        int tempa, tempb;
        cin>>tempa>>tempb;

        edges.push_back(make_pair(tempa, tempb));


    }

    vector<int> answer;
    int numanswer = 0;

    for(int i = 0; i<m; i++){
        pair<int,int> cur = edges.at(i);

        if(!isSame(cur.first, cur.second)){
            unite(cur.first, cur.second);
            answer.push_back(i+1);
            numanswer++;

        }

    }

    if(numanswer != n-1){
        cout<<"Disconnected Graph"<<endl;
    }
    else{
        for(auto i : answer){
            cout<<i<<endl;
        }
    }





}
