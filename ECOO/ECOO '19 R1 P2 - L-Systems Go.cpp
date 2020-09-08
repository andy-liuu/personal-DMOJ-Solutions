#include <bits/stdc++.h>

using namespace std;




int main(){


    for(int qwe = 0; qwe < 10; qwe++){


    map<char,string> rules;
    long long freq[100] = {};
    long long between[100] = {};

    long long r,t;
    string a;





    for(int q = 0; q<100; q++){
        freq[q] = 0;
    }


    cin>>r>>t>>a;

    //set frequencies
    for(int i = 0; i<a.size(); i++){
        freq[(int)a.at(i)]++;
    }



    for (int i = 0; i<r; i++){
        char f;
        string w;
        cin>>f>>w;
        rules[(int)f] = w;
    }



    //iterations

    char fir = a.at(0),las = a.at(a.size()-1);



    for(int q = 0; q<t; q++){
        //letter
        for(int w = 0; w<100; w++){

            if(freq[w] != 0){
                string temp = rules[w];
                long long num = freq[w];

                for(int e = 0; e< temp.size(); e++){
                    between[(int)temp.at(e)] += num;

                }


            }

        }

        fir = rules[(int)fir].at(0);
        las = rules[(int)las].at(rules[(int)las].size()-1);

        for(int a = 0; a<100; a++){
            freq[a] = between[a];
            between[a] = 0;
        }



    }

    long long ans = 0;
    for(int a = 0; a<100; a++){
        ans += freq[a];
    }

    cout<<fir<<las<<" "<<ans<<endl;

    }




}
