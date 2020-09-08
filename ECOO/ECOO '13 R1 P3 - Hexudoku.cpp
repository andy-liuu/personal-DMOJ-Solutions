#include <bits/stdc++.h>
using namespace std;

int main(){

    for(int x = 0;x<10;x++){

        bool rows[16][16] = {{}},coll[16][16] = {{}},grid[16][16] = {{}},box[4][4][16] = {{{}}};


    string temp;

    for(int i = 0;i<16;i++){
        cin>>temp;
        for(int j = 0;j<16;j++){
            int let = (int)temp.at(j);

            if (let >= (int)'A' && let <= (int)'F'){
                let-=55;
                rows[i][let] = coll[j][let] = box[i/4][j/4][let] = grid[i][j] = true;
            }
            else if (let == (int)'-'){
                grid[i][j] = false;
            }
            else{
                let -= 48;
                rows[i][let] = coll[j][let] = box[i/4][j/4][let] = grid[i][j] = true;
            }
        }
    }

    //check
    int c = 0;
    for(int i = 0;i<16;i++){
        for(int j = 0;j<16;j++){
            if (!grid[i][j]){
                for(int let = 0;let<16;let++){
                    if (!rows[i][let] && !coll[j][let] && !box[i/4][j/4][let]){
                        rows[i][let] = coll[j][let] = box[i/4][j/4][let] = true;
                        c++;
                        break;
                    }
                }
            }
        }
    }
    cout<<c<<endl;

    }



}
