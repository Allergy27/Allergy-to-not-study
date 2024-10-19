/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.2\D.cpp
 *@data      2023/12/02 20:39:37
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
vector<vector<int>> sum;
void MatrixSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
        }
    }
}

// 返回左上角在 (r1,c1) 右下角在 (r2-1,c2-1) 的子矩阵元素和（类似前缀和的左闭右开）
int query(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
}

void solve() {
    int n, m, q,i, j;
    cin >> n>>q;
    
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}