#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MAXM = 300;
const int MAXU = 100;
const int MAXR = 150;

int dp[MAXR+1][MAXU+1][MAXM+1] = {0};
/*dp[r][u][m] denotes best value considering
first r restaurants, given stomach capacity of u
and minutes spent being m


*/

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,u,r;// minutes available, stomach capacity, num restaurants
    cin>>m>>u>>r;

    int vi,ti,fi;//value, time spent, food spent

    //loop through restaurants
    for(int rest = 1; rest <= r; rest++){
        cin>>vi>>ti>>fi;

        //loop through food capacity and time available
        for(int food = 1; food <= u; food++){
            for(int time = 1; time <= m; time++){

                //can you take this
                if (food - fi >= 0 && time - ti >= 0){
                    dp[rest][food][time] = max(dp[rest-1][food][time], dp[rest-1][food-fi][time - ti] + vi);
                }
                else{
                    dp[rest][food][time] = dp[rest-1][food][time];
                }

            }
        }


    }

    cout<<dp[r][u][m]<<endl;




}
