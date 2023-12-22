#include<iostream>
#include<vector>
using namespace std;
bool iscycle(int src,vector<vector<int>>&adj,vector<bool>&vis,int parent){
    vis[src] = true;
    for(auto it:adj[src]){
        if(it != parent){
            if(vis[it]){
                return true;
            }
            if(!vis[it] and iscycle(it,adj,vis,src)){
                return true;
            }
        }
    }
    return false;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle = false;
    vector<bool> vis(n,false);
    for (int  i = 0; i < n; i++)
    {
        if(!vis[i] && iscycle(i,adj,vis,-1)){
            cycle = true;
        }
    }

    cout<<cycle<<endl;
    
    

}