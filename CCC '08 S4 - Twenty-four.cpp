#include <bits/stdc++.h>
using namespace std;

int orihand[4];


bool alreadyChosen[4] = {};

int doHand[4] = {};
bool recurChoose[4] = {};



int bestAns = -1;

//retursion for calculating a hand order
void handOps(int sofar){

    //cout<<value<<endl;

    //already found best answer
    if(bestAns == 24){
        return;
    }

    if(sofar == 4){
        int val;
        for(int i = 0; i<4; i++){
            if (!recurChoose[i]){
                val = doHand[i];

            }
        }


        //cout<<val<<endl;
        if(val <= 24){
            bestAns = max(val, bestAns);
        }



    }
    else{

        //choose a value i , then do an operation on another value
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4; j++){
                if(i != j && !recurChoose[i] && !recurChoose[j]){

                    recurChoose[i] = true;
                    int prev = doHand[j];

                    //+
                    doHand[j] += doHand[i];
                    handOps(sofar+1);
                    doHand[j] = prev;

                    //-
                    doHand[j] -= doHand[i];
                    handOps(sofar+1);
                    doHand[j] = prev;

                    //*

                    doHand[j] *= doHand[i];
                    handOps(sofar+1);
                    doHand[j] = prev;


                    if(doHand[i] != 0){
                        if(doHand[j] % doHand[i] == 0){
                            doHand[j] /= doHand[i];
                            handOps(sofar+1);
                            doHand[j] = prev;
                        }
                    }



                    recurChoose[i] = false;


                }
            }
        }

    }








}

//recurson for getting a hand order
void recurHand(int sofar){
    if(sofar == 4){
        handOps(1);
        return;
    }
    else{
        for(int i = 0; i<4; i++){
            if(!alreadyChosen[i]){

                doHand[sofar] = orihand[i];
                alreadyChosen[i] = true;
                recurHand(sofar+1);
                alreadyChosen[i] = false;
                doHand[sofar] = 0;


            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;


    //n testcases

    for(int i = 0; i<n; i++){

        bestAns = -1;

        //input hand
        for(int i = 0; i<4; i++){
            cin>>orihand[i];
        }

        recurHand(0);

        cout<<bestAns<<endl;

    }





}
