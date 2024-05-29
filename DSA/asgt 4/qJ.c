#include<stdio.h>

int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    char arr[r][c+1];
    for(int i = 0;i<r;i++){
        scanf("%s",arr[i]);
    }
    printf("\n");
    for(int i = 0;i<c;i++){
        int k = 0,s=-1,e=-1;
        while(k<r){
            if(arr[k][i] == '*' && s== -1){
                s = k;
            }
            else if(arr[k][i] == '.' && s != -1){
                arr[k][i] = arr[s][i];
                arr[s][i] = '.';
                e = k;
                s++;
            }
            else if(arr[k][i] == 'o'){
                s = -1;
            }
            k++;
        }
    }
    for(int i = 0;i<r;i++){
        printf("%s\n",arr[i]);
    }
}