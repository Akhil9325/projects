#include<stdio.h>

int main(){
    char num1[1000],num2[1000],num3[1001];
    scanf("%s",num1);
    scanf("%s",num2);
    int carry = 0;
    /*strings always have \0 at the end so it can be used*/
    int len1 = 0,len2 = 0;
    while(num1[len1] != '\0'){
        len1++;
    }
    while (num2[len2] != '\0')
    {
        len2++;
    }
    int fidx = len1-1;
    int sidx = len2-1;
    int sumidx = 0;
    while(fidx>=0 && sidx>=0){
        int dig1 = num1[fidx--]-'0';
        int dig2 = num2[sidx--]-'0';
        int sum = dig1+dig2+carry;
        num3[sumidx++]= (sum % 10) + '0';
        carry = sum/10;
    }
    
    while(fidx>=0){
        int dig1 = num1[fidx--]-'0';
        int sum = dig1+carry;
        num3[sumidx++]= (sum % 10) + '0';
        carry = sum/10;
    }
    if(carry != 0){
        num3[sumidx++] = carry + '0';
    }
    for(int i = sumidx-1;i>=0;i--){
        printf("%c",num3[i]);
    }
}