#include<iostream>
#include<vector>
using namespace std;
//BINARY SEARCH
/*int binarysearch(int arr[],int key,int n){
  int s = 0;
  int e = n;
  while(s<=e){
    int mid = (s + e)/2;
    if(arr[mid] == key){
      return mid;
    }
    else if(arr[mid] > key){
      e = mid - 1;
    }
    else{
      s = mid + 1;
    }
  }
}*/
//SELECTION SORT
/*void selectionsort(int arr[],int n){
  for (int i = 0; i < n-1;i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if(arr[j] < arr[i]){
         int temp = arr[j];
         arr[j] = arr[i];
         arr[i] = temp;
    }}}}*/
    //BUBBLE SORT
  /*  void bubblesort(int arr[],int n){
  int counter = 1;
  while(counter < n){
  for (int i = 0; i < n - counter; i++)
  {  
    if(arr[i] > arr[i+1]){
      int temp = arr[i+1];
      arr[i+1] = arr[i];
      arr[i] = temp;
  }}
  counter++;}}*/
  //INSERTION SORT
  /*void insertionsort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
      int current = arr[i];
      int j = i-1;
      while(arr[j]>current && j>=0){
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = current;
      }}*/
      //MERGE SORT
    /*void merge(int arr[],int l,int mid,int r){
    int n1 = (mid-l+1);
    int n2 = (r-mid);
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
         arr[k] = a[i];
            k++;
            i++;
    }
    while(j<n2){
        arr[k] = b[j];
            k++;
            j++;
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
*/
//QUICK SORT
/*void swap(int arr[],int i,int j){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}
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
}*/
int main(){
  
  }
 