#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    for(int q = 0;q<t;q++){

        vector<int> top;
        vector<int> side;
        vector<int> bot;

        //get inputs
        int n;
        cin>>n;

        int input;
        for(int i = 0;i<n;i++){
            cin>>input;
            top.push_back(input);
        }

        int spot = 0;
        bool movement = false;
        while (bot.size()<n){
            //greedy algorithm here
            movement = false;
            //side to bot
            if(side.size()>0){
                if (side.back() == spot + 1 && !movement){

                    int curr = side.back();
                    side.pop_back();
                    bot.push_back(curr);

                    spot++;
                    movement = true;

                    //cout<<"side to bot"<<endl;
                }
            }

            if (top.size()>0){
                //top to bot
                if(top.back() == spot + 1 && !movement){
                    int curr = top.back();
                    top.pop_back();
                    bot.push_back(curr);
                    spot++;
                    movement = true;

                    //cout<<"top to bot"<<endl;
                }
                //top to side
                else if (!movement){
                    int curr = top.back();
                    top.pop_back();
                    side.push_back(curr);
                    movement = true;

                    //cout<<"top to side"<<endl;
                }
            }

            if (!movement){
                break;
            }
        }

        if(bot.back() == n){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }


    }




}
