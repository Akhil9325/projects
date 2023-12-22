#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> b;
    vector<vector<int>> adj(n+1,b);
    vector<int> visit(n+1,0);
    for (int  i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
    for (int  i = 1; i < n+1; i++)
    {
        if(visit[i] == 0){
            ans++;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                visit[node] = 1;
                for (int j = 0; j < adj[node].size(); j++)
                {
                    if(visit[adj[i][j]] == 0){
                        visit[adj[i][j]] = 1;
                        q.push(adj[i][j]);
                    }
                }
                
            }
        }
    }
    cout<<ans<<endl;
    
    
}