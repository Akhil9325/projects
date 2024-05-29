#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s", str);
    int arr[n];
    int t = 0;
    for(int i = 0;i<n;i++){
        if(str[i] == '_'){
            arr[t++] = i-1;
        }
    }
    arr[t] = n-1;
    int x = 0,p=0;
    t=0;
    for(int i = 0;i<n;i++){
        if(i <= arr[t]-x){
            char p = str[i];
            str[i] = str[arr[t]-x];
            str[arr[t] -x] = p;
            x++;
            }
            else{
                i = arr[t++]+1;
                x = 0;
            }
    }
    printf("%s",str);
}