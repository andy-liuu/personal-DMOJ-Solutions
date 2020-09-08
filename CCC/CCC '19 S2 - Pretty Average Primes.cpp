#include <bits/stdc++.h>
using namespace std;


bool checkPrime(double num){

    bool ans = true;
    int stop = sqrt(num)/1;

    for(int i = 2;i<= stop;i++){
        if ((int)num%i == 0){
            ans = false;
            break;
        }
    }

    return ans;

}


int main(){

    int t;
    cin>>t;

    for(int q = 0;q<t;q++){
        int num;
        cin>>num;

        int a,b;

        //bash the numbers
        for(int i = 2;i<2*num;i++){
            a = i;
            b = 2*num - i;

            if (checkPrime((double)a) && checkPrime((double)b)){
                cout<<a<<" "<<b<<endl;
                break;
            }
        }


    }








}
