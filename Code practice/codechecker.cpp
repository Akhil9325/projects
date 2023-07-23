#include<bits/stdc++.h>
using namespace std;
 void merger(int arr[],int l,int mid,int r){
          int i = l;
          int j = mid+1;
          int k = 0;
          int temper[r-l+1];
          while(i<=mid && j<=r){
            if(arr[i] < arr[j]){
              temper[k] = arr[i];
              k++;
              i++;
            }
            else{
              temper[k] = arr[j];
              j++;
              k++;
            }
          }
          while(i <=mid){
            temper[k] = arr[i];
              k++;
              i++;
          }
          while(j<=r){
            temper[k] = arr[j];
              j++;
              k++;
          }
          for (int m = 0; m < (r-l+1); m++)
          {
              arr[l+m] = temper[m];
          }
          

        }
        void mergesort(int arr[],int l,int r){
          if(l<r){
            int mid = (l+r)/2;
            mergesort(arr,l,mid);
            mergesort(arr,mid+1,r);
            merger(arr,l,mid,r);
          }
        }
int main(){
int n = 9;
int arr[9] = {5,6,7,8,1,2,3,4,5};
    int l = 0;
    int r = 8;
    mergesort(arr,l,r);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}