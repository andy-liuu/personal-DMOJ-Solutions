#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXK = 1e5;

bool states[MAXK+1] = {};
unordered_set<int> opts;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n,k;
    cin>>n>>k;

    while(n--){
        int temp;
        cin>>temp;
        opts.insert(temp);
    }

    for(int i = 1; i<=k; i++){

        bool ans = false;

        //if you can find a losing state (for other person) from this position
        //then your position is winning
        for(auto q : opts){
            if (i-q>=0){
                if (!states[i-q]){
                    ans = true;
                    break;
                }
            }
        }
        states[i] = ans;
    }

    if(states[k]){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }


}
