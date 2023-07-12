#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m){
      unordered_set<int> string;
      for (int i = 0; i < n; i++)
      {
         string.insert(a[i]);
      }
      for (int i = 0; i < m; i++)
      {
         string.insert(b[i]);
      }
      return string.size();
    }
};
int main(){
    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
}