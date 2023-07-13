#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r){
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
}

int main(){
   int array[5] = {2,45,23,1,4};
   mergesort(array,0,4);
   for (int i = 0; i < 5; i++)
   {
      cout<<array[i]<<" ";
   }
   


   

}