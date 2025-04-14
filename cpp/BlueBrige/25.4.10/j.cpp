// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\j.cpp
 * @date      2025/04/10 18:24:12
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> qwq(8, std::vector<int>(n + 1));
    std::vector<int> vis(n + 1);

    auto trans = [](int x) { return static_cast<int>(sqrtl(x / 2 + 1)); };
    for (int i = 1; i <= n; ++i) {
        std::cin >> qwq[0][i];
        int tmp = qwq[0][i], cnt = 0;
        while (tmp != 1) {
            qwq[++cnt][i] = trans(tmp);
            tmp = qwq[cnt][i];
        }
        vis[i] = cnt;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (vis[i] != 0) {
            ans += vis[i];
            for (int p = 0; p <= vis[i]; ++p) {
                for (int q = 0; q <= vis[i - 1]; ++q)
                    if (qwq[p][i] > 1 && qwq[p][i] == qwq[q][i - 1]) --ans;
            }
        }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
