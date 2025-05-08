// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 977 div2\c2.cpp
 * @date      2025/04/18 18:11:54
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct node {
    int s, t, i;
};

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::vector<int> mp(n + 1), op(m);
    for (auto &x : op) std::cin >> x;

    std::vector<node> xp(q);
    for (int i = 0; i < q; ++i) {
        int s, t;
        std::cin >> s >> t;
        xp[i] = {s, t, i};
    }

    sort(xp.begin(), xp.end(), [](node a, node b) {
        if (a.s != b.s) return a.s < b.s;
        return a.i < b.i;
    });
    int l = 0, p = 0;

    std::vector<int> cant(q + 2);

    for (int i = 0; i < m; ++i) {
        while (l < q && i == xp[l].s - 1) {
            if (mp[xp[l].t] == 0 && p < n && qwq[p] != xp[l].t)
                ++cant[xp[l].i + 1];
            else
                --cant[xp[l].i + 1];
            ++l;
        }
        int x = op[i];
        if (mp[x]) continue;  // 出现过
        if (p < n && qwq[p] != x)
            cant[0] = 1;
        else
            ++p;
        ++mp[x];
    }
    int ans = 0;
    for (int i = 1; i <= q + 1; ++i) {
        ans += cant[i - 1];
        if (ans)
            std::cout << "TIDAK" << ln;
        else
            std::cout << "YA" << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
