#include<stdio.h>


void mulstrigs(char num1[],char num2[],char product[]){
    int len1=0,len2=0;
    while(num1[len1] != '\0' ){
        len1++;
    }
    while(num2[len2] != '\0' ){
        len2++;
    }
    for(int i = 0;i<len1+len2;i++){
        product[i] = '0';
    }
    product[len1+len2] = '\0';
    for(int i = len1-1;i>=0;i--){
        for(int j = len2-1;j>=0;j--){
            int mul = (num1[i] - '0')*(num2[j]-'0');
            int sum = (product[i+j+1]-'0')+mul;
            
            product[i+j] += sum/10;
            product[i+j+1] = (sum%10)+'0';
        }
    }
}
int main(){
    char num1[1001],num2[1001],product[2002];
    printf("enter the first number: ");
    scanf("%s",num1);
    printf("enter the first number: ");
    scanf("%s",num2);
    
    mulstrigs(num1,num2,product);
    int i = 0;
    while(product[i] == '0'){
        i++;
    }
    if(product[i] == '\0'){
        printf("no product\n");
    }else{
        printf("product is %s\n",&product[i]);
    }
    
    
}