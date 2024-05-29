#include<stdio.h>

int binsearch(int arr[],int n,int h){
    int s = 0,e = n-1;
    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid] == h){
            return mid;
        }
        else if(arr[mid] > arr[s]){
            if(arr[mid] > h){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        else{
            if(arr[mid] > h){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n-1];
    for(int i = 0;i<n-1;i++){
        scanf("%d",&arr[i]);
    }
    int val = binsearch(arr,n,7);
    printf("%d",val);
}