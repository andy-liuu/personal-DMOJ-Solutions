#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//constraints
const int MAXN = 1e5;
const int MOD = 1e9 + 7;

const int BLACK = 0;
const int WHITE = 1;


/*
Given:
    - tree of n verticies

RFT:
    - # ways to color tree given no 2 black colors are adjacent

Ideas:
    - dp involves current position (head of subtree) and color of head of subtree
    - stores # ways to color subtree given color of head of subtree

    - dp[spot][color] =
        if color is white:
            multiply (dp[next][white] + dp[next][black]) for all next edges
        if color is black:
            multiply (dp[next][white]) for all next edges

    *subtrees do not interact but case is DEPENDENT :.

    - root tree @ node 1
    answer = dp[1][black] + dp[1][white]

*/

ll modnum(ll a){
    return a%MOD;
}

vector<int> graph[MAXN+1];

ll dp[MAXN+1][2];//denotes number of ways for subtree with head of [n] with color [1/2]


ll subtree(int head, int color, int prev){
    if (dp[head][color] != -1){
        return dp[head][color];
    }
    else{
        ll ans = 1;

        //cout<<head<<" "<<color<<endl;

        for(auto nex : graph[head]){

            //not allowed to go backwards and infiniloop me
            if (nex != prev){
                //cout<<head<<" "<<nex<<endl;
                ll white = subtree(nex, WHITE, head);
                ll black = subtree(nex, BLACK, head);

                if (color == WHITE){
                    ans = modnum(modnum(ans) * modnum(modnum(white)+modnum(black)));
                }

                if (color == BLACK){
                    ans = modnum(modnum(ans) * modnum(white));

                }


            }
        }

        dp[head][color] = modnum(ans);
        return dp[head][color];
    }
}



int main(void){


    ios::sync_with_stdio(0);
    cin.tie(0);


    memset(dp, -1, sizeof(dp));

    int n;
    cin>>n;

    for(int i = 0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);

    }

    cout<<modnum(modnum(subtree(1, WHITE, -1)) + modnum(subtree(1, BLACK, -1)))<<endl;




}
