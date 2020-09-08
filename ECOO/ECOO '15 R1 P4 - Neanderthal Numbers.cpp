#include <bits/stdc++.h>
using namespace std;

/*
ook
ookook
oog
ooga
ug
mook
mookmook
oogam
oogum
ugug
*/

//up to 50 words (longest is 8 chars) so length of string is max 400 characters

const int maxS = 400;
int dp[maxS + 1] = {};

set<string> nums = {"ook","ookook","oog","ooga","ug","mook","mookmook","oogam","oogum","ugug"};
int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);

    //x10
    for(int c = 0; c<10; c++){


        //reset dp
        for(int q = 0; q<maxS; q++){
            dp[q]=0;
        }
        dp[0] = 1;

        string word;
        cin>>word;

        int wordlength = word.length();

        for(int start = 0; start<=wordlength; start++){
            for(int l = 0; l<wordlength-start+1; l++){

                string test = word.substr(start,l);

                if (nums.count(test) != 0){
                    dp[start+l] += dp[start];
                }

            }
        }

        cout<<dp[wordlength]<<endl;
    }
}
