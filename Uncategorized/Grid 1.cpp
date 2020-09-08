#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int h,w;
    cin>>h>>w;

    long long paths[h+1][w+1] = {};
    paths[1][1] = paths[1][0]  =  1;
    string line;

    for(int q = 1;q<=h;q++){
        cin>>line;
        for (int e = 1; e<=w;e++){
            if(line.at(e-1) == '.'){
                paths[q][e] = (paths[q][e-1] + paths[q-1][e])%1000000007;
            }
        }
    }

    cout<<paths[h][w]%1000000007<<endl;
}
