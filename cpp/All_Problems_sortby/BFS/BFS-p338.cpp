// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\p338.cpp
 * @date      2024/11/18 20:35:21
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
    int n, m;
    cin >> n >> m;
    auto bfs = [&]() {  // lambda包装一下，个人习惯
        queue<pair<int, int>> que;
        vector<bool> qwq(2e6 + 5);
        que.push(pair{n, 0});
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            if (x == m) {
                cout << y << ln;
                return;
            }
            if (x <= 0 || x >= 2e6 || qwq[x]) continue;
            qwq[x] = true;  // 标记一下以免重新搜到导致无限循环爆内存
            que.push(pair{x * 16 / 10, y + 1});
            que.push(pair{x + 1, y + 1});
            que.push(pair{x * 6 / 10, y + 1});
        }
    };
    bfs();
}

signed main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
