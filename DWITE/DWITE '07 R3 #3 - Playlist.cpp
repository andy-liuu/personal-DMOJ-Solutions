#include <bits/stdc++.h>
using namespace std;

int n,space;
int main(){

    for(int a = 0;a<5;a++){
        cin>>space;
        cin>>n;

        string nameholder;
        int ratings[n+1];
        int sizes[n+1];

        for(int i = 1;i<=n;i++){
            cin>>nameholder>>ratings[i]>>sizes[i];
        }

        int dp[space+1][n+1];

        //loop thru items
        //loop thru sizes
        for(int q = 0;q<=n;q++){
            for (int w = 0;w<=space;w++){

                if (q == 0){
                    dp[w][q] = 0;
                }
                else if (w-sizes[q]>=0){
                    dp[w][q] = max(dp[w-sizes[q]][q-1]+ratings[q],dp[w][q-1]);
                }
                else{
                    dp[w][q] = dp[w][q-1];
                }



            }
        }
        cout<<dp[space][n]<<endl;
    }


}
