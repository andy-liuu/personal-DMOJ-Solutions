#include <bits/stdc++.h>
using namespace std;
const int MAXNUM = 30;

bool states[MAXNUM+1][MAXNUM+1][MAXNUM+1][MAXNUM+1] = {};
bool found[MAXNUM+1][MAXNUM+1][MAXNUM+1][MAXNUM+1] = {};


int moves[5][4] = {

{2,1,0,2},
{1,1,1,1},
{0,0,2,1},
{0,3,0,0},
{1,0,0,1},

};

bool iswin(int a, int b, int c, int d){
    //already found
    if (found[a][b][c][d]){
        return states[a][b][c][d];
    }
    else{
        bool ans = false;

        for(int i = 0; i<5; i++){
            int newa = a - moves[i][0];
            int newb = b - moves[i][1];
            int newc = c - moves[i][2];
            int newd = d - moves[i][3];

            if (newa>=0 && newb >= 0 && newc >= 0 && newd >= 0){
                if (!iswin(newa,newb,newc,newd)){
                    ans = true;
                    break;
                }

            }


        }
        found[a][b][c][d] = true;
        states[a][b][c][d] = ans;
        return ans;

    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    memset(states, false, sizeof(states));
    memset(found, false, sizeof(found));
    */


    int n;
    cin>>n;

    //n testcases here
    while(n--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        if(!iswin(a,b,c,d)){
            cout<<"Roland"<<endl;
        }
        else{
            cout<<"Patrick"<<endl;
        }

    }






}
