#include<stdio.h>

int func(int k,int arr[],int carr[],int n){
    if(n == -1){
        int mx = carr[0];
        for(int i = 1;i<k;i++){
            if(carr[i] > mx){
                mx = carr[i];
            }
        }
        return mx;
    }
    
    carr[0] += arr[n];
    int min = func(k,arr,carr,n-1);
    carr[0] -= arr[n];
    for(int i = 1;i<k;i++){
        carr[i] += arr[n];
        int t = func(k,arr,carr,n-1);
        if(t < min){
            min = t;
        }
        carr[i] -= arr[n];
    }
    return min;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int carr[k];
    for(int i = 0;i<k;i++){
        carr[i] =0;
    }
    printf("%d",func(k,arr,carr,n-1));
}