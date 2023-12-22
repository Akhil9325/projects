#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int component(vector<vector<int>> adj){
    int count = 0;
    int n = adj.size();
    vector<bool> vis(n,0);
    queue<int> q;
    for(int i = 1;i<n;i++){
        if(!vis[i]){
            q.push(i);
            count++;
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }
    return count;
    
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
    cout<<component(adj);
}