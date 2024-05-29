#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int getsize(long x){
    int count = 0;
    while(x > 0){
        x = x/10;
        count++;
    }
    return count;
}

long ksuba(long x, long y){
    if(x<10 && y<10){
        return x*y;
    }
    long size = fmax(getsize(x),getsize(y));
    if(size < 10){
        return x*y;
    }
    size = size/2 + size%2;
    long mult = pow(10,size);
    long b = x/mult;
    long a = x - b*mult;
    long d = y/mult;
    long c = y - d*mult;
    long u = ksuba(a,c);
    long v = ksuba(b,d);
    long z = ksuba(a+c,b+d);
    return u + (z-u-v)*mult + (v*(long)pow(10,2*size));
}
void tostring(char res[],long val){
    long rem = 0,len = 0,n= 0;
    n = val;
    while(n != 0){
        n = n/10;
        len++;
    }
    for(int i = 0;i<len;i++){
        rem = val%10;
        val = val/10;
        res[len-(i+1)] = rem+'0';
    }
    res[len] = '\0';
}

int main(){
    char num1[100],num2[100];
    scanf("%s",num1);
    scanf("%s",num2);
    long val1 = atoi(num1);
    long val2 = atoi(num2);
    long final = ksuba(val1,val2);
    char res[200];
    tostring(res,final);
    printf("%s\n",res);

}