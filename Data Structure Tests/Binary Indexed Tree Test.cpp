#include <bits/stdc++.h>
#define LSB(i) ((i) & -(i))
typedef long long ll;
using namespace std;
const int MAXN = 1e5;
int arr1[MAXN+1] = {};
int arr2[MAXN+1] = {};


class BIT{
    public:
    ll *vals;
    ll *tree;
    int length;

    BIT(int arr[], int len){
        length = len;

        vals = new ll[len+1];
        tree = new ll[len+1];

        //copy values
        for(int q = 0; q<=len; q++){
            vals[q] = arr[q];
            tree[q] = arr[q];
        }

        //construct tree
        for(int w = 1; w<=len; w++){
            int next = w + LSB(w);
            if (next <= len){
                tree[next] += tree[w];
            }
        }


    }

    ~BIT(){
        delete [] vals;
        delete [] tree;
    }

    ll prefixSum(ll i){
        ll sum = 0;
        while(i > 0){
            sum += tree[i];
            i -= LSB(i);
        }
        return sum;
    }

    ll rangeQ(ll i, ll j){
        return prefixSum(j) - prefixSum(i-1);
    }

    void add(ll spot, ll val){

        vals[spot]+=val;
        while(spot<=length){
            tree[spot] += val;
            spot += LSB(spot);
        }
    }



};

int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);
    //get inputs and original array
    int n, m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        int temp;
        cin>>temp;
        arr1[i] = temp;
        arr2[temp]++;
    }

    BIT sums(arr1, n);

    BIT numvals(arr2, MAXN);//at each spot should be the # of elements with value of index i

    for(int i = 0; i<m; i++){
        char c;
        cin>>c;
        if(c == 'C'){
            int x, v;
            cin>>x>>v;
            //update the actual arrays
            int beforeval = arr1[x];
            arr1[x] = v;
            arr2[beforeval]--;
            arr2[v]++;

            //update BIT with prefix sums
            int diff = v - sums.vals[x];
            sums.add(x, diff);

            //update BIT with the # of elements at each psoition
            numvals.add(beforeval, -1);
            numvals.add(v, 1);




        }
        else if (c == 'S'){
            int l,r;
            cin>>l>>r;
            cout<<sums.rangeQ(l,r)<<endl;
        }
        else if (c == 'Q'){
            int v;
            cin>>v;
            cout<<numvals.rangeQ(1, v)<<endl;
        }
    }




}
