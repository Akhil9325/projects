#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool cmp(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}
void makeset(vector<int> &parent,vector<int> &rank,int n){
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    
}
int findparent(vector<int>& parent,int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findparent(parent,parent[node]);
}
void unionset(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findparent(parent,u);
    v = findparent(parent,v);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int spannigtree(vector<pair<int,int>> adj[],int n){
sort(adj->begin(),adj->end(),cmp);
vector<int> parent(n);
vector<int> rank(n);
makeset(parent,rank,n);
int minwt = 0;
for (int i = 0; i < adj->size(); i++)
{
    int u = findparent(parent,i);
    int v = findparent(parent,adj[i);
    int wt = adj[i][2];
    if(u != v){
        minwt += wt;
        unionset(u,v,parent,rank);
    }
}


}
int main(){
int n,m;
cin>>n>>m;
vector<pair<int,int>> adj[n];
for (int i = 0; i < m; i++)
{
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
}




}