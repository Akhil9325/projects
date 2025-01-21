#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canCraftArtifact(int n, vector<long long>& a, vector<long long>& b) {
    // Total current materials
    long long total_a = accumulate(a.begin(), a.end(), 0LL);
    // Total required materials
    long long total_b = accumulate(b.begin(), b.end(), 0LL);
    
    // If we don't have enough total materials, return false
    if (total_a < total_b) return false;

    // Check for each material if we have at least as many as required
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of types of materials

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Current materials
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i]; // Required materials
        }

        if (canCraftArtifact(n, a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
