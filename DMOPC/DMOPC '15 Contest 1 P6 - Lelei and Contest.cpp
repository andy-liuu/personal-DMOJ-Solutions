#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

int arr[MAXN+1];//one indexed


int m,n,q;

int mod(int num){
    return num%m;
}

int modAdd(int a, int b){
    return (a%m + b%m)%m;
}

int modMult(int a, int b){
    return ((a%m) * (b%m))%m;
}


struct Node{
    int L,R;
    int sum;
    int lazy = 0;
} seg[4*MAXN + 1];


//combines V's 2 children into node V
void combineNodes(int v){
    seg[v].sum = modAdd(seg[2*v].sum, seg[2*v+1].sum);
}

void buildTree(int v, int L, int R){
    seg[v].L = L;
    seg[v].R = R;

    if(L == R){
        seg[v].sum = mod(arr[L]);
        return;
    }
    else{
        int mid = (L + R)/2;

        buildTree(2*v, L, mid);
        buildTree(2*v+1, mid+1, R);

        combineNodes(v);
    }
}

void pushLazy(int v){
    int L = seg[v].L;
    int R = seg[v].R;

    if (L != R){
        seg[2*v].lazy = modAdd(seg[2*v].lazy, seg[v].lazy);
        seg[2*v+1].lazy = modAdd(seg[2*v+1].lazy, seg[v].lazy);
    }
    seg[v].lazy = 0;
}

void changeWithLazy(int v){


    int lazy = seg[v].lazy;


    if (lazy == 0){
        return;
    }
    else{

        int L = seg[v].L;
        int R = seg[v].R;

        seg[v].sum = modAdd(seg[v].sum, modMult(R-L+1, lazy));

    }
}





void updateRange(int v, int UL, int UR, int add){
    int L = seg[v].L;
    int R = seg[v].R;

    changeWithLazy(v);
    pushLazy(v);

    //out of range
    if(UR < L || R < UL){
        return;
    }

    //in range completely
    if(UL <= L && R <= UR){
        //push lazy value
        seg[v].lazy = mod(add);

        changeWithLazy(v);
        pushLazy(v);
        return;
    }

    //update subtrees
    updateRange(2*v, UL, UR, add);
    updateRange(2*v+1, UL, UR, add);



    //combine 2 children into parent
    combineNodes(v);

}

int query(int v, int QL, int QR){
    int L = seg[v].L;
    int R = seg[v].R;


    changeWithLazy(v);
    pushLazy(v);

    if (QR < L || R < QL){
        return 0;
    }

    if (QL <= L && R <= QR){
        return mod(seg[v].sum);
    }

    return modAdd(query(2*v, QL, QR), query(2*v+1, QL, QR));
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //get inputs
    cin>>m>>n>>q;
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    buildTree(1, 1, n);

    int type, left, right, add;

    for(int quer = 0; quer < q; quer++){
        cin>>type;

        if(type == 1){

            cin>>left>>right>>add;

            //do update query with lazy prop
            updateRange(1, left, right, add);
        }
        else if (type == 2){
            cin>>left>>right;

            //cout the query sum from right to left
            cout<<query(1, left, right)<<"\n";
        }

    }




}
