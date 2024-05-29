#include<stdio.h>

int func(int arr1[],int arr2[],int n,int sum,int k){
    if(n == -1){
        return sum;
    }
    else if(k - arr2[n] < 0){
        return func(arr1,arr2,n-1,sum,k);
    }
    else{
        int x = func(arr1,arr2,n-1,sum+arr1[n],k-arr2[n]);
        int y = func(arr1,arr2,n-1,sum,k);
        if(x>y){
            return x;
        }
        else{
            return y;
        }
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr1[n],arr2[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for(int j = 0; j < n; j++)
        scanf("%d", &arr2[j]);
    printf("%d",func(arr1,arr2,n-1,0,k));
}