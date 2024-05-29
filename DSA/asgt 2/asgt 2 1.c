#include<stdio.h>

int binsearch(int arr[],int n,int h){
    int s = 0,e = n-1;
    while(s != e){
        int mid = (s + e )/2;
        if(arr[mid] == h){
            return mid+1;
        }
        else if(arr[mid] > h){
            e = mid - 1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}
int main(){
    int n,h;
    scanf("%d %d",&n,&h);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int idx = binsearch(arr,n,h);
    printf("%d",idx);

}