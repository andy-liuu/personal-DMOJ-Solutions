#include <bits/stdc++.h>
using namespace std;

int main(){

    for (int andy = 0;andy<10;andy++){
         //# of things on spinner
        int n;
        cin>>n;

        //get spinner
        bool spinner[101] = {};
        for (int i = 0; i<n;i++){
            int temp;
            cin>>temp;

            spinner[temp] = true;

        }

        bool second[1000001] = {};

        int scores[5];
        for(int i = 0;i<5;i++){
            cin>>scores[i];
        }

        for(int q = 0;q<=100;q++){

            if (spinner[q]){

                for (int w = 0;w<=100;w++){

                    if (spinner[w]){


                        for (int e = 0;e<=100;e++){


                            if (spinner[e]){

                                second[q*w*e] = true;
                                second[q+w+e] = true;
                                second[q*w+e] = true;
                                second[(q+w)*e] = true;







                            }


                        }




                    }



                }




            }



        }

        //check 5 answers
        for(int q = 0;q<5;q++){
            if (second[scores[q]]){
                cout<<"T";
            }
            else{
                cout<<"F";
            }
        }
        cout<<endl;



    }


}
