#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,twothous,fiveh,hundr;
    twothous=2000; 
    fiveh=500;
    hundr=100;
    cout<<"enter the amount: "<<endl;
        cin>>a;
        if(a/twothous>1){
            cout<<"denominations of 2000 are "<<(a/twothous)<<endl;
        }
        if(((a-(a/twothous*2000))/fiveh)>=1){
            cout<<"denominations of 500 are "<<((a-(a/twothous*2000))/fiveh)<<endl;
        }
        if(((a-(a/twothous*2000))-(((a-(a/twothous*2000))/fiveh*500)))/hundr >= 1){
            cout<<"denomiations of 100 are "<<((a-(a/twothous*2000))-(((a-(a/twothous*2000))/fiveh*500)))/hundr<<endl; 
        }
        else{


            
            cout<<"denominations of 100 are 0"<<endl;
        }
    }
