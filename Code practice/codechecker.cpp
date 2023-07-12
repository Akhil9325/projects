#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}
/*the last element as pivot is the worst case scenario
whereas the median element gives the best case scenario in quick sort */ 

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;
    for (int j = l; j < r; j++)
    {
         if(arr[j] < pivot){
               i++;
               swap(arr,i,j);               
         }
    }
    swap(arr,i+1,r);
 return (i+1);
    
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int l = 0;
    int r = n-1;
    quicksort(arr,l,r);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}