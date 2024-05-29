#include<stdio.h>
#include<math.h>

int isprime(long long int val){
    int flag = 1;
    for(long long int i = 2;i<=val/2;i++){
        if(val%i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    int n;
    scanf("%d",&n);
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    long long int product = -1;
    for(int i  = 0;i<n;i++){
        int f = 0;

        if(!isprime(arr[i])){
            if(product == -1){
                product = arr[i] % ((long long int)(1000000007));
            }
            else{
                product = (product*(arr[i]%((long long int)(1000000007)))) % ((long long int)(1000000007));
            }
        }
        
    }
    printf("%lld\n",product);
}