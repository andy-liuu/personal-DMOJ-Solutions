#include <bits/stdc++.h>
using namespace std;

int main(){
    int type;
    cin>>type;

    int n;cin>>n;

    vector<int> dmoj;
    vector<int> peg;

    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        dmoj.push_back(temp);
    }
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        peg.push_back(temp);
    }

    sort(dmoj.begin(),dmoj.end());
    sort(peg.begin(),peg.end());

    int sum = 0;
    if (type == 1){
        for(int i = 0;i<n;i++){
            sum += max(dmoj.at(i),peg.at(i));
        }
    }
    else{
        for(int i = 0;i<n;i++){
            sum += max(dmoj.at(i),peg.at(n-i-1));
        }
    }

    cout<<sum<<endl;




}
