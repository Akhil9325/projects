#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    int i = 0,j = n-1;
    while(i < j){
        while(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u'){
            i++;
        }
        while(str[j]!='a'&&str[j]!='e'&&str[j]!='i'&&str[j]!='o'&&str[j]!='u'){
            j--;
        }
        char p = str[i];
        str[i] = str[j];
        str[j] = p;
        i++;
        j--;
    }
    printf("%s",str);




    }
