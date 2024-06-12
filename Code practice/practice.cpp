#include<iostream>
using namespace std;
int fibb(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 1;
    }
    return fibb(n-1) + fibb(n-2);
}//here we just analyzed the situation at the top ans it got replicated to the end and we also checked for a base case

int main(){
    
    int ans = fibb(7);
    cout<<ans<<endl;

}