#include <bits/stdc++.h>
using namespace std;

//CONSTRAINTS
const int MAXT = 4;//favorite team (always 4 teams)
const int MAXG = 5; //games already played

//GARBAGE HARDCODED DATA
//low/hi = whether the lower number team or the higher number team won the game
enum{LOW, HIGH, TIE};

//game # [i] is between teams <a,b>
map<int,pair<int,int>> titles;
map<pair<int,int>, int> rtitles;
void init(){
    titles[0] = make_pair(1,2);
    rtitles[make_pair(1,2)] = 0;

    titles[1] = make_pair(1,3);
    rtitles[make_pair(1,3)] = 1;

    titles[2] = make_pair(1,4);
    rtitles[make_pair(1,4)] = 2;

    titles[3] = make_pair(2,3);
    rtitles[make_pair(2,3)] = 3;

    titles[4] = make_pair(2,4);
    rtitles[make_pair(2,4)] = 4;

    titles[5] = make_pair(3,4);
    rtitles[make_pair(3,4)] = 5;

}

//DATA NEEDED FOR RECURSION
int scores[MAXT + 1] = {};
int games[6];

int checkscores[MAXT+1] = {};
int checkgames[6] = {};


//recurse/complete search through all possibilities

int ans = 0;

bool checkifsoln(int winner){

    //see if games in this permutation match the originally given games
    bool gamesmatch = true;
    for(int i = 0; i<6; i++){
        if (games[i] != -1){
            if (games[i] != checkgames[i]){
                gamesmatch = false;
                break;
            }
        }
    }

    //see if winner is actually the winner
    if (gamesmatch){
        bool scoresmatch = true;
        for(int otherteam = 1; otherteam <= 4; otherteam++){
            if (otherteam != winner){
                if (checkscores[otherteam] >= checkscores[winner]){
                    scoresmatch = false;
                    break;
                }
            }
        }
        return scoresmatch;
    }
    else{
        return false;
    }



}

void recur(int game, int fav){
    //finished with permutation
    if (game == 6){
        if (checkifsoln(fav)){
            ans++;
        }
        return;
    }
    else{
        pair<int,int> poten = titles[game];

        //lo team wins
        checkgames[game] = LOW;
        checkscores[poten.first] += 3;
        recur(game+1, fav);
        checkgames[game] = -1;
        checkscores[poten.first] -= 3;

        //tie
        checkgames[game] = TIE;
        checkscores[poten.first]++;
        checkscores[poten.second]++;
        recur(game+1, fav);
        checkgames[game] = -1;
        checkscores[poten.first]--;
        checkscores[poten.second]--;

        //hi team wins
        checkgames[game] = HIGH;
        checkscores[poten.second] += 3;
        recur(game+1, fav);
        checkgames[game] = -1;
        checkscores[poten.second] -= 3;
    }

}


int main(void){
    /*
    ios::sync_with_stdio(0);
    cin.tie(0);
    */
    init();
    memset(games, -1, sizeof(games));
    memset(checkgames, -1, sizeof(checkgames));

    int t,g;
    cin>>t>>g;

    for(int i = 0; i<g; i++){
        int a,b,sa,sb;
        cin>>a>>b>>sa>>sb;

        int gamenum = rtitles[make_pair(a,b)];
        if (sa == sb){
            games[gamenum] = TIE;
            scores[a]++;
            scores[b]++;
        }
        else if (sa > sb){
            games[gamenum] = LOW;
            scores[a] += 3;
        }
        else{
            games[gamenum] = HIGH;
            scores[b] += 3;
        }
    }

    recur(0, t);
    cout<<ans<<endl;




}
