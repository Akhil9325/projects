#include<iostream>
#include<vector>
using namespace std;
void rightrotate(vector<int>& arr){
    int n = arr.size();
     int temp[n];
    int k = 0;
    int d;
    cout<<"how much do you want to rotate: "<<endl;
    cin>>d;
    for (int i = n-d; i < n; i++)
    {
        temp[k] = arr[i];
        ++k;
    }
    for (int i = 0; i < n-d; i++)
    {
       temp[k] = arr[i];
       k++;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
    

}
void leftrotate(vector<int>& arr){
    int n = arr.size();
     int temp[n];
    int k = 0;
    int d;
    cout<<"how much do you want to rotate: "<<endl;
    cin>>d;
    for (int i = d; i < n; i++)
    {
        temp[k] = arr[i];
        ++k;
    }
    for (int i = 0; i < d; i++)
    {
       temp[k] = arr[i];
       k++;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
}
int main(){
    vector<int> arr ={1,2,3,4,5,6,7};
    //lets do left rotate on the given arr
    leftrotate(arr);
    cout<<endl;
    //next we right rotate the arr 
    rightrotate(arr);


}
// after arrays we study sub-arrays and sub-sequences and then move on to linked lists which have extensive use of pointers.
//also writing the2 name of people specially me would improve my writing skills but at the same time we have to write without even seeing the keyboead
//I would know the shcehule for the tasks.

