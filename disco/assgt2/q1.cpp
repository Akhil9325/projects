#include<iostream>
using namespace std;
void sort(int arr[],int i,int n){
    for(int t = i;t<n-1;t++){
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int  i = 0; i < n; i++)
    {
        if(arr[i] < 0 || i+ arr[i] >= n){
            cout<<"no"<<endl;
            return 0;
        }
        else if(arr[i] == 0){
            cout<<"yes"<<endl;
            return 0;
        }
        int x = arr[i];
        for (int j = i+1; j < i+x+1; j++)
        {
            arr[j] = arr[j] - 1;
            if(arr[j] < 0){
                cout<<"no"<<endl;
                return 0;
            }
        }
        sort(arr,i+1,n);
    }
    cout<<"no"<<endl;
    }
