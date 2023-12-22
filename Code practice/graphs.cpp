#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>

 /*vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;

    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
        
    }*/
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1;i<n+1;i++){
        cout<<i<<"->";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    int vis[n+1] = {0};
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < bfs.size(); i++)
    {
        cout<<bfs[i]<<" ";
    }
    

    
   

}