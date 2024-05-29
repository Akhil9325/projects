#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int x=0,y=n-1,sum1=0,sum2=0;
    while(x<=y){
        if(sum1 < sum2){
            sum1 += arr[x++];
        }
        else if(sum2 < sum1){
            sum2 += arr[y--];
        }
        else{
            ans = sum1;
            sum1 += arr[x++];
            sum2 += arr[y--];
        }
    }
    printf("%d\n",ans);
    
}