#include <bits/stdc++.h>
#include <iostream>
#include <utility>

using namespace std;
#define pb push_back
#define ll long long
#define fo(a,b) for(auto i=a;i<b;i++)
#define nfo(a,b) for(auto i=a;i>=b;i--)
#define all(x) x.begin(), x.end()
#define sz(q) (ll)(q.size())
#define jfo(a,b) for(auto j=a;j<b;j++)
#define njfo(a,b) for(auto j=a;j>=b;j--)
#define kfo(a,b) for(auto k=a;k<b;k++)
#define nkfo(a,b) for(auto k=a;k>=b;k--)
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vpii vector<pair<ll,ll>>
#define vvpii vector<vector<pair<ll,ll>>>
#define viii vector<vector<vector<ll>>>
#define umii unordered_map<ll,ll>
#define mii map<ll,ll> 
#define umipii unordered_map<ll,pair<ll,ll>>
#define umivi unordered_map<ll,vector<ll>>
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define pii pair<ll,ll> 
const ll mod=1000000007;


void solve() {
    ll n,m;
    cin>>n>>m;
    vii arr(n,vi(m));
    fo(0,n){
        jfo(0,m){
            cin>>arr[i][j];
        }
    }
    
    fo(0,n){
        jfo(0,m){

            ll l=j==0?INT_MIN:arr[i][j-1];
            ll u=i==0?INT_MIN:arr[i-1][j];
            ll r=j==m-1?INT_MIN:arr[i][j+1];
            ll d=i==n-1?INT_MIN:arr[i+1][j];
            if(arr[i][j]>l && arr[i][j]>r && arr[i][j]>u && arr[i][j]>d){
                ll t1=max(l,r);
                ll t2=max(u,d);
                ll val=max(t1,t2);
                arr[i][j]=val;
                //so here what we actually did was to first check whether this cell is the peak one meaning that is it strictly greater than all its neighbouring cells and then we had to decrease the value of that cell until it became equal to the next maximum element so instead of doing that process in a while loop directly identify the next highest element and set the cell to that and move forward.

                // so today i would try to atleast complete 75% of the recursion playlist and then by tommorrow i complete this playlist and move on to the dynamic programming strivers playlist after that i also have to study graph becaue i cannot do its questions
                //also i have to keep on doing random array,string questions as they would make us get to understand new methods likebinary search maximization and sliding window etc.
                
            }
            
        }
    }
    fo(0,n){
        jfo(0,m){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
 
int main(){ 
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0; 
}