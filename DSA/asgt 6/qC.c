#include<stdio.h>
#include<conio.h>
void heapify(int arr[],int f,int e);
void maxheap(int arr[],int s,int e){
    for(int i = e/2;i>=s;i--){
        heapify(arr,i,e);
    }
}
void heapify(int arr[],int f,int e){
    int max = f,l = 2*f,r = 2*f+1;
    if(l<=e && arr[l] > arr[max]){
        max = l;
    }
    if(r<=e && arr[r] > arr[max]){
        max = r;
    }
    if(f != max){
        int temp = arr[f];
        arr[f] = arr[max];
        arr[max] = temp;
        heapify(arr,max,e);
    }
}
void heapsort(int arr[],int size){
    for(int i = size;i>=2;i--){
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapify(arr,1,i-1);

    }
}

int main(){

int n;
scanf("%d",&n);
int arr[n];
for(int i = 1;i<=n;i++){
    scanf("%d",&arr[i]);
}
maxheap(arr,1,n);
heapsort(arr,n);
for(int i = 1;i<=n;i++){
    printf("%d ",arr[i]);
}
}