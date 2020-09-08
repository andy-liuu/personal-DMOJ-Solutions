#include <bits/stdc++.h>
using namespace std;

//implement union-find
class UnionFind{
public:
    int *link;
    int *sz;

    UnionFind(int len){
        link = new int[len];
        sz = new int[len];

        for(int i = 0; i<len; i++){
            link[i] = i;
            sz[i] = 1;
        }
    }
    ~UnionFind(){
        delete [] link;
        delete [] sz;
    }
    int find(int p){
        int root = p;
        while(root != link[root])root = link[root];

        //path compression part
        while(p != root){
            int next = link[p];
            link[p] = root;
            p = next;
        }

        return root;
    }
    bool same(int a, int b){
        return find(a)==find(b);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a]<sz[b])swap(a,b);
            link[b] = a;
            sz[a] += sz[b];
        }
    }
    int size(int a){
        return sz[find(a)];
    }

};

int main(void){
    int n,m;
    cin>>n>>m;

    UnionFind sets(n+1);

    for(int i = 0; i<m; i++){
        int k;
        cin>>k;

        int head;
        for(int j = 0; j<k; j++){
            int pers;
            cin>>pers;
            if(j == 0)head = pers;
            sets.unite(head,pers);


        }

    }
    cout<<sets.size(1)<<endl;
    for(int i = 1; i<=n; i++){
        if(sets.same(1,i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;


}
