#include<stdio.h>

int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    char str[n+1];
    int i = a/(b+1);
    int j = a%(b+1);
    int k = 0;
    while(k<n){
        int x = 0;
        while(x<i){
            str[k++] = 'K';
            if(k>=n){
                break;
            }
            x++;
        }
        if(j>0){
            str[k++] = 'K';
            j--;
        }
        if(k<n){
            str[k] = 'O';
            k++;
        }
    }
    str[k] = '\0';
    printf("%s",str);

}