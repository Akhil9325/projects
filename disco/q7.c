#include<stdio.h>


int sumtok(int arr[],int n,int temp[100],int k){
    if(n == 0){
        if(k == 0){
            return 0;
        }
        else{
            return -1;
        }
    }
    int result = sumtok(arr+1,n-1,temp,k-arr[0]);
    if(result >= 0){
        temp[result+1] = arr[0];
        return result+1;
    }
    else{
        return sumtok(arr+1,n-1,temp,k);
    }
}

void findsequence(int arr[],int n,int k){
    int temp[100];
    int result = sumtok(arr,n,temp,k);
    printf("%d\n",result);
    if(result >= 0){
        printf("the subsequences are: ");
        for (int i = result; i>=1; i--)
        {
            printf("%d ",temp[i]);
        }
    }else{
        printf("nothing found");
    }

}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    findsequence(arr,n,k);
    
}