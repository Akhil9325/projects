#include<stdio.h>

int main(){
    char a[10001],b[10001];
    scanf("%s",a);
    scanf("%s",b);
    char c[20002];
    int i = 0,j = 0,cnt = 0;
    while(a[i] != '\0' || b[j] != '\0'){
        if(a[i] == '\0'){
            i = 0;
            continue;
        }
        else if(b[j] == '\0'){
            j = 0;
            continue;
        }
        else if(a[i] != b[j]){
            printf("-1\n");
            return 0;
        }
        else{
            c[cnt] = a[i];
            i++;
            j++;
            cnt++;
        }
    }
    c[cnt] = '\0';
    printf("%s",c);
}