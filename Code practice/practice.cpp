#include<bits/stdc++.h>
using namespace std;
/*void merge(int arr[],int l,int mid,int r){
   int i = l;
   int j = mid+1;
   int temp[r-l+1];
   int k = 0;
   while(i<=mid && j<=r){
      if(arr[i] <= arr[j]){
         temp[k] = arr[i];
         i++;
         k++;
      }else{
         temp[k] = arr[j];
         j++;
         k++;
      }
   }
   while(i<=mid){
       temp[k] = arr[i];
         i++;
         k++;
   }
   while(j<=r){
      temp[k] = arr[j];
         j++;
         k++;
   }
   for(int m = 0;m<(r-l+1);m++){
      arr[l+m] = temp[m];
   }
}
void mergesort(int arr[],int l,int r){
   if(l<r){
      int mid = (l+r)/2;
      mergesort(arr,l,mid);
      mergesort(arr,mid+1,r);
      merge(arr,l,mid,r);
   }
}*/
void swap(int arr[],int i,int j){
   int temp = arr[j];
   arr[j] = arr[i];
   arr[i] = temp;
}
int partition(int arr[],int l,int r){
   int pivot = arr[r];
   int i = l-1;
   for(int j = l;j<r;j++){
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

}}
int main(){
   int n;
   cin>>n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin>>arr[i];
   }
   
   quicksort(arr,0,n-1);
   for (int i = 0; i < 5; i++)
   {
      cout<<arr[i]<<" ";
   }
   


   

}