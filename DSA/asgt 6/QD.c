#include<stdio.h>

void insertion_sort(int arr[],int s,int e){
    for(int i = s+1;i<=e;i++){
        int curr = arr[i];
        int j = i-1;
        while(arr[j] > curr && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

void merge(int arr[],int s,int mid,int e){
    int n1 = mid-s+1;
    int n2 = e-mid;
    int a[n1];
    int b[n2];
    for(int i = 0;i<n1;i++){
        a[i] = arr[s+i];
    }
    for(int i = 0;i<n2;i++){
        b[i] = arr[mid+1+i];
    }
    int i = 0,j = 0,k=s;
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
    while(i<n2){
        arr[k++] = b[j++];
    }
}

void mergesort(int arr[],int s,int e,int k){
    if((e-s+1) <= k){
        insertion_sort(arr,s,e);
    }else{
        int mid = (s+e)/2;
        mergesort(arr,s,mid,k);
        mergesort(arr,mid+1,e,k);
        merge(arr,s,mid,e);
    }
}
int main(){
int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1,k);

    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}