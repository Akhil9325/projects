#include<iostream>
#include<vector>

using namespace std;
bool compare(vector<int> arr1,vector<int> arr2){
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if(arr1[i] == arr2[j]){
                return false;
            }
        }
        
    }
    return true;
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> b;
    vector<vector<int>> adj(n+1,b);
    for (int  i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 0;j<adj[i].size();j++){
            if(!compare(adj[i],adj[adj[i][j]])){
                cout<<"no"<<endl;
                return 0;
            }
        }
    }
    cout<<"yes"<<endl;
    
}