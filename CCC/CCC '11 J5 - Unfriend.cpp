#include <bits/stdc++.h>
using namespace std;

const int maxN = 6;

vector<int> graph[maxN+1];//graph[i] gives ppl i invited


int solve(int num){

    //no ppl that num invited
    if(graph[num].empty()){
        return 2;
    }
    else{
        int mult = 1;
        for(int a : graph[num]){
            mult *= solve(a);

        }
        return mult + 1;
    }


}

int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);


    //get inputs
    int n;
    cin>>n;

    //make tree
    for(int i = 1; i<n; i++){
        int temp;
        cin>>temp;
        //temp invited i
        graph[temp].push_back(i);


    }


    cout<<solve(n)-1<<endl;







}
