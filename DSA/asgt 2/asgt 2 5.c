#include <stdio.h>

int binary_search(int n, int arr[][n], int k){
    int beg = 0, end = (n * n - 1);
    while(beg <= end){
        int mid = (beg + end) / 2;
        int row = mid / n;
        int col = mid % n;
        if(arr[row][col] == k)
            return 1;
        else if(arr[row][col] < k)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    if(binary_search(n, arr ,k) == 1)
        printf("YES");
    else
        printf("NO");
}