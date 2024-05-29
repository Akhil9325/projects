#include<stdio.h>

int func(int arr[],int n,int k,int sum){
    if(n==-1){
        if(sum == k){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        int x = 0;
        int i = 0;
        while(sum + i*arr[n] <= k){
            x += func(arr,n-1,k,sum+i*arr[n]);
            i++;
        }
    return x;
}}

int main(){
     int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    printf("%d",func(arr,n-1,k,0));
}