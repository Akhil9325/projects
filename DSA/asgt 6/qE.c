#include<stdio.h>
#include<math.h>
int merge(int arr[],int s,int mid,int e){
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
    int inv = 0;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k++] = a[i++];
        }
        else{
            inv += (mid-(s+i)+1);
            arr[k++] = b[j++];
        }
    }
    while(i<n1){
        arr[k++] = a[i++];
    }
    while(i<n2){
        arr[k++] = b[j++];
    }
    return inv;
}

int mergesort(int arr[],int s,int e){
    if(s < e){
        int mid = (s+e)/2;
       int x =  mergesort(arr,s,mid);
        int y = mergesort(arr,mid+1,e);
        return (merge(arr,s,mid,e) + x + y);
    }else{
        return 0;
    }
}

int main(){
int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans = mergesort(arr,0,n-1);
    printf("%d ",ans);

    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}