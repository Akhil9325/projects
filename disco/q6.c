#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int s[n],e[n];
    for(int i = 0;i<n;i++){
        scanf("%d %d",&s[i],&e[i]);
    }
    int x,y;
    scanf("%d %d",&x,&y);
    for (int i = 0; i < n; i++)
    {
        if(x >= e[i]){
            if(i == n-1){
                printf("yes");
                break;
            }
            continue;
        }
        else{
            if(y <= s[i]){
                printf("yes");
                break;
            }
            else{
                printf("no");
                break;
            }
        }
    }
    
}