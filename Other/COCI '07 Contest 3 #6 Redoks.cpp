#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250000;
const int MAXM = 100000;


string line;

struct Node{
    int L,R;
    int freq[10];
    int lazy;
} tree[4*MAXN + 1];

//combines data from 2 childrens
void combineNodes(int v){
    for(int i = 0; i<=9; i++){
        tree[v].freq[i] = tree[v*2].freq[i] + tree[v*2+1].freq[i];
    }
}



void build_tree(int v, int L, int R){
    tree[v].L = L;
    tree[v].R = R;
    tree[v].lazy = 0;

    if(L == R){
        int val = line[L-1]-'0';
        tree[v].freq[val] = 1;
        return;
    }
    else{
        int mid = (L + R)/2;
        build_tree(v*2, L, mid);
        build_tree(v*2+1, mid+1, R);

        combineNodes(v);
    }
}

//pushes lazy value to children
void pushLazy(int v){
    //not child node
    if (tree[v].L != tree[v].R){
        tree[v*2].lazy = (tree[v*2].lazy + tree[v].lazy)%10;
        tree[v*2+1].lazy = (tree[v*2+1].lazy + tree[v].lazy)%10;
    }

    tree[v].lazy = 0;
}

void changeWithLazy(int v){
    int lazy = tree[v].lazy;

    //only do change if you have a lazy value
    if (lazy != 0){
        int temp[10];
        for(int i = 0; i<=9; i++){
            temp[(i+lazy)%10] = tree[v].freq[i];
        }

        for(int i = 0; i<=9; i++){
            tree[v].freq[i] = temp[i];
        }
    }
}

void updateRange(int v, int UL, int UR){
    int L = tree[v].L;
    int R = tree[v].R;



    //node range outside of update range
    if (UR < L || R < UL){
        return;
    }

    //note range completely inside of update range
    if(UL <= L && R <= UR){
        tree[v].lazy++;
        tree[v].lazy %= 10;



        return;
    }

    updateRange(v*2, UL, UR);
    updateRange(v*2+1, UL, UR);


    changeWithLazy(v*2);
    pushLazy(v*2);

    changeWithLazy(v*2+1);
    pushLazy(v*2+1);



    combineNodes(v);
    return;

}

int query(int v, int QL, int QR){

    int L = tree[v].L;
    int R = tree[v].R;

    changeWithLazy(v);
    pushLazy(v);

    //out of range
    if (QR < L || R < QL){
        return 0;
    }

    if(QL <= L && R <= QR){
        int sum = 0;
        for(int i = 0; i<=9; i++){
            sum += (i * tree[v].freq[i]);
        }
        return sum;
    }

    return query(2*v, QL, QR) + query(2*v+1, QL, QR);

}





int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    cin>>line;

    build_tree(1, 1, n);

    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<query(1, a, b)<<endl;
        updateRange(1, a, b);
    }


}
