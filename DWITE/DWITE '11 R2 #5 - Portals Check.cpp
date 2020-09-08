#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

//union-find
int link[2*MAXN+1];
int size[2*MAXN+1];

int find(int n){
    while(n != link[n]) n = link[n];
    return n;
}

bool same(int a, int b){
    return find(a)==find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a]<size[b]) swap(a,b);
    size[a] += size[b];
    link[b] = a;
}

//need to turn strings into ints
unordered_map<string,int> label;
int stringtonum(string s){
    //not already in map
    if(label.find(s) == label.end()){
        //new word gets the next integer, words get put in/labeled in order
        int temp = label.size();//zero indexed
        label[s] = temp;

    }
    return label[s];
}





int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);

    //x5 testcases here
    for(int qwe = 0; qwe < 5; qwe++){
        label.clear();

        //reset link and size
        for(int i = 0; i<2*MAXN+1; i++){
            link[i] = i;
            size[i] = 1;
        }

        int n;
        cin>>n;

        while(n--){

            char type;
            string a, b;
            cin>>type>>a>>b;



            int anum = stringtonum(a);
            int bnum = stringtonum(b);

            if(type == 'p'){
                if(!same(anum, bnum)) unite(anum, bnum);
            }
            else{
                if(same(anum, bnum)){
                    cout<<"connected"<<endl;
                }
                else{
                    cout<<"not connected"<<endl;
                }
            }

        }

    }





}
