
#include <bits/stdc++.h>

using namespace std;

long long fnum[99999] = {0};
long long x[99999] = {0};
long long y[99999] = {0};


long long fibo(long long n){
    if (n == 1){
        return 1;
    }
    else if (n == 2){
        return 1;
    }
    else if (fnum[n] != 0){
        return fnum[n];
    }
    else{
        fnum[n] = fibo(n-1) + fibo(n-2);
        return fnum[n];
    }


}


long long getX(long long n){


    if (n == 1){
        return 1;
    }
    else if (n == 2){
        return 0;
    }

    else if (x[n] != 0){
        return x[n];
    }
    else{
        int mod = n%4;

        long long ans;

        if (mod == 0){ans =  getX(n-1) + fibo(n);};
        if (mod == 1){ans =  getX(n-1);};
        if (mod == 2){ans =  getX(n-1) - fibo(n-1);};
        if (mod == 3){ans =  getX(n-2);};

        x[n] = ans;
        return ans;


    }

}

long long getY(int n){


    if (n == 1){
        return 0;
    }
    else if (n == 2){
        return 0;
    }

    else if (y[n] != 0){
        return y[n];
    }
    else{
        int mod = n%4;

        long long ants;

        if (mod == 0){ants =  getY(n-1);};
        if (mod == 1){ants =  getY(n-1) - fibo(n-1);};
        if (mod == 2){ants =  getY(n-2);};
        if (mod == 3){ants =  getY(n-1) + fibo(n);};

        y[n] = ants;
        return ants;


    }

}

int main(){

    x[1] = 1;
    fnum[1] = 1;
    fnum[2] = 1;

    for(long long ars = 0; ars < 10; ars++){


    long long ix,iy;
    cin>>ix>>iy;

    long long c = 1;
    while (true){

        //cout<<fibo(c)<<endl;

        long long tx = getX(c),ty = getY(c);

        long long bx = tx - fibo(c);
        long long by = ty - fibo(c);

        //cout<<tx<<" "<<ty<<" "<<bx<<" "<<by<<" "<<endl;

        if (ix >= bx && ix <= tx && iy >= by && iy <= ty ){
            cout<<c<<endl;
            break;
        }
        else{
            c++;
        }

    }

    }









}







