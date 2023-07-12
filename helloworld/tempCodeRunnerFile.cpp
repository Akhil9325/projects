}
int profit = max - min;
if(profit == 0){
    arr.pop_back();
    int min2 = arr[0];
    I = 0;
 for (int i = 0; i < n-1; i++)
{
  if(arr[i] < min2){
    min2 = arr[i];
    I = i;
  }
}
cout<<min2<<","<<I<<endl;
int max2 = arr[I];
for(int i = I; i < n; i++)
{
    if(arr[i] > max2){
        max2 = arr[i];
    }
}
profit = max2 - min2;
cout<<profit;
    }
    
}