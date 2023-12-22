#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0;i<n;i++)
    {
        scanf("%d ",&arr[i]);
    }
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    int mid = (n/2);
    int med = 0;
    while(mid){
        med++;
        mid--;
    }
    printf("the median of array is %d",arr[med]);
    int mode;
    int maxcount = 0;
    for(int i = 0;i<n;i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count > maxcount){
            maxcount = count;
            mode = arr[i];
        }
        
    }
    printf("\nthe mode of array is %d",mode);
    
}