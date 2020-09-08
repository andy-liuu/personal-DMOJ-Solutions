#include <bits/stdc++.h>
using namespace std;



bool incircle(double cx,double cy,double kx,double ky){

    double dist = sqrt(pow(cx-kx,2) + pow(cy-ky,2));

    return dist <= 50.0;


}

double dist(double kx,double ky,pair<pair<double, char>,pair<double,double>> poten){

    double dist = sqrt(pow(kx-poten.second.first,2) + pow(ky-poten.second.second,2));
    return dist;

}




int main(){
for(int arcy=0;arcy<10;arcy++){

    int cx,cy;
    cin>>cx>>cy;

    vector<pair<pair<double, char>,pair<double,double>>>houses;



    for (int i = 0; i<100;i++){
        double tx,ty;
        char pol;
        cin>>tx>>ty>>pol;

        houses.push_back(make_pair(make_pair(0.0, pol),make_pair(tx,ty)));
    }
    int numD = 0, tot = 0;
    for (double kx =  cx-50; kx <= cx+50; kx++){
        for (double ky =  cy-50; ky <= cy+50; ky++){
            int smolD=0;
            int smolR=0;
            if (incircle(cx,cy,kx,ky)){
                tot++;
                for (int i = 0;i<houses.size(); i++){
                    houses.at(i).first.first = dist(kx,ky,houses.at(i));

                    if (dist(kx,ky,houses.at(i)) == 0){
                        tot--;
                        continue;
                    }


                }



                sort(houses.begin(), houses.end());

                //a
                vector<pair<pair<double, char>,pair<double,double> > > close;


                close.push_back(houses.at(0));
                close.push_back(houses.at(1));
                close.push_back(houses.at(2));

                for (int tie = 3;tie<houses.size();tie++){

                    if (houses.at(tie).first.first == houses.at(2).first.first){
                        close.push_back(houses.at(tie));
                    }
                    else{
                        break;
                    }

                }
                for(int res=0;res<close.size();res++){
                  if(close.at(res).first.second=='D'){
                    smolD++;
                  }
                  else{
                    smolR++;
                  }
                }
                if (smolD>=smolR){
                  numD++;
                }





            }




        }
    }
    double percenty=(double)numD/tot*100;
    printf("%.1f\n",percenty);


}
}
/*
sort(v.begin,v.end,greater)

*/
