#include<stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    int cnt = 0,ans = 0;
    for(int i = 0;i<n;i++){
        int s = i,e = n-1,cnt = 0;
        while(s<=e){
            if(str[s]==str[e] && s!=e){
                cnt += 2;
                s++;
            }
            else if(str[s]==str[e] && s==e){
                cnt += 1;
                s++;
            }
            else{
                cnt = 0;
            }
            e--;
        }
        if(cnt > ans){
            ans = cnt;
        }
    }
    printf("%d",ans);
    
}