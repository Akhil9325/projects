#include<bits/stdc++.h>
using namespace std;
bool bfs(int s,int e,vector<vector<int>> adj,int pre[],int dist[]){
    int count = 0;
    int n = adj.size();
    vector<bool> vis(n,0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dist[s] = count;
    pre[s] = -1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count = dist[node] + 1;
        vector<int>:: iterator it;
        for(it = adj[node].begin();it<adj[node].end();it++){
            if(!vis[*it]){
                vis[*it] = 1;
                dist[*it] = count;
                q.push(*it);
                pre[*it] = node;
                if(*it == e){
                    return true;
                }
            }
        }
    }
    return false;
}
void printpath(int s,int e,vector<vector<int>>adj){
    int n = adj.size();
    int pre[n] = {-1};
    int dist[n] = {-1};
    if(bfs(s,e,adj,pre,dist) == false){
        cout<<"no paths"<<endl;
        return ;
    }
    vector<int> path;
    int back = e;
    path.push_back(back);
    while(pre[back] != -1){
        path.push_back(pre[back]);
        back = pre[back];
    }
    cout<<dist[e]+1<<endl;
    for (int i = path.size()-1; i>=0; i--)
    {
        cout<<path[i]<<" ";
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<int> b;
    vector<vector<int>> adj(n+1,b);
    for (int i = 1; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s,e;
    cin>>s>>e;
    printpath(s,e,adj);
    
}