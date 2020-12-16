#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000000;
const int MAXK = 500000;

struct Node{

    //DO NOT STORE L AND R, BUT ALWAYS KEEP TRACK OF THEM WHEN YOU RECURSE DOWN THE TREE
    int maxval = 0, minval = 0;
    int lazyraise = 0, lazyfall = 0;
    bool changeNeeded = false;

}seg[4*MAXN + 1];

/*
All heights start at 0;
*/

void updateLazy(int v, int raisepoten, int fallpoten){

    //make sure there are no conflictions
    //where raisepoten > fallpoten and values get shifted twice

    //updating a raise value
    seg[v].lazyraise = max(seg[v].lazyraise, raisepoten);
    seg[v].lazyfall = max(seg[v].lazyfall, raisepoten);

    //updating a fall value
    seg[v].lazyfall = min(seg[v].lazyfall, fallpoten);
    seg[v].lazyraise = min(seg[v].lazyraise, fallpoten);

    seg[v].changeNeeded = true;
}

void pushLazy(int v, int L, int R){
    int lazyraise = seg[v].lazyraise;
    int lazyfall = seg[v].lazyfall;

    //push to shildren if there are children
    if(L != R){
        updateLazy(2*v, lazyraise, lazyfall);
        updateLazy(2*v+1, lazyraise, lazyfall);
    }

    //reset to defaults
    seg[v].lazyraise = 0;
    seg[v].lazyfall = INT_MAX;
    seg[v].changeNeeded = false;


}

void changeWithLazy(int v){
    //anything above lazyfall gets fallen to lazyfall
    seg[v].maxval = min(seg[v].maxval, seg[v].lazyfall);
    seg[v].minval = min(seg[v].minval, seg[v].lazyfall);

    //anything below lazyraise is raised to lazyraise
    seg[v].maxval = max(seg[v].maxval, seg[v].lazyraise);
    seg[v].minval = max(seg[v].minval, seg[v].lazyraise);

}



void update(int v, int op, int val, int UL, int UR, int L, int R){

    //if a lazy value exists
    if(seg[v].changeNeeded){
        changeWithLazy(v);
        pushLazy(v, L, R);
    }
    else{
        seg[v].lazyfall = INT_MAX;
    }


    //out of range
    if (UR < L || R < UL){
        return;
    }

    //completely inside the range
    if(UL <= L && R <= UR){
        //raise value
        if(op == 1){
            updateLazy(v, val, INT_MAX);
        }
        //fall value
        if(op == 2){
            updateLazy(v, 0, val);
        }
        seg[v].changeNeeded = true;
        changeWithLazy(v);
        pushLazy(v, L, R);

        return;



    }

    //recurse here
    update(2*v, op, val, UL, UR, L, (L+R)/2);
    update(2*v+1, op, val, UL, UR, (L+R)/2 + 1, R);

    //combine the nodes
    seg[v].maxval = max(seg[2*v].maxval, seg[2*v+1].maxval);
    seg[v].minval = min(seg[2*v].minval, seg[2*v+1].minval);


}

int querySpot(int v, int spot, int L, int R){

    //if a lazy value exists
    if(seg[v].changeNeeded){
        changeWithLazy(v);
        pushLazy(v, L, R);
    }
    else{
        seg[v].lazyfall = INT_MAX;
    }

    if(L == spot && R == spot){
        return seg[v].maxval; //only one guy left denoted my maximum or minimum value
    }

    //every guy in the subreange is equal then the guy u want is equal to the value u know

    //and if you are in range

    if (L <= spot && spot <= R){
        if(seg[v].maxval == seg[v].minval){
            return seg[v].minval;
        }
    }

    int mid = (L + R)/2;
    //left subchild
    if(L <= spot && spot <= mid){
        return querySpot(2*v, spot, L, mid);
    }
    //right subchild
    else if (mid+1 <= spot && spot <= R){
        return querySpot(2*v+1, spot, mid+1, R);
    }
    //out of bounds should never happen
    else{
        return 0;
    }

}


void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    for(int q = 0; q<k; q++){

        update(1, op[q], height[q], left[q], right[q], 0, n-1);

    }

    for(int i = 0; i<n; i++){
        finalHeight[i] = querySpot(1, i, 0, n-1);
    }

}






