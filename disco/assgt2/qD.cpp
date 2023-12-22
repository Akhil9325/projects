#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int s,int e,vector<vector<int>> adj){
    int count = 0;
    int n = adj.size();
    vector<bool> vis(n,0);
    vector<int> dist(n,-1);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dist[s] = count;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count = dist[node] + 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                dist[it] = count;
                q.push(it);
            }
        }
    }
    cout<<dist[e]<<endl;
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
    bfs(1,n,adj);
    
}