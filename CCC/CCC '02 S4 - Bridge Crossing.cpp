#include <bits/stdc++.h>
using namespace std;

const int MAXM = 20;
const int MAXQ = 100;

int curnum = 0;

//store names and data
string names[MAXQ+1];
int weights[MAXQ+1];

//linear dynamic programming

int dp[MAXQ+1];//-1 denotes not found
int len[MAXQ+1];//len[i] denotes length of last optimal group ending at [i]
//for backtracking

int m;
int q;


int solve(int val){
    if (dp[val] != -1){
        return dp[val];
    }
    else if (val == 0){
        return 0;
    }
    else{
        int biggest = -1;
        int ans = INT_MAX;
        int l = -1;

        for(int i = 0; i<m; i++){
            //in RANGE
            if(val - i > 0){
                biggest = max(biggest, weights[val-i]);
                if(ans > solve(val-i-1) + biggest){
                    ans = solve(val-i-1) + biggest;
                    l = i+1;
                }
            }
        }

        len[val] = l;
        dp[val] = ans;
        return ans;
    }
}




int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>m>>q;

    memset(dp, -1, sizeof(dp));
    memset(len, -1, sizeof(len));

    for(int i = 1; i<=q; i++){
        cin>>names[i]>>weights[i];
    }

    cout<<"Total Time: "<<solve(q)<<endl;



    vector<string> lines;

    while(q){

        int lengroup = len[q];
        string line = "";

        for(int i = q-lengroup+1; i<=q; i++){
            line += names[i];
            if (i != q){
                line += " ";
            }
        }

        q = q - lengroup;
        lines.push_back(line);


    }

    reverse(lines.begin(), lines.end());
    for(auto a : lines){
        cout<<a<<endl;
    }








}
