#include<bits/stdc++.h>
using namespace std;
int dfs(int vis[],vector<vector<int>> adj,int ans[],int s,int p){
    vis[s] = 1;
    for(auto it:adj[s]){
        if(vis[it] == 0){
            int l = dfs(vis,adj,ans,it,s);
            if(l>=0){
                ans[l] = it;
                return l+1;
            }
        }else if(p != it){
            return 0;
        }
    }
return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> b;
    vector<vector<int>> adj(n+1,b);
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int vis[n+1] = {0};
    int ans[n+1];
    for (int i = 1; i < n+1; i++)
    {
        if(vis[i] == 0){
            int x = dfs(vis,adj,ans,i,-1);
            if(x >= 0){
                for (int i = x-1;i>=0 ;i--)
                {
                    cout<<ans[i]<<" ";
                }
                return 0;
            }
        }
    }
    
    cout<<"-1"<<endl;
}