#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> colID = {{"BLUE", 100}, {"PINK", 200}, {"GREEN",300}};
struct Slip{
    string col;
    int num;
};
struct compareSlips{

    bool operator()(const Slip& s, const Slip& q){
        if(s.col != q.col){
            return colID[s.col]>colID[q.col];
        }
        else{
            return s.num>q.num;
        }
    }
};

priority_queue<Slip, vector<Slip>, compareSlips> line;


int main(void){

    cin.sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;

    while(q--){
        string temp;
        cin>>temp;
        if(temp == "ADD"){
            string color;
            int num;
            cin>>color>>num;
            Slip ticket = {color, num};
            line.push(ticket);
        }
        else{
            if(!line.empty()){
                Slip ticket = line.top();
                line.pop();
                cout<<ticket.col<<" "<<ticket.num<<endl;
            }
            else{
                cout<<"NONE"<<endl;
            }
        }
    }
}
