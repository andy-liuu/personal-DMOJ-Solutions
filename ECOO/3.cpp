#include <bits/stdc++.h>
using namespace std;

int main(){

    const double pi = acos(-1);

    for (int q = 0;q<5;q++){
        int px,py;
        cin>>px>>py;

        double dist = sqrt(pow(px,2)+pow(py,2));
        double ang = atan2(py,px);

        double ax = dist*cos(ang-pi/3);
        double ay = dist*sin(ang-pi/3);

        double bx = dist*cos(ang+2*pi/3);
        double by = dist*sin(ang+2*pi/3);

        double cx = sqrt(3)*dist*cos(ang+pi/6);
        double cy = sqrt(3)*dist*sin(ang+pi/6);


        string ans = "(%.2f,%.2f) (%.2f,%.2f) (%.2f,%.2f)\n";
        printf("(%.1f,%.1f) (%.1f,%.1f) (%.1f,%.1f)\n",bx,by,ax,ay,cx,cy);
    }

}
