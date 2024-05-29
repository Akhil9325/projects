#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = -1;
    }
    /*
    int len = 0;
    int maxlen =0;
    for(int i = 0;i<n;i++){
        int val = str[i]-'a';
        if(arr[val] >= len){
            len++;
            arr[val]++;
        }
        else{
            if(len > maxlen){
                maxlen = len;
            }
            len = 0;
            

        }
    }
    printf("%d\n",maxlen);
    */
   int len = 0,mlen = 0;
   for(int i = 0;i<n;i++){
    int val = (str[i] - 'a');
    if(arr[val] >= len){
        len = arr[val]+1;
    }
    arr[val] = i;
    if((i-len+1) > mlen){
        mlen = i-len+1;
    }
   }
   printf("%d",mlen);
}