/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\g.cpp
 *@date      2024/04/20 18:44:07
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, ans = 0;
    cin >> n >> m;
    vector<string>qwq(n);
    for(auto &x : qwq)cin >> x;
    vector<pair<int, int>>way = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
    vector<vector<int>>qaq(n, vector<int>(m));
    char find[] = { 'C', 'C', 'U', 'T' };
    auto bfs = [&](auto self,int x, int y, int f) {
        if(x<0||x==n||y<0||y==m||qaq[x][y])return;
        if(qwq[x][y] == find[f]) {
            qaq[x][y] = 1;
            if(f == 3)++ans;
            else for(auto [p, q] : way)self(self, x + p, y + q, f + 1);
            qaq[x][y] = 0;
        }

        };
    for(int i = 0;i < n;++i)
        for(int j = 0;j < m;++j)
            if(qwq[i][j] == 'C')
                bfs(bfs,i, j, 0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}