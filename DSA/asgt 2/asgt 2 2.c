#include<stdio.h>

int binsearch(int arr[],int n){
    int s = 1,e = n;
    while(s<e){
        int mid = (s + e)/2;
        if(arr[mid] > arr[mid+1]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return s;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int val = binsearch(arr,n);
    printf("%d",val);
}