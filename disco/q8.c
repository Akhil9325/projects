#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    int temp[n];
    int k;
    scanf("%d",&k);
    temp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        temp[i] = temp[i-1] + arr[i];
    }
    int mc = INT_MIN,count = 0;
    for (int i = 0; i < n; i++)
    {
        if(temp[i] < k){
            continue;
        }
        else if(temp[i] == k){
            if(i+1 > mc){
                mc = i+1;
            }
        }
        else{
            int g = 0;
            while(g<i){
                if(temp[i] - temp[g] <= k){
                    if(i-g > mc){
                        mc = i-g;
                    }
                    else{
                        break;
                    }
                }
                g++;
            }
        }
    }
    printf("the max count is %d",mc);
    
    
}