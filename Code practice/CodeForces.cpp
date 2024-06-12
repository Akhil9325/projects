#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool goodch(vector<long long> arr){
    long long total_sum = accumulate(arr.begin(), arr.end(), 0LL);
    for(long long num : arr){
        if(total_sum - num == num){
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<int> ans;

    while (t--)
    {
        int n;
        cin>>n;
        vector<long long> arr = {};
        for(int i = 0;i<n;i++){
            long long temp = 0;
            cin>>temp;
            arr.push_back(temp);
        }
        int tot = 0;
        bool is = false;
        while(arr.size() != 0){
            is = goodch(arr);
            if(is == true){
                ++tot;
            }
            arr.pop_back();
        }
        ans.push_back(tot);
    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}