#include <bits/stdc++.h>
using namespace std;

int main(){


    for ( int x = 0;x<10;x++){
        string word;
        cin>>word;
        int len = word.size();

        int dp[len+2];
        for(int q = 0;q<len+2;q++){
            dp[q] = 0;
        }


        int ans = 0;

        for (int i = 1;i<len+1;i++){


            for (int j = 0;j<i;j++){

                int newlen = i-j;
                string test = word.substr(j,newlen);


                if (newlen%2 == 0){
                    string first = test.substr(newlen/2);
                    string sec = test.substr(0,newlen/2);

                    //cout<<sec << " " << first <<" "<< j << " " << i << endl;

                    if (first == sec){
                        dp[i] = max(dp[i],dp[j] + newlen);

                        if (dp[i] > ans){
                            ans = dp[i];
                        }

                    }



                }




            }
        }

        cout<<ans<<endl;



    }


}
