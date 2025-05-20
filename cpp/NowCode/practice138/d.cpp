// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\practice138\d.cpp
 * @date      2025/05/09 19:58:14
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    auto lcm = [](int a, int b) { return a * b / std::__gcd(a, b); };
    int end = 1;
    for (int i = 1; i <= 16; ++i) end = lcm(end, i);  // 720720

    int n, m;
    std::cin >> n;
    std::vector<std::string> qvq(n);
    std::vector<bool> len(16);
    std::vector<std::vector<int>> find(16);
    for (int i = 0; i < 16; ++i) find[i] = std::vector<int>(i + 1);

    bool flag = false;
    for (auto &x : qvq) {
        std::cin >> x;
        if (flag) continue;
        int p = x.size();
        if (len[p - 1]) {
            int tmp = false;
            for (int i = 0; i < p; ++i) {
                find[p - 1][i] &= (x[i] - '0');
                tmp |= find[p - 1][i];
            }
            flag = !tmp;
            continue;
        }
        len[p - 1] = true;
        for (int i = 0; i < p; ++i) find[p - 1][i] |= (x[i] - '0');
    }
    if (flag) {
        std::cout << -1 << ln;
        return;
    }

    std::vector<int> qwq(end + 1);
    int p = 0;
    for (int i = 0; i < 16; ++i) {
        if (!len[i]) continue;
        p += 1;
        for (int j = 0; j <= i; ++j)
            if (find[i][j] == 1) {
                for (int k = j; k < end; k += i + 1)
                    if (qwq[k] == p - 1) qwq[k] = p;
            }
    }
    int ans = -1, res = 0;
    for (int i = 0; i < 16; ++i)
        if (len[i]) ++res;
    for (int i = 0; i < end; ++i)
        if (qwq[i] == res) {
            ans = i + 1;
            break;
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
