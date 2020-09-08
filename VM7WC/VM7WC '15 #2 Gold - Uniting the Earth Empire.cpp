
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5;

stack<pair<ll,ll>> line;//number, # of occurences in a row

int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;


    //armortized linear time hopefully
    ll ans = 0;

    for(ll i = 0; i<n; i++){

        //cur represents the right end of a bridge, each value in the stack are possible left ends of the bridge
        ll cur;
        cin>>cur;

        //empty stack aka the first element
        if (line.empty()){
            line.push(make_pair(cur, 1));
        }
        else{
            //same number, you can match to each of the previous same number ones, match to one of the previous ones if exist
            if(cur == line.top().first){
                ans += line.top().second;
                line.top().second++;
                //there is another bigger value before that you can alco connect to one
                if(line.size() > 1){
                    ans++;
                }

            }
            //smaller, you can only match to the first of the previous numbers
            else if (cur < line.top().first){
                ans += 1;
                line.push(make_pair(cur, 1));
            }
            /*
            bigger, remove values that can no longer be part of a solution,
            then adjust frequency of a pair/push in if needed

            the bigger number can match to each of the smaller numbers x freq as well
            */
            else{
                while(line.top().first < cur){
                    ans += line.top().second;
                    line.pop();
                    if(line.empty())break;
                }

                if(line.empty()){
                    line.push(make_pair(cur,1));
                }
                else{
                    if (line.top().first == cur){
                        ans += line.top().second;
                        line.top().second++;
                        if(line.size() > 1){
                            ans++;
                        }
                    }
                    else{
                        ans += 1;
                        line.push(make_pair(cur, 1));
                    }
                }

            }
        }

    }

    cout<<ans<<endl;



}
