#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
        for(int i = 0;i<n;i++){
            if(max%arr[i] == 0){
            }else{
                max++;
                i = 0;
            }
        }
        printf("the LCM is %d",max);
    
}