/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\4.10\6.cpp
 *@date      2024/04/10 13:00:17
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
pair<int, int>way[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int solve(vector<vector<char>> &grid) {
    int f = 1, n = grid.size(), m = grid[0].size();
    pair<int, int> way[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    vector<vector<int>> qwq(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            qwq[i][j] = grid[i - 1][j - 1] ^ 48;
    }
    auto bfs = [&](auto self, int x, int y, int sgn) -> int {
        if(0 < x && x < n - 1 && 0 < y && y < m - 1 && qwq[x][y] == 1) {
            qwq[x][y] = sgn;
            for(auto [p, q] : way)
                self(self, x + p, y + q, sgn);
        }
        return 0;
        };
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(grid[i][j] && !qwq[i][j])
                bfs(bfs, i, j, ++f);
        }
    return f - 1;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> qwq(n, vector<char>(m));
    for(int i = 0;i < n;++i) {
        string str;
        cin >> str;
        for(int j = 0;j < m;++j)qwq[i][j] = str[j];
    }
    while(t--)solve(qwq);
    cin >> t;
    return 0;
}