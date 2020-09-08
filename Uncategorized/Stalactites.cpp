#include <bits/stdc++.h>
using namespace std;

#define LSB(i) ((i)&-(i))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> cube;


//3d fenwick tree
class BIT{
public:
    cube tree;
    cube vals;
    int len;
    BIT(int n){
        tree.resize(n+1, vvll(n+1, vll(n+1, 0)));
        vals.resize(n+1, vvll(n+1, vll(n+1, 0)));
        len = n;
    }

    //forward declarations



    void update(int x, int y, int z, ll val){
        ll atspot = vals[x][y][z];
        vals[x][y][z] = val;
        ll diff = val - atspot;

        for(int tx = x; tx<=len; tx+=LSB(tx)){
            for(int ty = y; ty <= len; ty+= LSB(ty)){
                for(int tz = z; tz<=len; tz+=LSB(tz)){
                    tree[tx][ty][tz] += diff;
                }
            }
        }

    }

    ll prefsum(int x,int y, int z){
        ll sum = 0;

        int tx = x;
        while(tx > 0){
            int ty = y;
            while(ty > 0){
                int tz = z;
                while(tz > 0){
                    sum += tree[tx][ty][tz];
                    tz -= LSB(tz);
                }
                ty -= LSB(ty);
            }
            tx -= LSB(tx);
        }

        return sum;
    }

    ll query(int xlo, int ylo, int zlo, int xhi, int yhi, int zhi){
        return
        prefsum(xhi, yhi, zhi) - (prefsum(xlo-1, yhi, zhi) + prefsum(xhi, ylo-1, zhi) + prefsum(xhi, yhi, zlo-1)
                                 - prefsum(xlo-1, ylo-1, zhi) - prefsum(xlo-1, yhi, zlo-1) - prefsum(xhi, ylo-1, zlo-1)
                                 + prefsum(xlo-1, ylo-1, zlo-1));
    }

};

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    BIT cave(n);

    int q;
    cin>>q;

    ll ans = 0;
    while(q--){
        char let;
        cin>>let;

        if (let == 'C'){
            int x, y,z,l;
            cin>>x>>y>>z>>l;
            cave.update(x,y,z,l);
        }
        else if (let == 'S'){
            int xl,yl,zl,xh,yh,zh;
            cin>>xl>>yl>>zl>>xh>>yh>>zh;
            ans += cave.query(xl,yl,zl,xh,yh,zh);
        }
    }

    cout<<ans<<endl;


}
