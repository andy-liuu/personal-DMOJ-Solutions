#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//CONSTRAINTS
const int MAXT = 100;
const int MAXSCORE = 2000;
const ll MOD = 1e9 + 7;

ll modnum(ll a){
    return a%MOD;
}

ll stress[MAXSCORE+1][MAXSCORE+1];
ll stressfree[MAXSCORE+1][MAXSCORE+1];
/*
[you][op] both arrays denote number of stress/stressfree ways to obtain a score of [you]-[op]
*/

ll solveStressFree(int you, int opp){
    //already found
    if(stressfree[you][opp] != -1){
        return stressfree[you][opp];
    }

    //breaks condition of stressfree so no ways to get to this score
    else if (you <= opp){
        stressfree[you][opp] = 0;
        return 0;
    }

    else{
        //add case where you scored the last point and opponent scored the last point
        //cout<<you<<" "<<opp;
        stressfree[you][opp] = modnum(modnum(solveStressFree(you - 1, opp)) + modnum(solveStressFree(you, opp-1)));
        return stressfree[you][opp];


    }
}

//solves up until your score and opponent score are equal (after that, only one way (you score the rest of the points)
ll solveStress(int you, int opp){
    //already found
    if(stress[you][opp] != -1){
        return stress[you][opp];
    }
    //your score is bigger than opponent's score
    else if (you > opp){
        stress[you][opp] = solveStress(you-1, opp);
        return stress[you][opp];
    }
    else{
        ll ans = 0;
        //you scored the last point
        if (you-1 <= opp){
            ans = modnum(ans + modnum(solveStress(you-1, opp)));
        }

        //opponent scored the last point
        if (you <= opp-1){
           ans = modnum(ans + modnum(solveStress(you, opp-1)));
        }

        stress[you][opp] = ans;
        return stress[you][opp];

    }
}



int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);


    //init + base cases
    for(int i = 0; i<=MAXSCORE; i++){
        for(int j = 0; j<= MAXSCORE; j++){

            //default to "need to compute later"
            stress[i][j] = -1;
            stressfree[i][j] = -1;


            //opponenent scores no points aka you score all of them (both stress and stressfree)
            if (j == 0){
                stress[i][j] = 1;
                stressfree[i][j] = 1;
            }

            //position where you score no points and opponent scores points (impossible stress free, 1 way stressful
            if (i == 0){
                stress[i][j] = 1;
                stressfree[i][j] = 0;
            }

            //both have no points, 1 way
            if ( i == 0 && j == 0){
                stress[i][j] = 1;
                stressfree[i][j] = 1;
            }

        }
    }


    int t;
    cin>>t;

    //t testcases here

    for(int test = 0; test < t; test++){

        int a, b;
        char dash;
        cin>>a>>dash>>b;



        cout<<"Case #"<<test+1<<": "<<modnum(solveStressFree(a,b))<<" "<<modnum(solveStress(b,b))<<endl;
    }



}
