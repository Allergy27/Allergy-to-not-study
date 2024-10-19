/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.15\zou.cpp
 *@date      2024/03/17 19:37:03
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

void bfs(int x, int y, vector<vector<int>> &qaq, vector<pair<int, int>> ans) {
    //走迷宫
    pair<int, int>t{ x, y };
    ans.push_back(t);
    if(x < 0 || x == qaq.size() || y < 0 || y == qaq[0].size() || qaq[x][y] == 1) {
        ans.pop_back();
        return;
    }
    //如果到终点
    if(x == qaq.size() - 1 && y == qaq[0].size() - 1) {
        for(auto t : ans)cout << t.first << ' ' << t.second << '\n';
        return;
    }
    qaq[x][y] = 1;
    for(auto t : dir)bfs(x + t[0], y + t[1], qaq, ans);
}

void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>>qwq(r);
    vector<pair<int, int>>ans;
    for(int j = 0;j < r;++j)
        for(int i = 0;i < c;++i) {
            char x;cin >> x;
            if(x == '.')qwq[j].emplace_back(0);
            else qwq[j].emplace_back(1);
        }
    bfs(0, 0, qwq, ans);
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}