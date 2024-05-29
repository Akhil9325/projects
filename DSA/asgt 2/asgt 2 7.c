#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int msum = 0;
    for(int i = 0;i<n;i++){
        int sum = arr[i];
        if(sum > msum){
            msum = sum;
        }
        for(int j = i+1;j<n;j++){
            sum += arr[j];
            if(sum > msum){
                msum = sum;
            }
        }
    }
    printf("%d",msum);
}
    