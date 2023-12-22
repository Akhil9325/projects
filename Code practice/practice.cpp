#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr;
    vector<int> x;
    arr.push_back({});
    x.push_back(0);
    for(int i = 1; i <= n; i++){
        int y;
        cin >> y;
        x.push_back(y);
        arr.push_back({});
        for(int j = 0; j < y; j++){
            int t;
            cin >> t;
            arr[i].push_back(t);
        }
    }
    vector<int> ans;
    int l = 0;
    do{
        l = ans.size();
        vector<int> p;
        for(int i = 1; i < x.size(); i++){
            if(x[i] == 0)
            {
                x[i] = -1;
                ans.push_back(i);
                p.push_back(i);
            }
        }
        for(int i = 0; i < p.size(); i++){
            for(int j = 1; j <= n; j++){
                for(int t = 0; t < arr[j].size(); t++){
                    if(p[i]==arr[j][t])
                        x[j]--;
                }
            }
        }
    }while(l != ans.size());
    if(ans.size() == n){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
    else
        cout<< "-1"<< endl;
}