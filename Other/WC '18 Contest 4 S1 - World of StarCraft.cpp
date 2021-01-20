#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int MAXM = 100000;
const int MAXK = 100000;


int link[MAXN+1]; //one indexed
int sz[MAXN + 1]; //one indexed

int find(int x){
    int root = x;
    while(root != link[root]) root = link[root];

    while(x != root){
        int nex = link[x];
        link[x] = root;
        x = nex;
    }

    return root;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(sz[a] < sz[b]) swap(a,b);//makes a group larger than b group

    link[b] = a;
    sz[a] += sz[b];


}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    string factions;
    cin>>factions;

    //init link and sz
    for(int i = 0;i<=n; i++){
        link[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i<m; i++){
        //join space routes IF they are the same faction
        int a,b;
        cin>>a>>b;

        //same faction
        if (factions[a-1] == factions[b-1]){
            //not already connected
            if (!same(a,b)){
                unite(a,b);
            }

        }

    }

    int ans = 0;
    for(int i = 0; i<k; i++){

        int start, dest;
        cin>>start>>dest;
        if(same(start,dest)){
            ans++;
        }

    }
    cout<<ans<<endl;








}
