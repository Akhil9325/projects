#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n][n];
    int x = 1;
    int top = 0,bottom = n-1,left = 0,right = n-1;
    while(top<=bottom && left<=right){
        for(int i = left;i<=right;i++){
            arr[top][i] = x++;
        }
        top++;
        for(int i = top;i<=bottom;i++){
            arr[i][right] = x++;
        }
        right--;
        for(int i = right;i>=left;i--){
            arr[bottom][i] = x++;
        }
        bottom--;
        for(int i = bottom;i>=top;i--){
            arr[i][left] = x++;
        }
        left++;
    }
    for(int i= 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}