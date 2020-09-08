#include <bits/stdc++.h>
using namespace std;


int main(){

    //loop 10 here

    for(int q = 0; q<10; q++){



    int n, m, d;

    cin>>n>>m>>d;

    int events[d+1] = {};

    for(int i = 0; i<m; i++){
        int temp;
        cin>>temp;
        events[temp]++;
    }

    int tot = 0;
    int totshirts = n;
    for(int day = 1; day<=d; day++){

        if  (n == 0){
            tot++;
            n = totshirts;
        }

        n--;
        n += events[day];
        totshirts += events[day];





    }

    cout<<tot<<endl;
    }



}
