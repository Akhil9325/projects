#include<stdio.h>

int linearsearch(int arr[],int n,int val){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == val){
            return 1;
        }
    }
    return -1;
    
}
void selectionsort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    
}
void uni(int arr[],int array[],int n1,int n2,int temp[]){
    printf("the union is: ");
    int k = 0;
    for(int i = 0;i<n1;i++){
        temp[k++] = arr[i];
    }
    for (int i = 0; i < n2; i++)
    {
        if(linearsearch(arr,n1,array[i]) == -1){
            temp[k++] = array[i];
        }
    }
    
}
void intersect(int arr[],int array[],int n1,int n2){
    printf(" the intersection is: ");
    if(n2<n1){
        for (int i = 0; i < n2; i++)
        {
            if(linearsearch(arr,n1,array[i]) == 1){
                printf("%d ",array[i]);
            }
        }
        
    }else{
        for (int i = 0; i < n1; i++)
        {
            if(linearsearch(array,n2,arr[i]) == 1){
                printf("%d ",arr[i]);
            }
        }

    }
}
void diff(int arr[],int array[],int n1,int n2){
    printf(" the diff is ");
    for(int i = 0;i<n1;i++){
        if(linearsearch(array,n2,arr[i]) == -1){
            printf("%d ",arr[i]);
        }
    }
}
int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int arr[n1];
    int array[n2];
    for(int i = 0;i<n1;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i<n2;i++){
        scanf("%d",&array[i]);
    }
    int temp[n1+n2];
    for (int  i = 0; i < n1+n2; i++)
    {
        temp[i] = -1;
    }
    
    uni(arr,array,n1,n2,temp);
    selectionsort(temp,n1+n2);
    for (int  i = 0; i < n1+n2; i++)
    {
        if(temp[i] > 0){
        printf("%d ",temp[i]);
    }}
    
    



}