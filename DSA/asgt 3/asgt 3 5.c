#include<stdio.h>

void merge(int arr[],int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];
    for(int i = 0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i = 0;i<n2;i++){
        b[i] = arr[mid+1+i];
    }
    int i = 0,j= 0,k= l;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i<n1){
        arr[k++] = a[i++];
    }
    while(j<n2){
        arr[k++] = b[j++];
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int arr1[n1];
    int arr2[n2];
    int arr[n1+n2];
    for(int i = 0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i = 0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    for(int i = 0;i<n1;i++){
        arr[i] = arr1[i];
    }
    for(int i = n1;i<n1+n2;i++){
        arr[i] = arr2[i-n1];
    }
    mergesort(arr,0,n1+n2-1);
    for(int i = 0;i<n1+n2;i++){
        printf("%d ",arr[i]);
    }    



    
}