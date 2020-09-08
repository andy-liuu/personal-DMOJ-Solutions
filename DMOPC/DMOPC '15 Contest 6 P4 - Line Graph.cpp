#include <bits/stdc++.h>
using namespace std;

const int maxN = 100000;
const int maxK = 100000;

int link[maxN];
int setsize[maxN];




priority_queue<tuple<int,int,int>> edges;//weight, end1, end2
long long ans = 0;

//functions for the union-find structure
int findrep(int x){
    while( x != link[x]) x = link[x];
    return x;
}
bool sameset(int a, int b){
    return findrep(a) == findrep(b);
}
void unite(int a, int b){
    a = findrep(a);
    b = findrep(b);
    if(setsize[a] < setsize[b]) swap(a,b);

    setsize[a] += setsize[b];
    link[b] = a;
}


int main(void){



    int n, k;
    cin>>n>>k;

    //make edge list, get input
    for(int i = 0; i<n-1; i++){
        int weight;
        cin>>weight;

        edges.push(make_tuple(-weight, i, i+1));
        if(i + k < n){
            edges.push(make_tuple(0,i,i+k));
        }

    }

    //initialize link and setsize for union-find structure
    for(int i = 0; i<n; i++){
        link[i] = i;
        setsize[i] = 1;
    }


    //kruskal's alg for mst
    //use union-find structure to make kruskal's alg more efficient



    while(!edges.empty()){
        tuple<int,int,int> current = edges.top();
        edges.pop();

        int a = get<1>(current);
        int b = get<2>(current);

        if(!sameset(a,b)){
            unite(a,b);
            ans -= get<0>(current);
        }


    }

    cout<<ans<<endl;


}
