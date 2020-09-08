#include <bits/stdc++.h>

using namespace std;

long double pointline(long double d,long double x,long double y){

    return abs(tan(d)*x - y)/sqrt(pow(tan(d),2) + 1);

}

long double dist(long double x,long double y,long double ex,long double ey){

    return sqrt(pow(ex-x,2) + pow(ey-y,2));

}

long double toRad(long double n){
    return n/180.0 * acos(-1);
}

int main(){

    for(int matt = 0; matt<5; matt++){



    long double d,l,n;
    cin>>d>>l>>n;
    d = toRad(d);



    long double endx = l * cos(d);
    long double endy = l * sin(d);
    //cout<<"ENDX: "<<endx<<"   ENDY:   "<<endy<<endl;



    if (endx != 0 && endy != 0){

        long double path[3] = {tan(d), -1.0, 0.0};
        long double top[3] = {1.0, tan(d), -1*endx - tan(d)*endy};
        long double bot[3] = {1.0,tan(d), 0.0};

        int c = 0;
        for(int i = 0; i<n; i++){
            long double airx,airy,rad;

            cin>>airx>>airy>>rad;


            long double topx,botx;
            topx = (-1*top[2])-(top[1]*airy);
            botx = (-1*bot[2])- (bot[1]*airy);
            //cout<<topx<<" <- TOP BOT ->  "<<botx<<endl;



            if (topx >= botx && topx >= airx && botx <= airx){

                //cout<<"top bigger than bot"<<endl;
                if (pointline(d,airx,airy) <= rad){
                    //cout<<"yes"<<endl;
                    c++;
                }

            }
            else if (botx >= topx && botx >= airx && topx <= airx){
                //cout<<"bot bigger than top"<<endl;
                if (pointline(d,airx,airy) <= rad){
                    //cout<<"yes"<<endl;
                    c++;
                }

            }

            else{

                //cout<<"to (0,0) ->  "<<dist(airx,airy,0,0)<<endl;
                //cout<<"to (endx,endy) ->  "<<dist(airx,airy,endx,endy)<<endl;


                if (dist(airx,airy,0,0) <= rad || dist(airx,airy,endx,endy) <= rad){
                    //cout<<"yes"<<endl;
                    c++;
                }


            }



        }

        cout<<"The jet will appear on "<<c+1<<" radar screens."<<endl;


    }


    else if (endx == 0){

        int c = 0;
        for(int i = 0; i<n; i++){
            long double airx,airy,rad;
            cin>>airx>>airy>>rad;

            if (airy >= 0 && airy <= endy && abs(airx) <= rad){
                c++;
            }

            else{

                if (dist(airx,airy,0,0) <= rad || dist(airx,airy,endx,endy) <= rad){
                    c++;
                }


            }


        }

        cout<<"The jet will appear on "<<c+1<<" radar screens."<<endl;

    }
    //endy == 0
    else{

        int c = 0;
        for(int i = 0; i<n; i++){
            long double airx,airy,rad;
            cin>>airx>>airy>>rad;

            if (airx >= 0 && airx <= endx && abs(airy) <= rad){
                c++;
            }

            else{

                if (dist(airx,airy,0,0) <= rad || dist(airx,airy,endx,endy) <= rad){
                    c++;
                }


            }


        }

        cout<<"The jet will appear on "<<c+1<<" radar screens."<<endl;

    }




    }



}
