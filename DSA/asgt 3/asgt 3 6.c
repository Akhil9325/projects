#include<stdio.h>

int main(){
    int n,k,x;
    scanf("%d %d %d",&n,&k,&x);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int s = 0,ans = 0,ct=0;
    for(int i = 0;i<k;i++){
        s += arr[i];
    }

    if(s/k >= x){
        ct++;
    }

    for(int i = 1;i<n-k+1;i++){
        s -= arr[i-1];
        s += arr[i+k-1];
        if(s/k >= x){
            ct++;
        }
    }
    printf("%d",ct);
    
}