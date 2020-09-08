#include <bits/stdc++.h>
using namespace std;

const int maxN = 30000;//pins
const int maxK = 500;//#bowling balls

int pins[maxN+1] = {};
int pinsums[maxN+1] = {};


int dp[maxN+1][maxK+1] = {};
//dp[a][b] = max sum considering the first a pins using b bolwing balls
//kinda like knapsack

int testcases;
int n, k, w;



int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);


    cin>>testcases;

    //xtestcases here
    for(int asdf = 0; asdf < testcases; asdf++){



        cin>>n>>k>>w;

        //reset arrays
        for(int i = 0; i<=maxN; i++){
            pins[i] = 0;
            pinsums[i] = 0;


            for(int j = 0; j<=maxK; j++){
                 dp[i][j] = 0;
            }
        }

        //get input
        for(int i = 1; i<=n; i++){
            cin>>pins[i];
        }

        //calculate summations of shots that end at that specific spot (going down by w units)

        for(int i = 1; i<=n; i++){
            if (i == 1){
                pinsums[i] = pins[i];
            }
            else if (i <= w){
                pinsums[i] = pinsums[i-1] + pins[i];
            }
            else{
                pinsums[i] = pinsums[i-1] + pins[i] - pins[i-w];
            }




        }

        /*
        for(int i = 0; i<=n; i++){
            cout<<pinsums[i]<<" ";
        }
        */


        //dp knapsack-ish time

        for(int p = 0; p<=n; p++){
            for(int ball = 0; ball<=k; ball++){

                if (p == 0 || ball == 0){
                    dp[p][ball] = 0;
                }
                else if (p<w){
                    dp[p][ball] = max(dp[p-1][ball], max(pinsums[p],dp[p][ball-1] ));//pin is unused -- used (only used) -- ball is unused
                }
                else{
                    dp[p][ball] = max(dp[p-1][ball], max(dp[p-w][ball-1]+pinsums[p], dp[p][ball-1]));
                }

            }
        }

        /*
        for(int i = 0; i<=k; i++){
            for(int j = 0; j<=n; j++){
                cout<<dp[j][i]<<" ";

            }
            cout<<endl;
        }
        */

        cout<<dp[n][k]<<endl;

    }







}
