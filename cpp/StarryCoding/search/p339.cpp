// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\p339.cpp
 * @date      2024/11/19 16:49:27
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, k;
    // 读输入
    cin >> n >> m >> k;
    vector<vector<int>> qwq(n, vector<int>(m));
    for (auto &i : qwq)
        for (auto &j : i)
            cin >> j;
    // 标记连通块
    unordered_map<int, int> res;
    int tmp = 2;
    auto dfs = [&](auto self, int i, int j) -> void {
        if (i < 0 || j < 0 || i >= n || j >= m || qwq[i][j] == 1) return;
        if (qwq[i][j] == 0) {
            qwq[i][j] = tmp;
            self(self, i + 1, j);
            self(self, i - 1, j);
            self(self, i, j + 1);
            self(self, i, j - 1);
        }
    };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (qwq[i][j] == 0) {
                dfs(dfs, i, j);
                tmp++;
            }
            if (qwq[i][j] != 1) res[qwq[i][j]]++;
        }
    // 记录答案
    priority_queue<int, std::vector<int>, std::greater<int>> ans;
    for (auto [_, x] : res)
        if (x >= k) ans.push(x);
    // 没有大于等于的输出-1
    if (ans.size() == 0) {
        cout << "-1\n";
    } else {
        while (ans.size()) {
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << ln;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
