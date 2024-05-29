/*#include<stdio.h>
#include<gmp.h>

int nones(mpz_t num){
    int count = 0;
    char* binstr = mpz_get_str(NULL,2,num);
    for(int i = 0;binstr[i] != '\0';i++){
        if(binstr[i] == '1'){
            count++;
        }
    }
    return count;
}

int main(){
    mpz_t number;
    mpz_init(number);

    printf("enter number: ");
    gmp_scanf("%Zd",number);
    int x = nones(number);
    printf("the occurences are %d",x);
}
*/