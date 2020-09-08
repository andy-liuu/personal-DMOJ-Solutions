#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6;
const int MAXT = 1e6;

//implement difference array for range updates
//one-indexed cups
ll diff[MAXN+2] = {};
ll finalvals[MAXN+2] = {};



int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin>>n>>t;

    //update the ranges for diff array
    for(int i = 0; i<t; i++){
        int l, r, amount;
        cin>>l>>r>>amount;

        diff[l] += amount;
        diff[r+1] -= amount;
    }

    //prefix sums of diff array = actual final values
    finalvals[0] = diff[0];
    for(int i = 1; i<=n; i++){
        finalvals[i] = finalvals[i-1] + diff[i];
    }

    int l;
    cin>>l;



    //2 pointers method/
    int left = 1;
    int right = 0;

    int ans = -1;
    ll sofar = 0;

    while(right<n){
        //next move right is still in range
        if(sofar + finalvals[right+1] <= l){
            right++;
            sofar += finalvals[right];
            ans = max(ans, right-left+1);


        }
        else{

            sofar -= finalvals[left];
            left++;



        }

        //cout<<"left: "<<left<<" right: "<<right<<" sofar: "<<sofar<<endl;


    }

    cout<<ans<<endl;





}
