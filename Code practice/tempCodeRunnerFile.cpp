#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //this is the way to speed up the process of input and output in the cpp codes
    //but the time limit exceeded problems won't get solved away only with this as you would need a better optimized algorithm
    long long int t;
    cin >> t;
    vector<long long int> ans;

    while (t--)
    {
        long long int n,a,b;
        cin>>n>>a>>b;
        long long int k = 0;
        long long int maxi = 0;
        long long int sum = 0;
        while(k <= min(n,b)){
            for(long long int i = 1;i<=k;i++){
                sum += (b-i+1);
            }
            for(long long int i = 1;i<=n-k;i++){
                sum += a;
            }
            maxi = max(maxi,sum);
            sum = 0;
            ++k;
        }
        ans.push_back(maxi);
    }

    for(long long int i = 0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}