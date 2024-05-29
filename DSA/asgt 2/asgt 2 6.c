#include<stdio.h>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int array[q][2];
    for(int i = 0;i<q;i++){
        for(int j = 0;j<2;j++){
            scanf("%d",&array[i][j]);
        }
    }
    int x = 0;
    while(x != q){
        int sum  = 0;
        for(int i = array[x][0]-1;i<=array[x][1]-1;i++){
            sum += arr[i];
        }
        printf("%d\n",sum);
        x++;
    }
    
    
}