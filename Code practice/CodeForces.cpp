#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void read_matrix(int& n, int& m, vector<vector<int>>& matrix) {
    cin >> n >> m;
    matrix.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void stabilize_matrix(int n, int m, vector<vector<int>>& matrix) {
    while (true) {
        int max_value = numeric_limits<int>::min();
        int max_i = -1, max_j = -1;
        bool found = false;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool is_greater = true;
                if (i > 0 && matrix[i][j] <= matrix[i-1][j]) is_greater = false;
                if (i < n-1 && matrix[i][j] <= matrix[i+1][j]) is_greater = false;
                if (j > 0 && matrix[i][j] <= matrix[i][j-1]) is_greater = false;
                if (j < m-1 && matrix[i][j] <= matrix[i][j+1]) is_greater = false;
                
                if (is_greater) {
                    if (matrix[i][j] > max_value) {
                        max_value = matrix[i][j];
                        max_i = i;
                        max_j = j;
                        found = true;
                    } else if (matrix[i][j] == max_value) {
                        if (i < max_i || (i == max_i && j < max_j)) {
                            max_i = i;
                            max_j = j;
                        }
                    }
                }
            }
        }
        
        if (!found) break;
        
        matrix[max_i][max_j] -= 1;
    }
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (size_t j = 0; j < row.size(); ++j) {
            if (j > 0) cout << " ";
            cout << row[j];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin>>t;
    vector<vector<vector<int>>> ans = {};
    while(t--){
    int n, m;
    vector<vector<int>> matrix;
    read_matrix(n, m, matrix);
    stabilize_matrix(n, m, matrix);
    ans.push_back(matrix);
}
for(int i = 0;i<ans.size();i++){
    print_matrix(ans[i]);
}
}
