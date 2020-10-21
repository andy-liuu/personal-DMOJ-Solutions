#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int,int> tiiii;

//CONSTRAINTS
const int MAXN = 2e3;
const int MAXV = 1e5;
const int MAXC = 1e4;

ll dp[MAXC+1];

int coins[MAXN+1];

vector<tiiii> data;
/*
tuple indicates
amount to spend, num accepted coins, index it appears in input, answer (initially zero)
*/

bool sortbycoins(tiiii a, tiiii b){
    return (get<1>(a) < get<1>(b));
}

bool sortbyout(tiiii a, tiiii b){
    return (get<2>(a) < get<2>(b));
}





int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i<= MAXC; i++){
        dp[i] = -1;
    }
    dp[0] = 0;

    int n,v;
    cin>>n>>v;


    //input coins
    for(int i = 1; i <= n;  i++){
        cin>>coins[i];
    }

    //input queries
    for(int i = 0; i<v; i++){
        int sum, allowed;
        cin>>sum>>allowed;
        data.push_back(make_tuple(sum, allowed, i, 0));
    }

    sort(data.begin(), data.end(), sortbycoins);

    int currquery = 0;

    //knapsack-like code
    for(int c = 1; c <= n; c++){

        //knapsack through current coin
        for(int val = 0; val <= MAXC; val++){
            //possible to take this coin, otherwise do not change the value
            if(val - coins[c] >= 0){
                ll prev = dp[val - coins[c]];
                ll cur = dp[val];

                if (prev != -1 && cur != -1){
                    dp[val] = min(cur, prev+1);
                }
                else if (prev == -1 && cur != -1){
                    dp[val] = cur;
                }
                else if (prev != -1 && cur == -1){
                    dp[val] = prev+1;
                }
                else{
                    dp[val] = -1;
                }
            }

        }





        //run through queries
        while (currquery < data.size()){

            if (get<1>(data[currquery]) != c){
                break;
            }

            get<3>(data[currquery]) = dp[get<0>(data[currquery])];
            currquery++;


        }


    }

    sort(data.begin(), data.end(), sortbyout);
    for(auto i : data){
        ll ans = get<3>(i);
        cout<<ans<<endl;
    }


    //testing output of custom comparitors
    /*
    sort(data.begin(),data.end(), sortbycoins);

    for(auto i : data){
        cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<" "<<get<3>(i)<<endl;
    }

    sort(data.begin(),data.end(), sortbyout);
    cout<<endl;

    for(auto i : data){
        cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<" "<<get<3>(i)<<endl;
    }

    */


}
