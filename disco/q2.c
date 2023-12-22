#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int product = 1;
    int arr[n];
    int i = 2;
    while(n != 1){
        if(n%i == 0){
            product *= i;
        }
        while(n%i == 0 && n>=i){
            n = n/i;
        }
        i = i+(n%i);


    }
    printf("%d\n",product);
    
}