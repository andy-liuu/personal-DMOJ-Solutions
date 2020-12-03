#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100000;
const int MAXM = 500000;

int GCD(int a, int b) {
    if (b == 0) return a;
    if (a == 0) return b;
    return GCD(b%a, a);
}


int arr[MAXN+2];

struct Node{
    int L,R;

    int maxval, minval, gcdval;
};
Node tree[4*MAXN+1];

void build(int v, int L, int R){
    tree[v].L = L;
    tree[v].R = R;

    if(L == R){
        tree[v].maxval = arr[L];
        tree[v].minval = arr[L];
        tree[v].gcdval = arr[L];
    }
    else{
        int mid = (L + R)/2;
        build(2*v, L, mid);
        build(2*v+1, mid+1, R);

        tree[v].maxval = max(tree[2*v].maxval, tree[2*v+1].maxval);
        tree[v].minval = min(tree[2*v].minval, tree[2*v+1].minval);
        tree[v].gcdval = GCD(tree[2*v].gcdval, tree[2*v+1].gcdval);

    }
}

int queryMin(int v, int QL, int QR){
    int L = tree[v].L;
    int R = tree[v].R;

    //out of range
    if(QR < L || R < QL){
        return INT_MAX;
    }
    //completely inside range
    else if (QL <= L && R <= QR){
        return tree[v].minval;
    }
    else{
        return min(queryMin(2*v, QL, QR), queryMin(2*v+1, QL, QR));
    }
}

int queryGCD(int v, int QL, int QR){
    int L = tree[v].L;
    int R = tree[v].R;

    //out of range
    if(R < QL || QR < L){
        return 0;
    }
    //completely inside query range
    else if (QL <= L && R <= QR){
        return tree[v].gcdval;
    }
    else{
        return GCD(queryGCD(2*v, QL, QR), queryGCD(2*v+1, QL, QR));
    }
}

int queryFind(int v, int QL, int QR, int want){
    int L = tree[v].L;
    int R = tree[v].R;

    //out of range
    if(R < QL || QR < L){
        return 0;
    }
    //no people in this segment is equal to the value
    if (tree[v].maxval < want || want < tree[v].minval){
        return 0;
    }
    //every person in this segment is equal to the guy u want (also has to be completely in range)
    if (QL <= L && R <= QR){
        if (tree[v].minval == want && tree[v].maxval == want){
            return R - L + 1;
        }
    }

    return queryFind(2*v, QL, QR, want) + queryFind(2*v+1, QL, QR, want);


}

void update(int v, int idx, int newval){
    int L = tree[v].L;
    int R = tree[v].R;

    //out of range
    if(idx < L || R < idx){
        return;
    }
    else if (L == idx && R == idx){
        tree[v].maxval = newval;
        tree[v].minval = newval;
        tree[v].gcdval = newval;
        return;
    }
    else{
        update(2*v, idx, newval);
        update(2*v+1, idx, newval);

        tree[v].maxval = max(tree[2*v].maxval, tree[2*v+1].maxval);
        tree[v].minval = min(tree[2*v].minval, tree[2*v+1].minval);
        tree[v].gcdval = GCD(tree[2*v].gcdval, tree[2*v+1].gcdval);
        return;
    }
}






int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    build(1, 1, n);

    for(int qwe = 0; qwe < m; qwe++){
        char a;
        int b,c;
        cin>>a>>b>>c;
        if (a == 'C'){
            arr[b] = c;
            update(1, b,c);
        }
        else if (a == 'M'){
            cout<<queryMin(1, b, c)<<endl;
        }
        else if (a == 'G'){
            cout<<queryGCD(1,b,c)<<endl;
        }
        else if (a == 'Q'){
            int val = queryGCD(1,b,c);
            cout<<queryFind(1, b, c, val)<<endl;

        }

    }





}
